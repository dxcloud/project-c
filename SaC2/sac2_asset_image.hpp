#ifndef _ASSET_IMAGE_HPP_
#define _ASSET_IMAGE_HPP_

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