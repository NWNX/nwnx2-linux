//
// voltster-client.cpp - An NWNX Vaultster compatible receiver
// ~~~~~~~~~~~~~~~~~~~~~~~~~
// Copyright (c) 2009 John Klar ( plasmajohn at avlis dot org )
//
// Adapted from async_tcp_echo_server.cpp which is
// Copyright (c) 2003-2007 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <zlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#include "client.h"
#include "constants.h"

using namespace std;
using namespace boost::asio;
using boost::asio::ip::tcp;

const int timeout_sec = 5;

client::client(io_service& io_service,
               const string& player,
               const string& charname,
               const char*   server,
               const char*   port,
               const string& key,
               const string& password,
               const string& vaultpath,
               int debug,
               CNWNXBase *logger,
               request *req)
    :	resolver_(io_service),
        socket_(io_service),
        timer_(io_service),
        server_(server),
        port_(port),
        key_(key),
        pass_(password),
        vaultpath_(vaultpath),
        debug_(debug),
        logger_(logger),
        req_(req)
{
    strncpy(playerid_, player.c_str(), 128);
    strncpy(bicname_, charname.c_str(), 32);
    cmpdata_ = 0;
    srand((unsigned int) time(NULL));
}

client::~client()
{
    delete[] cmpdata_;
}

/*
  tcp::socket& socket()
  {
    return socket_;
  }
*/

void
client::start()
{
    fish.Initialize((unsigned char*)key_.c_str(), key_.length());

    logger_->Log(LOG_DEBUG, "DEBUG:\t* connect to %s:%s\n", server_.c_str(), port_.c_str());

    // Start an asynchronous resolve to translate the server and service names
    // into a list of endpoints.
    tcp::resolver::query query(tcp::v4(), server_, port_);
    resolver_.async_resolve(query,
                            boost::bind(&client::handle_resolve, this,
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::iterator));

}

void
client::handle_resolve(const boost::system::error_code& err,
                       tcp::resolver::iterator endpoint_iterator)
{
    if (!err) {
        // Attempt a connection to the first endpoint in the list. Each endpoint
        // will be tried until we successfully establish a connection.
        tcp::endpoint endpoint = *endpoint_iterator;
        socket_.async_connect(endpoint,
                              boost::bind(&client::handle_connect, this,
                                          boost::asio::placeholders::error, ++endpoint_iterator));
    } else {
        logger_->Log(LOG_ERR, "FAIL:\tresolve() %s\n", err.message().c_str());
        delete this;
        return;
    }
}

void
client::handle_connect(const boost::system::error_code& err,
                       tcp::resolver::iterator endpoint_iterator)
{
    if (!err) {
        // The connection was successful. Send the request.

        state_ = HNDL_SEND_CMD;
        send_word(CMD_SEND);

    } else if (endpoint_iterator != tcp::resolver::iterator()) {
        // The connection failed. Try the next endpoint in the list.
        socket_.close();
        tcp::endpoint endpoint = *endpoint_iterator;
        socket_.async_connect(endpoint,
                              boost::bind(&client::handle_connect, this,
                                          boost::asio::placeholders::error, ++endpoint_iterator));
    } else {
        logger_->Log(LOG_ERR, "FAIL:\tconnect %s\n", err.message().c_str());
        delete this;
        return;
    }
}

void
client::handle_state(const boost::system::error_code& error,
                     size_t bytes_transferred)
{
    int word;
    int status = STATUS_ERROR;

    if (error) {
        delete this;
        return;
    }

    logger_->Log(LOG_DEBUG, "DEBUG:\t* state=%d\n", state_);

    if (state_ == DONE) {
        // we're done
        delete this;
        return;
    }

    switch (state_) {
        case HNDL_SEND_CMD:
            // get ack/nack
            recv(4);
            break;
        case HNDL_RECV_ACK_CMD:
            word = *((int *)data_);
            if (word == INFO_NACK) {
                logger_->Log(LOG_ERR, "FAIL:\tCMD_SEND NACK'd\n");
                state_ = DONE;
                break;
            }
            // Generate nonce
            for (int i = 0; i < 128; i++)
                buf_[i] = 33 + (int)(89.0 * (rand() / (RAND_MAX + 1.0)));
            strncpy(buf_, pass_.c_str(), pass_.length());

            logger_->Log(LOG_DEBUG, "DEBUG:\t* Password buf = '%s'\n", buf_);

            fish.Encode((unsigned char *)buf_, (unsigned char *)data_, 128);
            send(128);

            break;
        case HNDL_SEND_ENC_PWD:
            // get ack/nack
            recv(4);
            break;
        case HNDL_RECV_ACK_PWD:
            word = *((int *)data_);
            if (word == INFO_NACK) {
                logger_->Log(LOG_ERR, "FAIL:\tPassword NACK'd\n");
                state_ = DONE;
                break;
            }
            len_ = strlen(playerid_);
            fishlen_ = fish.GetOutputLength(len_);
            send_word(fishlen_);

            break;
        case HNDL_SEND_ENC_PIDLEN:
            fish.Encode((unsigned char *)playerid_, (unsigned char *)data_, len_);
            send(fishlen_);
            break;
        case HNDL_SEND_ENC_PID:
            len_ = strlen(bicname_);
            fishlen_ = fish.GetOutputLength(len_);
            send_word(fishlen_);
            break;
        case HNDL_SEND_ENC_BICNAMELEN:
            fish.Encode((unsigned char *)bicname_, (unsigned char *)data_, len_);
            send(fishlen_);
            break;
        case HNDL_SEND_ENC_BICNAME:
            // get ack/nack
            recv(4);
            break;
        case HNDL_RECV_REDUNDANT_ACK_CMD:
            word = *((int *)data_);
            if (word == INFO_NACK) {
                logger_->Log(LOG_ERR, "CRIT:\tRedundant CMD check NACK'd (shouldn't have)\n");
                state_ = DONE;
                break;
            }
            // send filesize (as set up in prepfile)
            send_word(size_);
            break;
        case HNDL_SEND_FILESIZE: // uncompressed filesize
            chunkpos_ = 0;
            // send compressed filesize (as set up in prepfile)
            send_word(cmpsize_);
            break;
            /*
                case HNDL_SEND_CMPFSIZE: // compressed filesize

            	len_ = cmpsize_-chunkpos_;
            	if(len_ > max_length)
            		len_ = max_length;

            	// send chunksize
            	send_word(len_);
            	break;
            */
        case HNDL_CHUNK:

            len_ = cmpsize_ - chunkpos_;
            if (len_ > max_length)
                len_ = max_length;

            // send chunk
            sendbuf(cmpdata_ + chunkpos_, len_);

            chunkpos_ += max_length;

            /*
            	if(chunkpos_<cmpsize_) {
            		state_ = HNDL_SEND_CMPFSIZE;
            	} else {
            		state_ = HNDL_LAST_CHUNK;
            	}
            */
            if (chunkpos_ >= cmpsize_)
                state_ = HNDL_LAST_CHUNK;
            break;

        case HNDL_LAST_CHUNK:
            // get file status
            state_ = HNDL_FILE_STATUS;
            recv(4);
            break;

        case HNDL_FILE_STATUS:
            word = *((int *)data_);
            if (word == 0) {
                logger_->Log(LOG_ERR, "FAIL:\tSend failed\n");
            } else {
                logger_->Log(LOG_NOTICE, "NOTICE:\tSend succeeded\n");
                status = STATUS_OK;
            }
            state_ = DONE;
            break;
    }

    if (state_ < HNDL_CHUNK)
        ++state_;

    if (state_ == DONE) {
        logger_->Log(LOG_DEBUG, "DEBUG:\tDONE status=%d\n", status);
        req_->status = status;
        req_->s_time = time(NULL);
        delete this;
    }
}

void
client::handle_timeout(const boost::system::error_code& error)
{
    if (!error) {
        // bail
        socket_.close();
        // log
        logger_->Log(LOG_ERR, "FAIL:\tTimed out. state=%d\n", state_);

        state_ = DONE;
    }
}

void
client::send_word(int word)
{
    *((int *)data_) = word;
    send(4);
}

void
client::send(int length)
{
    async_write(socket_,
                buffer(data_, length),
                boost::bind(&client::handle_state, this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
    timer_.expires_from_now(boost::posix_time::seconds(timeout_sec));
    timer_.async_wait(boost::bind(&client::handle_timeout, this,
                                  boost::asio::placeholders::error));
}

void
client::sendbuf(unsigned char *buf, int length)
{
    async_write(socket_,
                buffer(buf, length),
                boost::bind(&client::handle_state, this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
    timer_.expires_from_now(boost::posix_time::seconds(timeout_sec));
    timer_.async_wait(boost::bind(&client::handle_timeout, this,
                                  boost::asio::placeholders::error));
}

void
client::recv(int length)
{
    async_read(socket_,
               buffer(data_, length),
               boost::bind(&client::handle_state, this,
                           boost::asio::placeholders::error,
                           boost::asio::placeholders::bytes_transferred));
    timer_.expires_from_now(boost::posix_time::seconds(timeout_sec));
    timer_.async_wait(boost::bind(&client::handle_timeout, this,
                                  boost::asio::placeholders::error));
}

void
client::recvbuf(unsigned char *buf, int length)
{
    async_read(socket_,
               buffer(buf, length),
               boost::bind(&client::handle_state, this,
                           boost::asio::placeholders::error,
                           boost::asio::placeholders::bytes_transferred));
    timer_.expires_from_now(boost::posix_time::seconds(timeout_sec));
    timer_.async_wait(boost::bind(&client::handle_timeout, this,
                                  boost::asio::placeholders::error));
}

bool
client::prepfile()
{
    stringstream oss;
    oss << vaultpath_ << "/" << playerid_;
    string dir = oss.str();

    // find bic file
    DIR *d = opendir(dir.c_str());
    if (d == NULL) {
        logger_->Log(LOG_ERR, "FAIL:\tUnable to open directory '%s'.\n\tError: %s\n",
                     dir.c_str(), strerror(errno));
        return false;
    }

    struct stat sbuf;
    struct dirent *dbuf;
    size_t len = strlen(bicname_);
    time_t hitime = 0;
    string fpath;

    if (len > 15) len = 15;

    for (dbuf = readdir(d); dbuf != NULL; dbuf = readdir(d)) {
        if (strncmp(bicname_, dbuf->d_name, len) == 0) {
            size_t dlen = strlen(dbuf->d_name);
            if (dlen != len + 4 && dlen != len + 5)
                continue;

            if (strncmp(".bic", &(dbuf->d_name[dlen - 4]), 4) != 0)
                continue;

            stringstream pss;
            pss << dir << "/" << dbuf->d_name;

            int status = stat(pss.str().c_str(), &sbuf);

            if (status) {
                if (debug_ >= LOG_WARNING)
                    cout << "WARN:\tstat() error: " << strerror(errno) << endl;
                logger_->Log(LOG_WARNING, "WARN:\tstat() error: %s\n",
                             strerror(errno));
                continue;
            }

            if (!S_ISREG(sbuf.st_mode))
                continue;

            logger_->Log(LOG_DEBUG, "DEBUG:\t* potential=%s\n", dbuf->d_name);

            if (sbuf.st_mtime > hitime) {
                fpath = pss.str();
                hitime = sbuf.st_mtime;
            }
        }
    }

    closedir(d);

    if (hitime == 0) {
        logger_->Log(LOG_ERR, "FAIL:\tUnable to find a suitable match for %s/%s\n",
                     playerid_, bicname_);
        return false;
    } else {
        logger_->Log(LOG_INFO, "INFO:\tSending %s\n", fpath.c_str());
    }

    FILE *fbic = fopen(fpath.c_str(), "rb");
    if (fbic == NULL) {
        logger_->Log(LOG_ERR, "FAIL:\tUnable to open '%s'.\n\tError: %s\n",
                     fpath.c_str(), strerror(errno));
        return false;
    }

    // get length
    fseek(fbic, 0, SEEK_END);
    size_ = ftell(fbic);
    fseek(fbic, 0, SEEK_SET);

    // inhale bic
    unsigned char *bicdata = new unsigned char[size_];
    fread(bicdata, 1, size_, fbic);
    fclose(fbic);

    // compress
    cmpsize_ = int(size_ * 1.2f) + 12;
    cmpdata_ = new unsigned char[cmpsize_];
    int res = compress2(cmpdata_, &cmpsize_, bicdata, size_, Z_DEFAULT_COMPRESSION);
    delete[] bicdata;

    if (res != Z_OK) {
        logger_->Log(LOG_ERR, "FAIL:\tCompression failed.\n");
        return false;
    }

    return true;
}

