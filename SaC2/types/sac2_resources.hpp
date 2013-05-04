/*!
 * \file    sac2_resources.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013 - 04 -20
 * \brief   Allows to access resource by \b Identifier
 * \details \b Res is defined as a \b static \b struct
 */

#ifndef SAC2_RESOURCES_HPP
#define SAC2_RESOURCES_HPP

#include <map>
#include <string>

#include "sac2_type.hpp"

namespace sac2
{

//! Associates a resource name with an \b Identifier
typedef struct res {
  static const sac2_asset_map_t image;  //!< Image type resource name
  static const sac2_asset_map_t font;   //!< Font type resource name
} Res;

//! Constant iterator for \b Res
typedef sac2_asset_map_t::const_iterator sac2_res_it;

}  //! namespace sac2

#endif  //! SAC2_RESOURCES_HPP
