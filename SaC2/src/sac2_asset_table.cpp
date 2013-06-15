//#ifdef USE_SAC2_DEFAULT_RESOURCE

#include "sac2_asset_table.hpp"

namespace sac2 {

#ifdef RESOURCE_PATH
const std::string AssetTable::m_res_path(RESOURCE_PATH);
#else
const std::string AssetTable::m_res_path(".");
#endif

//----------------------------------------------------------------------------
//  Ressource::m_textures
//----------------------------------------------------------------------------
asset_map_t AssetTable::m_table(create_table());

//----------------------------------------------------------------------------
//  Ressource::create_table
//----------------------------------------------------------------------------
asset_map_t AssetTable::create_table()
{
  asset_map_t table;
  table.insert(std::make_pair(static_cast<asset_id_t>(IMAGE_01),
                              m_res_path + "/image/image01.png"));
  table.insert(std::make_pair(static_cast<asset_id_t>(IMAGE_02),
                              m_res_path + "/image/image02.png"));
  return table;
}

//----------------------------------------------------------------------------
//  Ressource::find_asset
//----------------------------------------------------------------------------
const std::string& AssetTable::find_asset(asset_id_t id) const
{
  return m_table.find(id)->second;
}

}

//#endif
