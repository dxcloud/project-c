//////////////////////////////////////////////////////////////////////////////
//! \file sac2rg.cpp
//! \author
//!     Chengwu Huang
//! \version
//!     0.2.1 (alpha)
//! \date
//!     2013-08-21
//////////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <getopt.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "srg.hpp"

using std::cout;
using std::endl;
using std::string;

void try_help(const string& cmd)
{
  cout << "Try `" << cmd << " --help' for more information." << endl;
  exit(EXIT_SUCCESS);
}

void help(const string& cmd)
{
  cout << "Generate resource header and source from FILE." << endl;
  cout << endl;
  cout << "Usage: " << cmd << "[OPTION]... FILE" << endl;
  cout << endl;
  cout << "Mandatory arguments to long options";
  cout << " are mandatory for short options too." << endl;
  cout << endl;
  cout << "Options:" << endl;
  cout << "  -a, --add-file=FILE      ";
  cout << "add given FILE for resource generation ";
  cout << "(useful whether the resource is plit into several files)" << endl;
  cout << "  -h, --help               ";
  cout << "display this help and exit" << endl;
  cout << "  -O, --to-stdout          ";
  cout << "send output to standard output" << endl;
  cout << "  -o, --output=FILE        ";
  cout << "name the output file prefix (no extension)" << endl;
  cout << "  -V, --version            ";
  cout << "output version information and exit" << endl;
  cout << "  -v, --verbose            ";
  cout << "verbosely list resources processed" << endl;
  cout << "      --exclude-font       ";
  cout << "exclude font type resource" << endl;
  cout << "      --exclude-image      ";
  cout << "exclude image type resource" << endl;
  cout << "      --exclude-music      ";
  cout << "exclude music type resource" << endl;
  cout << "      --exclude-sound      ";
  cout << "exclude sound type resource" << endl;
  cout << "      --hdr-suffix=SUFFIX  ";
  cout << "specify the output header file suffix" << endl;
  cout << "      --src-suffix=SUFFIX  ";
  cout << "specify the output source file suffix" << endl;
  cout << endl;

  cout << "Valid arguments for the --hdr-suffix option are:" << endl;
  cout << "  hpp (default), hh, hxx, h++, HPP, H" << endl;
  cout << endl;
  cout << "Valid arguments for the --src-suffix option are:" << endl;
  cout << "  cpp (default), cc, cxx, c++, CPP, C" << endl;
  exit(EXIT_SUCCESS);
}

void version(const string& cmd)
{
  cout << cmd << " 0.2.1 (alpha)";
  cout << endl << endl;
  cout << "Copyright (C) 2013 SaC2";
  cout << endl << endl;
  cout << "Written by Chengwu Huang <chengwhuang@gmail.com>" << endl;
  exit(EXIT_SUCCESS);
}

enum ARG_OPTION
{
  NONE       = 0,
  ADD_FILE   = 'a',
  HELP       = 'h',
  TO_STDOUT  = 'O',
  OUTPUT     = 'o',
  VERSION    = 'V',
  VERBOSE    = 'v',
  EXCLUDE_FT = 300,
  EXCLUDE_IM = 301,
  EXCLUDE_MC = 302,
  EXCLUDE_SD = 303,
  HDR_SUFFIX = 1,
  SRC_SUFFIX = 2
};

const struct option long_options[] =
{
  {"add-file",      required_argument, 0, ADD_FILE  },
  {"help",          no_argument,       0, HELP      },
  {"to-stdout",     no_argument,       0, TO_STDOUT },
  {"output",        required_argument, 0, OUTPUT    },
  {"version",       no_argument,       0, VERSION   },
  {"verbose",       no_argument,       0, VERBOSE   },
  {"exclude-font",  no_argument,       0, EXCLUDE_FT},
  {"exclude-image", no_argument,       0, EXCLUDE_IM},
  {"exclude-music", no_argument,       0, EXCLUDE_MC},
  {"exclude-sound", no_argument,       0, EXCLUDE_SD},
  {"hdr-suffix",    required_argument, 0, HDR_SUFFIX},
  {"src-suffix",    required_argument, 0, SRC_SUFFIX},
  {0,               0,                 0, NONE      }
};


//////////////////////////////////////////////////////////////////////////////
// main
//////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
  string command(argv[0]);
  string input_file;
  string output_file;
  string h_suffix;
  string s_suffix;
  int    option_index(0);
  bool   verbose(false);

  while (true) {
    int option_arg = getopt_long(argc,
                                 argv,
                                 "a:hOo:Vv",
                                 long_options,
                                 &option_index);
    if (-1 == option_arg) { break; }  // no option to parse
    switch (option_arg) {
      case ADD_FILE:
        cout << "option " << long_options[option_index].name;
        cout << " " << optarg << endl;
        break;
      case HELP:
        help(command);
      case TO_STDOUT:
        cout << "to-stdout" << endl;
        break;
      case OUTPUT:
        output_file = optarg;
        break;
      case VERSION:
        version(command);
        break;
      case VERBOSE:
        verbose = true;
        break;
      case EXCLUDE_FT:
        cout << "x font" << endl;
        break;
      case EXCLUDE_IM:
        cout << "x image" << endl;
        break;
      case EXCLUDE_MC:
        cout << "x music" << endl;
        break;
      case EXCLUDE_SD:
        cout << "x sound" << endl;
        break;
      case HDR_SUFFIX:
        h_suffix = optarg;
        break;
      case SRC_SUFFIX:
        s_suffix = optarg;
        break;
      default:
        try_help(command);
      }
  }

  if (optind < argc) {
    if (argc - 1 == optind) {
      input_file = argv[optind];
      cout << "non-option ARGV element: " << input_file << endl;
    }
    else {
      cout << command << ": too many file operands" << endl;
      try_help(command);
    }
  }
  else {
    cout << command << ": missing file operand" << endl;
    try_help(command);
  }

  srg::Srg generator;
  generator.set_input_file(input_file);
  generator.set_verbose(verbose);
  if (true == generator.parse_xml()) {
    generator.generate();
  }

  return 0;
}
