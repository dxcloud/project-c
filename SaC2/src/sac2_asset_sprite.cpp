#include "sac2_asset_sprite.hpp"

namespace sac2
{

sac2_status_t AssetSprite::load(const sf::Image& image)
{
  if (false == m_loaded) {
    m_asset.SetImage(image);
    m_loaded = true;
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

sac2_status_t AssetSprite::reset()
{
  m_asset.SetPosition(0.0F, 0.0F);
  m_asset.SetScale(1.0F, 1.0F);
  m_asset.SetRotation(0.0F);
  return STATUS_SUCCESS;
}

}
