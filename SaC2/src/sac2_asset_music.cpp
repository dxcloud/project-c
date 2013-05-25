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
  if (false == m_loaded) {
    //m_filename = filename;
    if (false == m_asset.openFromFile(m_filename)) {
      return STATUS_MISS;
    }
    m_loaded = true;
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

}
