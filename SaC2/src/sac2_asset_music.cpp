#include "sac2_asset_music.hpp"

namespace sac2
{

sac2_status_t AssetMusic::load_asset()
{
  if (false == m_loaded) {
    m_loaded = p_music->OpenFromFile(m_filename);

    if (false == m_loaded) return STATUS_MISS;  // if the loading failed
  }  // if the asset is NOT loaded yet
  return STATUS_SUCCESS;
}

sac2_status_t AssetMusic::delete_asset()
{
  if (true == m_loaded) {
    p_music->Stop();
    delete p_music;
    p_music = 0;
    m_loaded = false;
  }  // if the asset is loaded
  return STATUS_SUCCESS;
}

sac2_status_t AssetMusic::play_music(bool play)
{
  if (true == play) p_music->Play();
  else p_music->Stop();

  return STATUS_SUCCESS;
}

sac2_status_t AssetMusic::set_loop(bool loop)
{
  p_music->SetLoop(loop);
  return STATUS_SUCCESS;
}


}