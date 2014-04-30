#include <sac2.hpp>

int main()
{
  sac2::Logger::open("output.log");
  sac2::Logger::write_debug("hello world");
  sac2::Logger::close();
  return 0;
}
