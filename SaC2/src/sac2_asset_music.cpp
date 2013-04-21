#include "sac2_asset_music.hpp"

namespace sac2
{

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
