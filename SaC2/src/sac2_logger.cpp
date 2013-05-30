#include <sac2_logger.hpp>

namespace sac2
{

//----------------------------------------------------------------------------
//  Logger::m_logger
//----------------------------------------------------------------------------
Logger Logger::m_logger;

//----------------------------------------------------------------------------
//  Engine::m_level
//----------------------------------------------------------------------------
const std::string Logger::m_level[]=
{
  "[DEBUG]  : ",
  "[CONFIG] : ",
  "[INFO]   : ",
  "[WARNING]: ",
  "[ERROR]  : "
};

//----------------------------------------------------------------------------
//  Engine::DEFAULT_LOG_FILE
//----------------------------------------------------------------------------
const std::string Logger::DEFAULT_LOG_FILE="SaC2.log";

//----------------------------------------------------------------------------
//  Logger::create
//----------------------------------------------------------------------------
void Logger::create(const std::string& filename)
{
  if (false == m_logger.m_active) {
    m_logger.m_active = true;
    m_logger.m_stream.open(filename.c_str());
    m_logger.m_stream << "Log File: " << filename << std::endl;
  }
}

//----------------------------------------------------------------------------
//  Logger::destroy
//----------------------------------------------------------------------------
void Logger::destroy()
{
  if (true == m_logger.m_active) {
    m_logger.m_active = false;
    if (true == m_logger.m_stream.is_open()) {
      m_logger.m_stream << "Log File closed" << std::endl;
      m_logger.m_stream.close();
    }
  }
}

//----------------------------------------------------------------------------
//  Logger::log
//----------------------------------------------------------------------------
void Logger::log(log_level_t level, const std::string& message)
{
  if (true == m_logger.m_active) {
    m_logger.m_stream << m_level[level]
                      << message
                      << std::endl;
  }
  else {
    std::cout << m_level[level]
              << message
              << std::endl;
  }
}

//----------------------------------------------------------------------------
//  Logger::log_debug
//----------------------------------------------------------------------------
void Logger::log_debug(const std::string& message)
{
  log(DEBUG, message);
}

//----------------------------------------------------------------------------
//  Logger::log_config
//----------------------------------------------------------------------------
void Logger::log_config(const std::string& message)
{
  log(CONFIG, message);
}

//----------------------------------------------------------------------------
//  Logger::log_info
//----------------------------------------------------------------------------
void Logger::log_info(const std::string& message)
{
  log(INFO, message);
}

//----------------------------------------------------------------------------
//  Logger::log_warning
//----------------------------------------------------------------------------
void Logger::log_warning(const std::string& message)
{
  log(WARNING, message);
}

//----------------------------------------------------------------------------
//  Logger::log_error
//----------------------------------------------------------------------------
void Logger::log_error(const std::string& message)
{
  log(ERROR, message);
}

}
