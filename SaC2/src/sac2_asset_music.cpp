#include "sac2_asset_music.hpp"

namespace sac2
{

status_t AssetMusic::play()
{
  m_asset.play();
  return STATUS_SUCCESS;
}

status_t AssetMusic::pause()
{
  m_asset.pause();
  return STATUS_SUCCESS;
}

status_t AssetMusic::stop()
{
  m_asset.stop();
  return STATUS_SUCCESS;
}

status_t AssetMusic::set_loop(bool loop)
{
  m_asset.setLoop(loop);
  return STATUS_SUCCESS;
}

status_t AssetMusic::load(const std::string& filename)
{
  if (false == m_asset.openFromFile(filename)) {
    return STATUS_FAIL;
  }
  return STATUS_SUCCESS;
}

}
