#ifndef _SAC2_TYPE_HPP_
#define _SAC2_TYPE_HPP_

/*!
 * \file
 * \author
 * \version
 * \date
 * \brief
 */

#include <string>
#include <map>

namespace sac2
{

const std::string defaultApplicationName("SaC2 Demo");
const std::string defaultLogFile("output.log");

//! State ID, used for identifying State objects
//typedef std::string sac2_state_id_t;
typedef unsigned int sac2_state_id_t;

//! Asset ID, used for identifying Asset objects
typedef std::string sac2_asset_id_t;

typedef struct engine_conf {
	std::string app_name;
	int weight;
	int height;
	int frame_rate;
} engine_conf_t;

//! Used for config section maps
typedef std::map<const std::string&, const std::string&> sac2_name_t;

//! Used for name, value pair maps
typedef std::map<const std::string&, const std::string&>::iterator sac2_name_iter_t;

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
  STATUS_MISS     = 6,  //!< A file is missing
  STATUS_NOMEM    = 7,  //!< Memory requirred not available
  STATUS_UNKNOWN  = 8   //!< Unknown behaviour
} sac2_status_t;

//! Asset type
typedef enum asset_type {
  ASSET_FONT,   //!< Font
  ASSET_IMAGE,  //!< Image/Sprite
  ASSET_MUSIC,  //!< Background Music
  ASSET_SOUND,  //!< Sound effect
  ASSET_SCRIPT, //!< Script
  ASSET_MAP,    //!< Map
  ASSET_CUSTOM  //!< Other type
} asset_type_t;

};

#endif