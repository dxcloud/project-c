#include <sac2_asset_manager.hpp>
#include "resource.hpp"

namespace sac2
{

const AssetManager::asset_map_t AssetManager::m_asset_table =
{
  {(asset_id_t) IMAGE0, "/home/orange/project-c/SaC2/samples/image/image00.png"},
  {(asset_id_t) IMAGE2, "/home/orange/project-c/SaC2/samples/image/image02.png"},
  {(asset_id_t) IMAGE3, "/home/orange/project-c/SaC2/samples/image/image03.png"},
  {(asset_id_t) MUSIC0, "/home/orange/project-c/SaC2/samples/music/music00.ogg"},
  {(asset_id_t) MUSIC1, "/home/orange/project-c/SaC2/samples/music/J-E-N-O-V-A.ogg"},
  {(asset_id_t) SOUND0, "/home/orange/project-c/SaC2/samples/sound/sound00.ogg"},
  {(asset_id_t) SOUND1, "/home/orange/project-c/SaC2/samples/sound/sound01.ogg"}
};

}

