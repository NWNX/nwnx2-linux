//
// vaultster-config.cpp - Vaultster config class
// ~~~~~~~~~~~~~~~~~~~~~~~~~
// Copyright (c) 2009 John Klar ( plasmajohn at avlis dot org )
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "vaultster-config.h"
#include <boost/program_options.hpp>
namespace po = boost::program_options;

int
config::init(const char *fname, int argc, char **argv)
{
    ifstream config(fname);
    if (!config) {
        cout << "Could not open " << fname << endl;
        return -1;
    }

    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("Vaultster.Port",
     po::value<unsigned short>()->default_value(5100), "set listening port")
    ("Vaultster.Path",
     po::value<string>(),				"set path to servervault")
    ("Vaultster.Key",
     po::value<string>()->default_value("abcdefgh"),	"set key")
    ("Vaultster.Password",
     po::value<string>()->default_value("AVLIS"),	"set password")
    ("Vaultster.ValidateClient",
     po::value<bool>()->default_value(true),		"enable validation")
    ("Vaultster.MaxClients",
     po::value<int>()->default_value(30),		"set maximum clients")
    ("Vaultster.Debug",
     po::value<int>()->default_value(0),		"set debug level")
    ("Vaultster.Server",
     po::value<vector<string> >(),			"allowed servers")
    ;

    po::variables_map vm;
    po::store(po::parse_config_file(config, desc, true), vm);
    po::notify(vm);

    config.close();

    if (! vm.count("Vaultster.Path")) {
        cout << "[Vaultster].Path option is missing.  Set it to point to your servervault." << endl;
        return -2;
    }

    if (! vm.count("Vaultster.Server")) {
        cout << "[Vaultster].Server entries are missing.  Add at least one containing the DNS or IP address of an authorized client." << endl;
        return -3;
    }

    port =		vm["Vaultster.Port"].as<unsigned short>();;
    path =		vm["Vaultster.Path"].as<string>();
    key =		vm["Vaultster.Key"].as<string>();
    password =	vm["Vaultster.Password"].as<string>();
    validate =	vm["Vaultster.ValidateClient"].as<bool>();
    maxclients = 	vm["Vaultster.MaxClients"].as<int>();
    debug = 	vm["Vaultster.Debug"].as<int>();
    servers	=	vm["Vaultster.Server"].as<vector<string> >();

    return 0;
}

