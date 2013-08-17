//////////////////////////////////////////////////////////////////////////////
//! \file sac2_input_manager.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (alpha)
//! \date
//!     2013-05-29
//! \brief
//!     Provides \b InputManager to manage inputs from Keyboard.
//! \todo
//!     Handle Mouse, Joystic.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_KEY_HPP
#define SAC2_KEY_HPP

#include <SFML/Window/Keyboard.hpp>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
//! \enum key_t
//! \brief
//!     List of available key codes.
//! \details
//!     Define most keys of \b sf::Keyboard::Key.
//////////////////////////////////////////////////////////////////////////////
enum key_t {
  KEY_A         = sf::Keyboard::A,          //!< The A key
  KEY_B         = sf::Keyboard::B,          //!< The B key
  KEY_C         = sf::Keyboard::C,          //!< The C key
  KEY_D         = sf::Keyboard::D,          //!< The D key
  KEY_E         = sf::Keyboard::E,          //!< The E key
  KEY_F         = sf::Keyboard::F,          //!< The F key
  KEY_G         = sf::Keyboard::G,          //!< The G key
  KEY_H         = sf::Keyboard::H,          //!< The H key
  KEY_I         = sf::Keyboard::I,          //!< The I key
  KEY_J         = sf::Keyboard::J,          //!< The J key
  KEY_K         = sf::Keyboard::K,          //!< The K key
  KEY_L         = sf::Keyboard::L,          //!< The L key
  KEY_M         = sf::Keyboard::M,          //!< The M key
  KEY_N         = sf::Keyboard::N,          //!< The N key
  KEY_O         = sf::Keyboard::O,          //!< The O key
  KEY_P         = sf::Keyboard::P,          //!< The P key
  KEY_Q         = sf::Keyboard::Q,          //!< The Q key
  KEY_R         = sf::Keyboard::R,          //!< The R key
  KEY_S         = sf::Keyboard::S,          //!< The S key
  KEY_T         = sf::Keyboard::T,          //!< The T key
  KEY_U         = sf::Keyboard::U,          //!< The U key
  KEY_V         = sf::Keyboard::V,          //!< The V key
  KEY_W         = sf::Keyboard::W,          //!< The W key
  KEY_X         = sf::Keyboard::X,          //!< The X key
  KEY_Y         = sf::Keyboard::Y,          //!< The Y key
  KEY_Z         = sf::Keyboard::Z,          //!< The Z key
  KEY_0         = sf::Keyboard::Num0,       //!< The 0 key
  KEY_1         = sf::Keyboard::Num1,       //!< The 1 key
  KEY_2         = sf::Keyboard::Num2,       //!< The 2 key
  KEY_3         = sf::Keyboard::Num3,       //!< The 3 key
  KEY_4         = sf::Keyboard::Num4,       //!< The 4 key
  KEY_5         = sf::Keyboard::Num5,       //!< The 5 key
  KEY_6         = sf::Keyboard::Num6,       //!< The 6 key
  KEY_7         = sf::Keyboard::Num7,       //!< The 7 key
  KEY_8         = sf::Keyboard::Num8,       //!< The 8 key
  KEY_9         = sf::Keyboard::Num9,       //!< The 9 key
  KEY_ESC       = sf::Keyboard::Escape,     //!< The Escape key
  KEY_LCTRL     = sf::Keyboard::LControl,   //!< The left Control key
  KEY_LSHIFT    = sf::Keyboard::LShift,     //!< The left Shift key
  KEY_ALT       = sf::Keyboard::LAlt,       //!< The left Alt key
  KEY_RCTRL     = sf::Keyboard::RControl,   //!< The right Control key
  KEY_RSHIFT    = sf::Keyboard::RShift,     //!< The right Shift key
  KEY_ALTGR     = sf::Keyboard::RAlt,       //!< The Alt Graphic key
  KEY_MENU      = sf::Keyboard::Menu,       //!< The Menu key
  KEY_SPACE     = sf::Keyboard::Space,      //!< The Space key
  KEY_ENTR      = sf::Keyboard::Return,     //!< The Return key
  KEY_BACKSPACE = sf::Keyboard::BackSpace,  //!< The Backspace key
  KEY_TAB       = sf::Keyboard::Tab,        //!< The Tabulation key
  KEY_PGUP      = sf::Keyboard::PageUp,     //!< The Page up key
  KEY_PGDN      = sf::Keyboard::PageDown,   //!< The Page down key
  KEY_HOME      = sf::Keyboard::Home,       //!< The Home key
  KEY_END       = sf::Keyboard::End,        //!< The End key
  KEY_INS       = sf::Keyboard::Insert,     //!< The Insert key
  KEY_DEL       = sf::Keyboard::Delete,     //!< The Delete key
  KEY_ADD       = sf::Keyboard::Add,        //!< The + key
  KEY_SUB       = sf::Keyboard::Subtract,   //!< The - key
  KEY_MUL       = sf::Keyboard::Multiply,   //!< The * key
  KEY_DIV       = sf::Keyboard::Divide,     //!< The / key
  KEY_LEFT      = sf::Keyboard::Left,       //!< Left arrow
  KEY_RIGHT     = sf::Keyboard::Right,      //!< Right arrow
  KEY_UP        = sf::Keyboard::Up,         //!< Up arrow
  KEY_DOWN      = sf::Keyboard::Down,       //!< Down arrow
  KEY_NUM0      = sf::Keyboard::Numpad0,    //!< The numpad 0 key
  KEY_NUM1      = sf::Keyboard::Numpad1,    //!< The numpad 1 key
  KEY_NUM2      = sf::Keyboard::Numpad2,    //!< The numpad 2 key
  KEY_NUM3      = sf::Keyboard::Numpad3,    //!< The numpad 3 key
  KEY_NUM4      = sf::Keyboard::Numpad4,    //!< The numpad 4 key
  KEY_NUM5      = sf::Keyboard::Numpad5,    //!< The numpad 5 key
  KEY_NUM6      = sf::Keyboard::Numpad6,    //!< The numpad 6 key
  KEY_NUM7      = sf::Keyboard::Numpad7,    //!< The numpad 7 key
  KEY_NUM8      = sf::Keyboard::Numpad8,    //!< The numpad 8 key
  KEY_NUM9      = sf::Keyboard::Numpad9,    //!< The numpad 9 key
  KEY_F1        = sf::Keyboard::F1,         //!< The F1 key
  KEY_F2        = sf::Keyboard::F2,         //!< The F2 key
  KEY_F3        = sf::Keyboard::F3,         //!< The F3 key
  KEY_F4        = sf::Keyboard::F4,         //!< The F4 key
  KEY_F5        = sf::Keyboard::F5,         //!< The F5 key
  KEY_F6        = sf::Keyboard::F6,         //!< The F6 key
  KEY_F7        = sf::Keyboard::F7,         //!< The F7 key
  KEY_F8        = sf::Keyboard::F8,         //!< The F8 key
  KEY_F9        = sf::Keyboard::F9,         //!< The F9 key
  KEY_F10       = sf::Keyboard::F10,        //!< The F10 key
  KEY_F11       = sf::Keyboard::F11,        //!< The F11 key
  KEY_F12       = sf::Keyboard::F12,        //!< The F12 key
  KEY_PAUSE     = sf::Keyboard::Pause       //!< The Pause key
};

}  // namespace sac2

#endif  //! SAC2_KEY_HPP
