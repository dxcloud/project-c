////////////////////////////////////////////////////////////////////////////////
/// @file    icelos.hpp
/// @brief   Main include file.
/// @date    2014-05-14
/// @version 0.1 (alpha)
/// @author  Chengwu Huang <chengwhuang@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef ICELOS_TYPE_HPP
#define ICELOS_TYPE_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include <cmath>
#include <vector>
#include <map>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define GL3_PROTOTYPES 1
#include <GLES3/gl3.h>

#include <icelos_vector.hpp>
#include <icelos_color.hpp>
#include <icelos_rectangle.hpp>
#include <icelos_key.hpp>
#include <icelos_macros.hpp>

namespace icelos
{

typedef std::string string_t;
//typedef uint32_t size_t;
typedef uint32_t resource_id_t;
typedef Color color_t;


enum status_t {
  STATUS_SUCCESS = 0, //!< General success response
  STATUS_ERROR   = 1, //!< Generic condition: backwards compatible
  STATUS_FAIL    = 2, //!< Initialization failed
  STATUS_CANCEL  = 3, //!< Operation cancelled by a call
  STATUS_BUSY    = 4, //!< Callee function no responding
  STATUS_INVAL   = 5, //!< An invalid parameter was passed
  STATUS_ALREADY = 6, //!< Parameter is already used/deleted
  STATUS_MISS    = 7, //!< A file is missing
  STATUS_NOMEM   = 8, //!< Memory requirred not available
  STATUS_UNKNOWN = 9, //!< Unknown status
  NUM_STATUS     = 10 ///< Total number of status
};

enum state_t
{
  UNINITIALIZED = 0,  //!< Uninitialized
  INITIALIZED   = 1,    //!< Initialized
  UNLOADED      = 0,       //!< Unloaded
  LOADED        = 1,         //!< Loaded
  CREATED       = 1,        //!< Created
  RUNNING       = 2,        //!< Running
  PAUSED        = 8,         //!< Paused
  STOPPED       = 16,        //!< Stopped
  DESTROYED     = 32,      //!< Destroyed
  SHUTDOWN      = 64  //!< Shut Down
};

// #define OUT(X) std::cout << X << std::endl;

namespace time
{
  const uint32_t MILLISECOND = 1000U;
  const uint32_t ZERO = 0U;
}

}

#endif /// ICELOS_TYPE_HPP

