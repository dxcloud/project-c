//#include <sac2.hpp>
//#include "test_06.hpp"
#include <sac2_logger.hpp>

int main() {
  sac2::Logger::create("test6.log");
  sac2::Logger::set_log_level(sac2::Logger::INFO);
  LOG_DEBUG("debug")
  LOG_INFO("info")
  sac2::Logger::log(sac2::Logger::WARNING, "warning");
  
//  sac2::Engine engine;
//  engine.run();
  return 0;
}

