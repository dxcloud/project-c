#include <sstream>

#include <sac2_version.hpp>

namespace sac2
{

std::string version_info()
{
  std::stringstream s;
  s << VERSION_MAJOR
    << "."
    << VERSION_MINOR
    << "."
    << VERSION_REVISION;
  return s.str();
}

}
