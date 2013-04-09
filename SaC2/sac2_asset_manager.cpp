#include "sac2_asset_manager.hpp"

namespace sac2
{

Asset* AssetManager::get_asset(sac2_asset_type_t type, sac2_asset_id_t id) const
{
  // TODO implement get_asset()
  return 0;
}

sac2_status_t AssetManager::load_asset(sac2_asset_type_t type)
{
  return STATUS_SUCCESS;
}

sac2_status_t AssetManager::delete_asset(sac2_asset_type_t type)
{
  return STATUS_SUCCESS;
}

}