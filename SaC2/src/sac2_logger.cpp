#include <sac2_logger.hpp>

namespace sac2
{

Logger Logger::m_logger;

const std::string Logger::m_level[]=
{
  "[DEBUG]  : ",
  "[CONFIG] : ",
  "[INFO]   : ",
  "[WARNING]: ",
  "[ERROR]  : "
};

const std::string Logger::DEFAULT_LOG_FILE="SaC2.log";

void Logger::open(const std::string& filename)
{
  if (false == m_logger.m_active) {
    m_logger.m_active = true;
    m_logger.m_stream.open(filename.c_str());
    m_logger.m_stream << "Log File: " << filename << std::endl;
  }
}

void Logger::close()
{
  if (true == m_logger.m_active) {
    m_logger.m_active = false;
    if (true == m_logger.m_stream.is_open()) { m_logger.m_stream.close(); }
  }
}

void Logger::write(log_level_t level, const std::string& message)
{
  if (true == m_logger.m_active) {
    m_logger.m_stream << m_level[level]
                      << message
                      << std::endl;
  }
}

void Logger::write_debug(const std::string& message)
{
  write(DEBUG, message);
}

void Logger::write_config(const std::string& message)
{
  write(CONFIG, message);
}

void Logger::write_info(const std::string& message)
{
  write(INFO, message);
}

void Logger::write_warning(const std::string& message)
{
  write(WARNING, message);
}

void Logger::write_error(const std::string& message)
{
  write(ERROR, message);
}

}
