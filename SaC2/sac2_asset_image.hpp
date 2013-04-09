#ifndef _ASSET_IMAGE_HPP_
#define _ASSET_IMAGE_HPP_

/*!
 * \file    sac2_asset_image.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief
 */

#include <string>

#include "sac2_asset.hpp"

namespace sac2
{

class AssetImage: public Asset
{
 public:
  AssetImage(const std::string& filename):
    Asset(filename)
  {}

  ~AssetImage() {}
  
  virtual sac2_status_t load_asset();
  
 protected:
 
 private:
};  // class AssetImage

}

#endif