#ifndef SAC2_VERIONS_HPP
#define SAC2_VERSION_HPP

#include <string>

namespace sac2
{

enum {
  VERSION_MAJOR    = 0,
  VERSION_MINOR    = 1,
  VERSION_REVISION = 0
};

std::string version_info();

}

#endif
