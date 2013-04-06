#ifndef _ASSET_MANAGER_HPP_
#define _ASSET_MANAGER_HPP_

#include "sac2_type.hpp"

namespace sac2
{

class AssetManager
{
 public:

  AssetManager() {}

  ~AssetManager() {}

  sac2_status_t load_asset(sac2_asset_type type);

  sac2_status_t delete_asset(sac2_asset_type type);

 protected:

 private:
};  // class AssetManager

};

#endif