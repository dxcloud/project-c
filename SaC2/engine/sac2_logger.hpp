/*!
 * \file    sac2_logger.hpp
 * \author  Chengwu HUANG
 * \version 0.2
 * \date    2013 - 5 -12
 * \brief   Provides \b Logger class
 */

#ifndef SAC2_LOGGER_HPP
#define SAC2_LOGGER_HPP

#include <fstream>

#include <sac2_type.hpp>

namespace sac2
{

/*!
 * \class   Logger
 * \brief   Writting messages to a log file.
 * \details This class is implemented with a singleton pattern.
 *
 *          The logging methods are all static.
 *
 *          Writting methods which take a single argument are named after the
 *          logging level (write_debug, write_config, etc.). These methods
 *          call \b write() with a specific logging level.
 */
class Logger
{
  /*!
   * \brief   A set of standard logging levels that can be used to signal
   *          logging output.
   * \details The logging level indicates the severity of the messages.
   *
   *          Typically, use \b ERROR to report a serious error and
   *          \b DEBUG to display a simple debug trace.
   *
   *          The levels in ascending order are:
   *          - \b DEBUG
   *          - \b CONFIG
   *          - \b INFO
   *          - \b WARNING
   *          - \b ERROR
   */
  typedef enum log_level {
    DEBUG,    ///< Debugging message
    CONFIG,   ///< Configuration message, e.g. CPU type
    INFO,     ///< Informational message
    WARNING,  ///< Potential problem
    ERROR     ///< Serious error message
  } log_level_t;

public:

  /*!
   * \brief Initialize Logger, open file stream for writting
   * \param filename Output Log filename, if the parameter is omitted
   *                 \b DEFAULT_LOG_FILE will be used
   */
  static void open(const std::string& filename=DEFAULT_LOG_FILE);

  /*!
   * \brief Close file stream
   */
  static void close();

  /*!
   * \brief Log a message
   * \param level   Log level identifier
   * \param message The string message
   * \see   log_level
   */
  static void write(log_level_t level, const std::string& message);

  /*!
   * \brief Log a DEBUG type message
   * \param message The string message
   */
  static void write_debug(const std::string& message);

  /*!
   * \brief Log a CONFIG type message
   * \param message The string message
   */
  static void write_config(const std::string& message);

  /*!
   * \brief Log an INFO type message
   * \param message The string message
   */
  static void write_info(const std::string& message);

  /*!
   * \brief Log a WARNING type message
   * \param message The string message
   */
  static void write_warning(const std::string& message);

  /*!
   * \brief Log an ERROR type message
   * \param message The string message
   */
  static void write_error(const std::string& message);

private:
  /*!
   * \brief Private Constructor
   */
  Logger();

  /*!
   * \brief Private Destructor
   */
  ~Logger();

  /*!
   * \brief Private copy Constructor
   * 
   *        Copy is NOT allowed
   */
  Logger(const Logger&);

  /*!
   * \brief Private assignment operator
   * 
   *        Copy is NOT allowed
   */
  Logger& operator=(const Logger&);

private:
  bool                     m_active; ///< Indicates whether Logger is initialized
  std::ofstream            m_stream; ///< Output file stream

  static Logger            m_logger;  ///< Instance of Logger (Singleton)
  static const std::string m_level[]; ///< Text describing \b log_level
  static const std::string DEFAULT_LOG_FILE; ///< Default Output Log file name
};  //class Logger


inline Logger::Logger():
  m_active(false)
{
  // do nothing
}

inline Logger::~Logger()
{
  // do nothing
}

}  // namespace sac2

#endif //! SAC2_LOGGER_HPP
