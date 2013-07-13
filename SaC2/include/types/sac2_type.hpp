/*!
 * \file    sac2_type.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Provides SaC2 types including typedef
 */

#ifndef SAC2_TYPE_HPP
#define SAC2_TYPE_HPP

#include <iostream>
#include <string>
#include <map>

#include <SFML/Window.hpp>

#include <sac2_status.hpp>
//#include <sac2_math_physics_type.hpp>
#include <sac2_vector2d.hpp>
#include <sac2_math.hpp>
#include <sac2_physics.hpp>

/*!
 * \namespace sac2
 * \brief     Main namespace
 */
namespace sac2
{

//! Default name for the application
const std::string defaultApplicationName = "SaC2 Demo";

//! Default Log file name
const std::string defaultLogFile = "output.log";

//! State ID, used for identifying Game state
typedef uint8_t state_id_t;

//! Asset ID, used for identifying Asset objects
typedef uint32_t asset_id_t;

//! Engine configuration file parameters
typedef struct sac2_engine_conf {
  std::string app_name;    //!< Name of the application
  int         weight;      //!< Window weight
  int         height;      //!< Window height
  int         frame_rate;  //!< Frame rate
} sac2_engine_conf_t;

//! Default video settings
enum DEFAUL_VIDEO_SETTING {
  DEFAULT_VIDEO_WIDTH     = 1024U, //!< Video mode width, in pixels
  DEFAULT_VIDEO_HEIGHT    = 768U,  //!< Video mode height, in pixels
  DEFAULT_VIDEO_BPP       = 32U,   //!< Video mode pixel depth, in bits per pixels
  DEFAULT_FRAMERATE_LIMIT = 60,   //!< Maximum fixed frequency
  DEFAULT_DB              = 24,   //!< Bits of the depth buffer
  DEFAULT_SB              = 8,    //!< Bits of the stencil buffer
  DEFAULT_AAL             = 0,    //!< Level of antialiasing
  //! Window creation styles
  DEFAULT_STYLE           = (sf::Style::Resize | sf::Style::Close)
};



/*!
 * \enum    state_t
 * \brief   List of different states
 * \details Could be used by a State Machine
 */
enum state_t
{
  UNINITIALIZED,  //!< Uninitialized
  INITIALIZED,    //!< Initialized
  UNLOADED,       //!< Unloaded
  LOADED,         //!< Loaded
  CREATED,        //!< Created
  RUNNING,        //!< Running
  PAUSED,         //!< Paused
  STOPPED,        //!< Stopped
  DESTROYED,      //!< Destroyed
  SHUTDOWN        //!< Shut Down
};


//! Asset type
typedef enum asset_type_t {
  ASSET_FONT,   //!< Font
  ASSET_SPRITE, //!< Sprite
  ASSET_IMAGE,  //!< Image
  ASSET_TEXTURE,
  ASSET_MUSIC,  //!< Background Music
  ASSET_BUFFER, //!< Sound Buffer
  ASSET_SOUND,  //!< Sound effect
  ASSET_TEXT,   //!< Text
  ASSET_SCRIPT, //!< Script
  ASSET_MAP,    //!< Map
  ASSET_CUSTOM,  //!< Other type
  ASSET_UNDEFINED
} asset_type_t;


} // namespace sac2


#endif  //! SAC2_TYPE_HPP
