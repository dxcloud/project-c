/*!
 * \file    sac2_input_config.hpp
 * \author  Chengwu Huang
 * \version 1.0
 * \date    2013-05-29
 * \brief   Provides InputConfig class and DefaultInputConfig as a default
 *          input configuration.
 */

#ifndef SAC2_INPUT_CONFIG_HPP
#define SAC2_INPUT_CONFIG_HPP

#include <SFML/Window.hpp>

#include <sac2_type.hpp>
#include <sac2_engine.hpp>
#include <sac2_logger.hpp>

namespace sac2
{
/*!
 * \enum    key_t
 * \brief   List of available key codes
 * \details The items of this list are mostly the same as \b sf::Keyboard::Key.
 *          Some key codes are missing.
 */
typedef enum key_t {
  KEY_A         = sf::Keyboard::A,        ///< The A key
  KEY_B         = sf::Keyboard::B,            ///< The B key
  KEY_C         = sf::Keyboard::C,            ///< The C key
  KEY_D         = sf::Keyboard::D,            ///< The D key
  KEY_E         = sf::Keyboard::E,            ///< The E key
  KEY_F         = sf::Keyboard::F,            ///< The F key
  KEY_G         = sf::Keyboard::G,            ///< The G key
  KEY_H         = sf::Keyboard::H,            ///< The H key
  KEY_I         = sf::Keyboard::I,            ///< The I key
  KEY_J         = sf::Keyboard::J,            ///< The J key
  KEY_K         = sf::Keyboard::K,            ///< The K key
  KEY_L         = sf::Keyboard::L,            ///< The L key
  KEY_M         = sf::Keyboard::M,            ///< The M key
  KEY_N         = sf::Keyboard::N,            ///< The N key
  KEY_O         = sf::Keyboard::O,            ///< The O key
  KEY_P         = sf::Keyboard::P,            ///< The P key
  KEY_Q         = sf::Keyboard::Q,            ///< The Q key
  KEY_R         = sf::Keyboard::R,            ///< The R key
  KEY_S         = sf::Keyboard::S,            ///< The S key
  KEY_T         = sf::Keyboard::T,            ///< The T key
  KEY_U         = sf::Keyboard::U,            ///< The U key
  KEY_V         = sf::Keyboard::V,            ///< The V key
  KEY_W         = sf::Keyboard::W,            ///< The W key
  KEY_X         = sf::Keyboard::X,            ///< The X key
  KEY_Y         = sf::Keyboard::Y,            ///< The Y key
  KEY_Z         = sf::Keyboard::Z,            ///< The Z key
  KEY_0         = sf::Keyboard::Num0,         ///< The 0 key
  KEY_1         = sf::Keyboard::Num1,         ///< The 1 key
  KEY_2         = sf::Keyboard::Num2,         ///< The 2 key
  KEY_3         = sf::Keyboard::Num3,         ///< The 3 key
  KEY_4         = sf::Keyboard::Num4,         ///< The 4 key
  KEY_5         = sf::Keyboard::Num5,         ///< The 5 key
  KEY_6         = sf::Keyboard::Num6,         ///< The 6 key
  KEY_7         = sf::Keyboard::Num7,         ///< The 7 key
  KEY_8         = sf::Keyboard::Num8,         ///< The 8 key
  KEY_9         = sf::Keyboard::Num9,         ///< The 9 key
  KEY_ESC       = sf::Keyboard::Escape,       ///< The Escape key
  KEY_LCTRL     = sf::Keyboard::LControl,     ///< The left Control key
  KEY_LSHIFT    = sf::Keyboard::LShift,       ///< The left Shift key
  KEY_ALT       = sf::Keyboard::LAlt,         ///< The left Alt key
  KEY_RCTRL     = sf::Keyboard::RControl,     ///< The right Control key
  KEY_RSHIFT    = sf::Keyboard::RShift,       ///< The right Shift key
  KEY_ALTGR     = sf::Keyboard::RAlt,         ///< The Alt Graphic key
  KEY_MENU      = sf::Keyboard::Menu,         ///< The Menu key
  KEY_SPACE     = sf::Keyboard::Space,        ///< The Space key
  KEY_ENTR      = sf::Keyboard::Return,       ///< The Return key
  KEY_BACKSPACE = sf::Keyboard::BackSpace,    ///< The Backspace key
  KEY_TAB       = sf::Keyboard::Tab,          ///< The Tabulation key
  KEY_PGUP      = sf::Keyboard::PageUp,       ///< The Page up key
  KEY_PGDN      = sf::Keyboard::PageDown,     ///< The Page down key
  KEY_HOME      = sf::Keyboard::Home,         ///< The Home key
  KEY_END       = sf::Keyboard::End,          ///< The End key
  KEY_INS       = sf::Keyboard::Insert,       ///< The Insert key
  KEY_DEL       = sf::Keyboard::Delete,       ///< The Delete key
  KEY_ADD       = sf::Keyboard::Add,          ///< The + key
  KEY_SUB       = sf::Keyboard::Subtract,     ///< The - key
  KEY_MUL       = sf::Keyboard::Multiply,     ///< The * key
  KEY_DIV       = sf::Keyboard::Divide,       ///< The / key
  KEY_LEFT      = sf::Keyboard::Left,         ///< Left arrow
  KEY_RIGHT     = sf::Keyboard::Right,        ///< Right arrow
  KEY_UP        = sf::Keyboard::Up,           ///< Up arrow
  KEY_DOWN      = sf::Keyboard::Down,         ///< Down arrow
  KEY_NUM0      = sf::Keyboard::Numpad0,      ///< The numpad 0 key
  KEY_NUM1      = sf::Keyboard::Numpad1,      ///< The numpad 1 key
  KEY_NUM2      = sf::Keyboard::Numpad2,      ///< The numpad 2 key
  KEY_NUM3      = sf::Keyboard::Numpad3,      ///< The numpad 3 key
  KEY_NUM4      = sf::Keyboard::Numpad4,      ///< The numpad 4 key
  KEY_NUM5      = sf::Keyboard::Numpad5,      ///< The numpad 5 key
  KEY_NUM6      = sf::Keyboard::Numpad6,      ///< The numpad 6 key
  KEY_NUM7      = sf::Keyboard::Numpad7,      ///< The numpad 7 key
  KEY_NUM8      = sf::Keyboard::Numpad8,      ///< The numpad 8 key
  KEY_NUM9      = sf::Keyboard::Numpad9,      ///< The numpad 9 key
  KEY_F1        = sf::Keyboard::F1,           ///< The F1 key
  KEY_F2        = sf::Keyboard::F2,           ///< The F2 key
  KEY_F3        = sf::Keyboard::F3,           ///< The F3 key
  KEY_F4        = sf::Keyboard::F4,           ///< The F4 key
  KEY_F5        = sf::Keyboard::F5,           ///< The F5 key
  KEY_F6        = sf::Keyboard::F6,           ///< The F6 key
  KEY_F7        = sf::Keyboard::F7,           ///< The F7 key
  KEY_F8        = sf::Keyboard::F8,           ///< The F8 key
  KEY_F9        = sf::Keyboard::F9,           ///< The F9 key
  KEY_F10       = sf::Keyboard::F10,          ///< The F10 key
  KEY_F11       = sf::Keyboard::F11,          ///< The F11 key
  KEY_F12       = sf::Keyboard::F12,          ///< The F12 key
  KEY_PAUSE     = sf::Keyboard::Pause        ///< The Pause key
} key_t;

class GameState;

/*!
 * \class InputConfig
 * \brief This is a base class for input configuration
 */
class InputConfig
{
public:
  /*!
   * \brief Default constructor
   */
  InputConfig(GameState* game_state = 0);

  /*!
   * \brief Default destructor
   */
  virtual ~InputConfig();

  /*!
   * \brief
   */
  void bind_game_state(GameState* game_state);

  /*!
   * \brief   Handle inputs from Keyboard
   * \details This method must be override by any derived class
   * \return  SaC2 status
   */
  virtual void handle_inputs() = 0;

protected:
  GameState* p_game_state;

protected:
  /*!
   * \brief   Check if a key is pressed
   * \param   key Key to be checked
   * \return  Return \b true if the key is pressed, false otherwise
   * \see     key_t
   */
  bool is_key_pressed(key_t key);
};  // class InputConfig


//----------------------------------------------------------------------------
//  InputConfig::InputConfig
//----------------------------------------------------------------------------
inline InputConfig::InputConfig(GameState* game_state):
  p_game_state(game_state)
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("InputConfig::constructor - new input config created");
#endif
}

//----------------------------------------------------------------------------
//  InputConfig::~InputConfig
//----------------------------------------------------------------------------
inline InputConfig::~InputConfig()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("InputConfig::destructor - input config deleted");
#endif
}

//----------------------------------------------------------------------------
//  InputConfig::is_key_pressed
//----------------------------------------------------------------------------
inline bool InputConfig::is_key_pressed(key_t key)
{
  return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key));
}

/*!
 * \class   DefaultInputConfig
 * \brief   This is a default input configuration
 * \details To use another configuration instead of this one, call
 *          set_input_config(new_input_config_pointer) from InputManager
 * \see     InputManager
 */
class DefaultInputConfig:
  public InputConfig
{
public:
  /*!
   * \brief Default constructor
   */
  DefaultInputConfig(GameState* game_state = 0);

  /*!
   * \brief Default destructor
   */
  ~DefaultInputConfig();

  /*!
   * \brief   Handle inputs
   * \details Call Engine::quit() whether 'Escape' key is pressed
   */
  void handle_inputs();
};  // class DefaultInputConfig


//----------------------------------------------------------------------------
//  DefaultInputConfig::DefaultInputConfig
//----------------------------------------------------------------------------
inline DefaultInputConfig::DefaultInputConfig(GameState* game_state):
  InputConfig(game_state)
{
  // do nothing
}

//----------------------------------------------------------------------------
//  DefaultInputConfig::~DefaultInputConfig
//----------------------------------------------------------------------------
inline DefaultInputConfig::~DefaultInputConfig()
{
  // do nothing
}

//----------------------------------------------------------------------------
//  DefaultInputConfig::handle_inputs
//----------------------------------------------------------------------------
inline void DefaultInputConfig::handle_inputs()
{
  if (true == is_key_pressed(KEY_ESC)) {
#ifdef SAC2_LOGGER_ENABLED
    Logger::log_debug("DefaultInputConfig::handle_inputs - Escape key pressed");
#endif
    Engine::quit();
  }
}


}  // namespace sac2

#endif  //! SAC2_INPUT_CONFIG_HPP
