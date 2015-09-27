//
// vaultster-serv.cpp - An NWNX Vaultster compatible receiver
// ~~~~~~~~~~~~~~~~~~~~~~~~~
// Copyright (c) 2009 John Klar ( plasmajohn at avlis dot org )
//
// Adapted from async_tcp_echo_server.cpp which is
// Copyright (c) 2003-2007 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/foreach.hpp>

#include <zlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <netdb.h>

#include "vaultster-config.h"
#include "constants.h"
#include "blowfish.h"

using namespace std;
using namespace boost::asio;
using boost::asio::ip::tcp;

const int timeout_sec = 5;

class session
{
public:
    session(io_service& io_service, config *c)
        : socket_(io_service), timer_(io_service), c_(c), debug_(c->debug) {
        cmpdata_ = NULL;
        expdata_ = NULL;
    }

    ~session() {
        delete [] cmpdata_;
        delete [] expdata_;
    }

    tcp::socket& socket() {
        return socket_;
    }

    void start() {
        fish.Initialize((unsigned char*)c_->key.c_str(), c_->key.length());
        state_ = HNDL_RECV_CMD;
        recv(4);
    }

    void handle_state(const boost::system::error_code& error,
                      size_t bytes_transferred) {
        int word;

        if (error) {
            delete this;
            return;
        }


        if (debug_ >= LOG_DEBUG)
            cout << "DEBUG:\t* state=" << state_ << endl;

        if (state_ == DONE) {
            // we're done
            delete this;
            return;
        }

        switch (state_) {
            case HNDL_RECV_CMD:
                // if verify_client && !valid_client
                // 	send_nack("invalid client");
                // else
                // if cmd != CMD_SEND
                //	send_nack("bad command");
                // else
                // 	send_ack();
                word = *((int *)data_);


                if ((c_->validate && !verify())) {
                    send_word(INFO_NACK);
                    state_ = DONE;
                } else if (word != CMD_SEND) {
                    if (debug_ >= LOG_ERR)
                        cout << "FAIL:\tbad command received (" << word << ")" << endl;
                    send_word(INFO_NACK);
                    state_ = DONE;
                } else {
                    send_word(INFO_ACK);
                }
                break;
            case HNDL_SEND_ACK_CMD:
                // recv(encpass,128);
                recv(128);
                break;
            case HNDL_RECV_ENC_PWD:
                // decrypt password/compare password
                // if not match
                //	send_nack("bad password");
                // else
                //	send_ack();
                fish.Decode((unsigned char *)data_, (unsigned char *)buf_, 128);
                buf_[ c_->password.length() ] = 0;
                if (c_->password.compare(buf_) == 0)
                    send_word(INFO_ACK);
                else {
                    if (debug_ >= LOG_ERR)
                        cout << "FAIL:\tBad password.  Expected '" << c_->password << "' got '" << buf_ << "'" << endl;
                    send_word(INFO_NACK);
                    state_ = DONE;
                }
                break;
            case HNDL_SEND_ACK_PWD:
                // recv(pidlen,4);
                recv(4);
                break;
            case HNDL_RECV_ENC_PIDLEN:
                // recv(pid,pidlen);
                word = *((int *)data_);
                recv(word);
                break;
            case HNDL_RECV_ENC_PID:
                // recv(charfnlen,4);
                memset(playerid_, 0, 128);
                fish.Decode((unsigned char *)data_, (unsigned char *)playerid_, bytes_transferred);
                // cout << "Player id=" << playerid_ << endl;
                recv(4);
                break;
            case HNDL_RECV_ENC_BICNAMELEN:
                // recv(charfn,charfnlen);
                word = *((int *)data_);
                recv(word);
                break;
            case HNDL_RECV_ENC_BICNAME:
                // // reudundant since we've NACK'd everything but CMD_SEND above
                // send_ack();
                memset(bicname_, 0, 32);
                fish.Decode((unsigned char *)data_, (unsigned char *)bicname_, bytes_transferred);
                // cout << "Bic name=" << bicname_ << endl;

                if (strchr(bicname_, '/') != NULL || strchr(playerid_, '/') != NULL) {
                    if (debug_ >= LOG_CRIT)
                        cout << "CRIT:\tPath separator found in playerid or bicname, transfer terminated." << endl;
                    send_word(INFO_NACK);
                    state_ = DONE;
                } else {
                    send_word(INFO_ACK);
                }
                break;
            case HNDL_SEND_REDUNDANT_ACK_CMD:
                // recv(fsize,4);
                recv(4);
                break;
            case HNDL_RECV_FILESIZE: // uncompressed filesize
                // recv(cmpfsize,4);
                size_ = *((int *)data_);
                // cout << "Uncompressed size=" << size_ << endl;
                recv(4);
                break;
            case HNDL_RECV_CMPFSIZE: // compressed filesize
                cmpsize_ = *((int *)data_);
                // cout << "Compressed size=" << cmpsize_ << endl;

                // allocate buffer of cmpfsize
                // bufpos=0
                // status=-1
                // recv(chunk,min(BUF_SIZE,bytesleft));

                if (debug_ >= LOG_INFO)
                    cout	<< "INFO:\t("
                            << playerid_ << ","
                            << bicname_ << ","
                            << size_ << ","
                            << cmpsize_ << ")" << endl;

                cmpdata_ = new unsigned char[cmpsize_];
                recvbuf(cmpdata_, cmpsize_);
                break;
            case HNDL_CHUNK:
                // copy chunk,recvdbytes to buf+bufpos
                // bufpos+=recvdbytes
                // if(bufpos<cmpfsize)
                // 	status=uncompress(...)
                //	send(status,4)
                // else
                // 	recv(chunk,min(BUF_SIZE,bytesleft));

                state_ = DONE;

                expdata_ = new unsigned char[size_];
                int status = uncompress(expdata_, (unsigned long *)&size_, cmpdata_, (unsigned long)cmpsize_);
                if (status != Z_OK) {
                    if (debug_ >= LOG_ERR)
                        cout << "FAIL:\tdecompression failed. status=" << status << endl;
                    send_word(0);
                    break;
                }

                if (bytes_transferred == cmpsize_) {
                    if (!prepvault()) {
                        send_word(0);
                        break;
                    }

                    if (debug_ >= LOG_DEBUG)
                        cout << "DEBUG:\t* Will write to '" << bicpath_ << "'" << endl;

                    int fd = open(bicpath_.c_str(), O_RDWR | O_CREAT | O_TRUNC, 0644);
                    if (fd < 0) {
                        if (debug_ >= LOG_ERR)
                            cout << "FAIL:\tError opening '" << bicpath_ << "' : " << strerror(errno) << endl;
                        send_word(0);
                        break;
                    }

                    // casts needed to force selection of write(2)
                    int status = write(fd, (const void *)expdata_, (size_t)size_);
                    if (status < 0) {
                        if (debug_ >= LOG_ERR)
                            cout << "FAIL:\tError writing '" << bicpath_ << "' : " << strerror(errno) << endl;
                        send_word(0);
                        break;
                    }

                    // flush to physical storage
                    status = fsync(fd);
                    if (status < 0) {
                        if (debug_ >= LOG_ERR)
                            cout << "FAIL:\tError syncing '" << bicpath_ << "' : " << strerror(errno) << endl;
                        send_word(0);
                        break;
                    }

                    status = close(fd);
                    if (status < 0) {
                        if (debug_ >= LOG_ERR)
                            cout << "FAIL:\tError closing '" << bicpath_ << "' : " << strerror(errno) << endl;
                        send_word(0);
                        break;
                    }

                    if (debug_ >= LOG_NOTICE)
                        cout << "NOTICE:\tSuccess: " << bicpath_ << endl;


                    send_word(1);
                } else {
                    send_word(0);
                }

                break;
        }

        if (state_ < HNDL_CHUNK)
            ++state_;

    }

    void handle_timeout(const boost::system::error_code& error) {
        if (!error) {
            // bail
            socket_.close();
            // log
            if (debug_ >= LOG_ERR)
                cout << "FAIL:\tTimed out. state=" << state_ << endl;
            state_ = DONE;
        }
    }

    void send_word(int word) {
        *((int *)data_) = word;
        send(4);
    }

    void send(int length) {
        async_write(socket_,
                    buffer(data_, length),
                    boost::bind(&session::handle_state, this,
                                boost::asio::placeholders::error,
                                boost::asio::placeholders::bytes_transferred));
        timer_.expires_from_now(boost::posix_time::seconds(10));
        timer_.async_wait(boost::bind(&session::handle_timeout, this,
                                      boost::asio::placeholders::error));
    }

    void recv(int length) {
        async_read(socket_,
                   buffer(data_, length),
                   boost::bind(&session::handle_state, this,
                               boost::asio::placeholders::error,
                               boost::asio::placeholders::bytes_transferred));
        timer_.expires_from_now(boost::posix_time::seconds(10));
        timer_.async_wait(boost::bind(&session::handle_timeout, this,
                                      boost::asio::placeholders::error));
    }

    void recvbuf(unsigned char *buf, int length) {
        async_read(socket_,
                   buffer(buf, length),
                   boost::bind(&session::handle_state, this,
                               boost::asio::placeholders::error,
                               boost::asio::placeholders::bytes_transferred));
        timer_.expires_from_now(boost::posix_time::seconds(10));
        timer_.async_wait(boost::bind(&session::handle_timeout, this,
                                      boost::asio::placeholders::error));
    }

    bool prepvault() {
        struct stat buf;
        stringstream oss;
        string path;

        oss << c_->path << "/" << playerid_;
        path = oss.str();

        // does servervaultpath/playerid exist?
        int status = stat(path.c_str(), &buf);
        if (status && errno == ENOENT) {
            // create it
            status = mkdir(path.c_str(), 0755);
            if (status == 0)
                // make sure it's really there
                status = stat(path.c_str(), &buf);
        }
        // check errors
        if (status) {
            if (debug_ >= LOG_ERR)
                cout << "FAIL:\tInvalid path: " << path << " Error: " << strerror(errno) << endl;
            return false;
        }
        // make sure it's a directory
        if ((buf.st_mode & S_IFDIR) == 0) {
            if (debug_ >= LOG_ERR)
                cout << "FAIL:\t" << path << " is not a directory." << endl;
            return false;
        }

        // add the bicname
        oss << "/" << bicname_ << ".bic";

        bicpath_ = oss.str();

        return true;
    }

    bool verify() {
        string addr = socket_.remote_endpoint().address().to_string();
        if (debug_ >= LOG_NOTICE)
            cout << "NOTICE:\tReceived connection from: '" << addr << "'" << endl;

        BOOST_FOREACH(string s, c_->servers) {
            hostent* host = gethostbyname(s.c_str());
            if (host) {
                struct in_addr *address = (struct in_addr *) host->h_addr;
                string server_addr = inet_ntoa(*address);
                if (debug_ >= LOG_DEBUG)
                    cout << "DEBUG:\t* " << s << " --> '" << server_addr << "'" << endl;

                if (addr == server_addr)
                    return true;
            } else {
                if (debug_ >= LOG_NOTICE)
                    cout << "NOTICE:\tCould not get IP for '" << s << "' Error: " << hstrerror(h_errno) << endl;
            }
        }

        if (debug_ >= LOG_CRIT)
            cout << "CRIT:\t" << addr << " is not an approved sender." << endl;
        return false;
    }

private:
    tcp::socket socket_;
    deadline_timer timer_;

    enum { max_length = 1024 };

    enum { HNDL_RECV_CMD = 0, HNDL_SEND_ACK_CMD, HNDL_RECV_ENC_PWD, HNDL_SEND_ACK_PWD,
           HNDL_RECV_ENC_PIDLEN, HNDL_RECV_ENC_PID, HNDL_RECV_ENC_BICNAMELEN,
           HNDL_RECV_ENC_BICNAME, HNDL_SEND_REDUNDANT_ACK_CMD, HNDL_RECV_FILESIZE,
           HNDL_RECV_CMPFSIZE, HNDL_CHUNK,
           DONE
         };

    enum { LOG_EMERG = 0, LOG_ALERT, LOG_CRIT, LOG_ERR, LOG_WARNING, LOG_NOTICE, LOG_INFO, LOG_DEBUG };

    config *c_;
    char data_[max_length];
    char buf_[max_length];
    char playerid_[128];
    char bicname_[32];
    string bicpath_;
    unsigned char *cmpdata_;
    unsigned char *expdata_;
    int state_, size_, cmpsize_, debug_;
    CBlowFish fish;
};

class server
{
public:
    server(io_service& io_service, config *c)
        : io_service_(io_service), c_(c),
          acceptor_(io_service, tcp::endpoint(tcp::v4(), c->port)) {
        session* new_session = new session(io_service_, c);
        acceptor_.async_accept(new_session->socket(),
                               boost::bind(&server::handle_accept, this, new_session,
                                           boost::asio::placeholders::error));
    }

    void handle_accept(session* new_session,
                       const boost::system::error_code& error) {
        if (!error) {
            // start processing the currently handled request
            new_session->start();

            // set up for the next request
            new_session = new session(io_service_, c_);
            acceptor_.async_accept(new_session->socket(),
                                   boost::bind(&server::handle_accept, this, new_session,
                                               boost::asio::placeholders::error));
        } else {
            delete new_session;
        }
    }

private:
    io_service& io_service_;
    config* c_;
    tcp::acceptor acceptor_;
};

int main(int argc, char* argv[])
{
    config c;
    if (c.init("vaultster.ini", argc, argv))
        exit(1);

    io_service io_service;

    try {
        server s(io_service, &c);
        io_service.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
