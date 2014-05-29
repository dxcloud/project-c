////////////////////////////////////////////////////////////////////////////////
/// @file    icelos_engine.hpp
/// @brief   Provides Engine class.
/// @date    2014-05-14
/// @version 0.1 (alpha)
/// @author  Chengwu Huang <chengwhuang@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef ICELOS_ENGINE_HPP
#define ICELOS_ENGINE_HPP

// icelos include
#include <icelos_type.hpp>

namespace icelos
{

class InputManager;

/// @class Engine
/// @brief The Engine class manages the application's control flow.
/// @details
///   The following example shows the minimum lines needed to run
///   an application.
/// @code
///   int main(int argc, char* argv[])
///   {
///     icelos::Engine app(argc, argv);
///     return app.run();
///   }
/// @endcode
class Engine
{
public:
  /// @brief Public default constructor.
  Engine();

  /// @brief Public override constructor.
  Engine(int argc, char* argv[]);

  /// @brief Public destructor.
  ~Engine();

  /// @brief Start engine.
  /// @return Status code.
  ///   - @b STATUS_SUCCESS
  ///   - @b STATUS_ERROR
  status_t run();

private:
  /// @brief Initialize engine.
  status_t initialize();

  /// @brief Cleanup
  void cleanup();

  /// @brief Start game loop
  void game_loop();

public:
  /// @brief Static method
  static void quit();

private:
  static state_t m_engine_state;
  int            m_argc;
  char**         m_argv;
};

}

#endif // ICELOS_ENGINE_HPP

