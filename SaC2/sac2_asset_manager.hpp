#ifndef _ASSET_MANAGER_HPP_
#define _ASSET_MANAGER_HPP_

/*!
 * \file    sac2_asset_manager.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief
 */

#include "sac2_type.hpp"

namespace sac2
{

class AssetManager
{
 public:

  AssetManager() {}

  ~AssetManager() {}

  sac2_status_t load_asset(sac2_asset_type_t type);

  sac2_status_t delete_asset(sac2_asset_type_t type);

 protected:

 private:
};  // class AssetManager

}

#endif