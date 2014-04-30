#include <sac2_asset_manager.hpp>
#include "resource.hpp"

namespace sac2
{

const asset_map_t AssetManager::m_asset_table =
{
  {(asset_id_t) IM0001, "image/image01.png"},
  {(asset_id_t) IM0002, "image/image02.png"},
  {(asset_id_t) SD0001, "sound/sound01.ogg"}
};

}

