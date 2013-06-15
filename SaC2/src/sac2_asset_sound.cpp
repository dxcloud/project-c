#include "sac2_asset_sound.hpp"

namespace sac2
{

status_t AssetSound::play()
{
  m_asset.play();
  return STATUS_SUCCESS;
}

status_t AssetSound::pause()
{
  m_asset.pause();
  return STATUS_SUCCESS;
}

status_t AssetSound::stop()
{
  m_asset.stop();
  return STATUS_SUCCESS;
}

status_t AssetSound::load_sound(const sf::SoundBuffer& buffer)
{
    m_asset.setBuffer(buffer);
    return STATUS_SUCCESS;

}

}
