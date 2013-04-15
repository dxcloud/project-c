#include "sac2_asset_music.hpp"

namespace sac2
{

sac2_status_t AssetMusic::load_asset()
{
  if (false == m_load) {
    m_load = m_asset.OpenFromFile(m_filename);
    if (false == m_load) { return STATUS_FAIL; }  // if the loading failed
  }  // if the asset is NOT loaded yet
  return STATUS_SUCCESS;
}

sac2_status_t AssetMusic::delete_asset()
{
  if (true == m_load) {
    m_asset.Stop();
    m_load = false;
  }  // if the asset is loaded
  return STATUS_SUCCESS;
}

sac2_status_t AssetMusic::play_music(bool play)
{
  if (true == play) { m_asset.Play(); }
  else { m_asset.Stop(); }

  return STATUS_SUCCESS;
}

sac2_status_t AssetMusic::set_loop(bool loop)
{
  m_asset.SetLoop(loop);
  return STATUS_SUCCESS;
}


}
