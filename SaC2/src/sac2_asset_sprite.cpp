#include "sac2_asset_sprite.hpp"

namespace sac2
{

sac2_status_t AssetSprite::load_asset()
{
  if ((false == m_load) && (0 != p_image)) {
    m_asset.SetImage(p_image->get_asset());
    m_load = true;
    return STATUS_SUCCESS;
  }
  return STATUS_FAIL;
}

sac2_status_t AssetSprite::delete_asset()
{
  p_image = 0;
  m_load = false;
  p_asset_manager->delete_asset(ASSET_SPRITE, m_filename);
  return STATUS_SUCCESS;
}

}
