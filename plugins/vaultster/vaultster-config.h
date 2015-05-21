//
// vaultster-config.h - Vaultster config class
// ~~~~~~~~~~~~~~~~~~~~~~~~~
// Copyright (c) 2009 John Klar ( plasmajohn at avlis dot org )
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef vaultster_config_h_
#define vaultster_config_h_

#include <vector>
#include <cstdlib>
using namespace std;

class config
{
public:
    unsigned short port;
    string path;
    string key;
    string password;
    bool validate;
    int maxclients;
    int debug;
    vector<string> servers;

    config() : port(5100), validate(true), maxclients(30), debug(0) {};

    int init(const char *fname, int argc, char **argv);
};

#endif
