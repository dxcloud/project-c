//////////////////////////////////////////////////////////////////////////////
//! \file sac2_input_config.hpp
//! \author
//!     Chengwu Huang
//! \version
//!     0.1 (alpha)
//! \date
//!     2013-05-29
//! \brief
//!     Provides InputConfig class and DefaultInputConfig as a default
//!     input configuration.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_INPUT_CONFIG_HPP
#define SAC2_INPUT_CONFIG_HPP

#include <sac2_type.hpp>
#include <sac2_logger.hpp>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
//! \class InputConfig
//! \brief
//!     This is a base class for input configuration.
//////////////////////////////////////////////////////////////////////////////
class InputConfig
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Public default constructor.
  ////////////////////////////////////////////////////////////////////////////
  InputConfig();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Public destructor.
  ////////////////////////////////////////////////////////////////////////////
  virtual ~InputConfig();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Handle inputs from Keyboard.
  //! \details
  //!     Override this method to handle inputs.
  ////////////////////////////////////////////////////////////////////////////
  virtual void handle_inputs() = 0;

protected:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Check whether the specified key is pressed.
  //! \param[in] key
  //!     Key to be checked.
  //! \return
  //!     Return \b true whether the key is pressed, \b false otherwise.
  ////////////////////////////////////////////////////////////////////////////
  bool is_key_pressed(key_t key);
};  // class InputConfig

}  // namespace sac2

#include <sac2_input_config.inl>

#endif  //! SAC2_INPUT_CONFIG_HPP
