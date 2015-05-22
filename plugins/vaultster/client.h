//
// voltster-client.h - An NWNX Vaultster compatible receiver
// ~~~~~~~~~~~~~~~~~~~~~~~~~
// Copyright (c) 2009 John Klar ( plasmajohn at avlis dot org )
//
// Adapted from async_tcp_echo_server.cpp which is
// Copyright (c) 2003-2007 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef client_h_
#define client_h_

#include <stdio.h>

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/thread.hpp>

#include "NWNXBase.h"
#include "blowfish.h"

using namespace std;
using namespace boost::asio;
using boost::asio::ip::tcp;

class client;

struct request {
    io_service	ios;

    client*		c;
    boost::thread*	t;

    time_t		s_time;
    int		status;

    string		playerid;
    string		charname;
};

class client
{
public:

    client(io_service& io_service,
           const string& player,
           const string& charname,
           const char*   server,
           const char*   port,
           const string& key,
           const string& password,
           const string& vaultpath,
           int debug,
           CNWNXBase *logger,
           request *req);

    ~client();

    bool prepfile();

    void start();

protected:
    void handle_resolve(const boost::system::error_code& err,
                        tcp::resolver::iterator endpoint_iterator);
    void handle_connect(const boost::system::error_code& err,
                        tcp::resolver::iterator endpoint_iterator);
    void handle_state(const boost::system::error_code& error,
                      size_t bytes_transferred);
    void handle_timeout(const boost::system::error_code& error);

    void send_word(int word);
    void send(int length);
    void sendbuf(unsigned char *buf, int length);
    void recv(int length);
    void recvbuf(unsigned char *buf, int length);

private:
    tcp::resolver resolver_;
    tcp::socket socket_;
    deadline_timer timer_;

    enum { max_length = 1024 };

    enum { HNDL_SEND_CMD = 0, HNDL_RECV_ACK_CMD, HNDL_SEND_ENC_PWD, HNDL_RECV_ACK_PWD,
           HNDL_SEND_ENC_PIDLEN, HNDL_SEND_ENC_PID, HNDL_SEND_ENC_BICNAMELEN,
           HNDL_SEND_ENC_BICNAME, HNDL_RECV_REDUNDANT_ACK_CMD, HNDL_SEND_FILESIZE,
           /* HNDL_SEND_CMPFSIZE, */
           HNDL_CHUNK, HNDL_LAST_CHUNK, HNDL_FILE_STATUS,
           DONE
         };

    enum { LOG_EMERG = 0, LOG_ALERT, LOG_CRIT, LOG_ERR, LOG_WARNING, LOG_NOTICE,
           LOG_INFO, LOG_DEBUG
         };

    // config *c_;
    char data_[max_length];
    char buf_[max_length];
    char playerid_[128];
    char bicname_[32];
    string server_, port_, key_, pass_, vaultpath_;
    int state_, debug_;
    unsigned char *cmpdata_;
    unsigned long len_, fishlen_, size_, cmpsize_, chunkpos_;
    CBlowFish fish;
    CNWNXBase *logger_;
    request *req_;
};

#endif

