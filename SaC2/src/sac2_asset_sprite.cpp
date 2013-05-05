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

}
