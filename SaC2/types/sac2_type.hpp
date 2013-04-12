﻿#ifndef _SAC2_TYPE_HPP_
#define _SAC2_TYPE_HPP_

/*!
 * \file    sac2_type.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief
 */

#include <string>
#include <map>

#include <SFML/Window.hpp>

namespace sac2
{

//! Default name for the application
const std::string defaultApplicationName("SaC2 Demo");

typedef const std::string asset_id_t;

#ifdef LOG_ENABLED
//! Default Log file name
const std::string defaultLogFile("output.log");
#endif

//! State ID, used for identifying Game state
typedef enum sac2_state_id {
  STATE_CURRENT = 0, //!< Current State
  STATE_MENU    = 1  //!< Main Menu State
} sac2_state_id_t;

//! Asset ID, used for identifying Asset objects
typedef std::string sac2_asset_id_t;

typedef struct sac2_engine_conf {
  std::string app_name;
  int         weight;
  int         height;
  int         frame_rate;
} sac2_engine_conf_t;

//! Default video settings
enum sac2_default_video_settings {
  DEFAULT_VIDEO_WIDTH     = 1024, //!< Video mode width, in pixels
  DEFAULT_VIDEO_HEIGHT    = 768,  //!< Video mode height, in pixels
  DEFAULT_VIDEO_BPP       = 32,   //!< Video mode pixel depth, in bits per pixels
  DEFAULT_FRAMERATE_LIMIT = 60,   //!< Maximum fixed frequency
  DEFAULT_DB              = 24,   //!< Bits of the depth buffer
  DEFAULT_SB              = 8,    //!< Bits of the stencil buffer
  DEFAULT_AAL             = 0,    //!< Level of antialiasing
  //! Window creation styles
  DEFAULT_STYLE           = (sf::Style::Resize | sf::Style::Close)
};

//! Status Return value
typedef enum sac2_status {
  STATUS_SUCCESS  = 0,  //!< General success response
  STATUS_ERROR    = 1,  //!< Generic condition: backwards compatible
  STATUS_FAIL     = 2,  //!< Initialization failed
  STATUS_CANCEL   = 3,  //!< Operation cancelled by a call
  STATUS_BUSY     = 4,  //!< Callee function no responding
  STATUS_INVAL    = 5,  //!< An invalid parameter was passed
  STATUS_ALREADY  = 5,  //!< Parameter is already used/deleted
  STATUS_MISS     = 6,  //!< A file is missing
  STATUS_NOMEM    = 7,  //!< Memory requirred not available
  STATUS_QUIT     = 8,
  STATUS_UNKNOWN        //!< Unknown behaviour
} sac2_status_t;

//! Asset type
typedef enum sac2_asset_type {
  ASSET_FONT,   //!< Font
  ASSET_SPRITE, //!< Sprite
  ASSET_IMAGE,  //!< Image
  ASSET_MUSIC,  //!< Background Music
  ASSET_SOUND,  //!< Sound effect
  ASSET_SCRIPT, //!< Script
  ASSET_MAP,    //!< Map
  ASSET_CUSTOM  //!< Other type
} sac2_asset_type_t;

} // namespace sac2

#endif