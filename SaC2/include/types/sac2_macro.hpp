#ifndef SAC2_MACRO_HPP
#define SAC2_MACRO_HPP

//////////////////////////////////////////////////////////////////////////////
//! \def ASSET_MANAGER
//! \brief
//!     Macro, equivalent to \b sac2::AssetManager::instance().
//////////////////////////////////////////////////////////////////////////////
#ifndef ASSET_MANAGER
#define ASSET_MANAGER sac2::AssetManager::instance()
#endif

//////////////////////////////////////////////////////////////////////////////
//! \def INPUT_MANAGER
//! \brief
//!     Macro, equivalent to \b sac2::InputManager::instance().
//////////////////////////////////////////////////////////////////////////////
#ifndef INPUT_MANAGER
#define INPUT_MANAGER sac2::InputManager::instance()
#endif

//////////////////////////////////////////////////////////////////////////////
//! \def RENDER_MANAGER
//! \brief
//!     Macro, equivalent to \b sac2::RenderingManager::instance().
//////////////////////////////////////////////////////////////////////////////
#ifndef RENDER_MANAGER
#define RENDER_MANAGER sac2::RenderingManager::instance()
#endif

//////////////////////////////////////////////////////////////////////////////
//! \def STATE_MANAGER
//! \brief
//!     Macro, equivalent to sac2::StateManager::instance().
//////////////////////////////////////////////////////////////////////////////
#ifndef STATE_MANAGER
#define STATE_MANAGER sac2::StateManager::instance()
#endif

#ifndef WINDOW_WIDTH
#define WINDOW_WIDTH sac2::RenderingManager::instance().get_width()
#endif

#ifndef WINDOW_HEIGHT
#define WINDOW_HEIGHT sac2::RenderingManager::instance().get_height()
#endif

//////////////////////////////////////////////////////////////////////////////
//! \def LOG_DEBUG
//! \brief
//!     Equivalent to \b sac2::Logger::log_debug
//!     whether \b SAC2_LOGGER_ENABLED is defined.
//! \see sac2::Logger::log_debug
//!
//! \def LOG_CONFIG
//! \brief
//!     Equivalent to \b sac2::Logger::log_config
//!     whether \b SAC2_LOGGER_ENABLED is defined.
//! \see sac2::Logger::log_config
//!
//! \def LOG_INFO
//! \brief
//!     Equivalent to \b sac2::Logger::log_info
//!     whether \b SAC2_LOGGER_ENABLED is defined.
//! \see sac2::Logger::log_info
//!
//! \def LOG_WARNING
//! \brief
//!     Equivalent to \b sac2::Logger::log_warning
//!     whether \b SAC2_LOGGER_ENABLED is defined.
//! \see sac2::Logger::log_warning
//!
//! \def LOG_ERROR
//! \brief
//!     Equivalent to \b sac2::Logger::log_error
//!     whether \b SAC2_LOGGER_ENABLED is defined.
//! \see sac2::Logger::log_debug
//////////////////////////////////////////////////////////////////////////////
#ifdef SAC2_LOGGER_ENABLED
#define LOG_DEBUG(X)   sac2::Logger::log_debug(X);
#define LOG_CONFIG(X)  sac2::Logger::log_config(X);
#define LOG_INFO(X)    sac2::Logger::log_info(X);
#define LOG_WARNING(X) sac2::Logger::log_warning(X);
#define LOG_ERROR(X)   sac2::Logger::log_error(X);
#else
#define LOG_DEBUG(X)
#define LOG_CONFIG(X)
#define LOG_INFO(X)
#define LOG_WARNING(X)
#define LOG_ERROR(X)
#endif  // SAC2_LOGGER_ENABLED

#endif  //! SAC2_MACRO_HPP

