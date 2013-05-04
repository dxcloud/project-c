#include "sac2_asset_font.hpp"

namespace sac2
{

sac2_status_t AssetFont::load()
{
  if (false == m_loaded) {
    if (false == m_asset.LoadFromFile(m_filename)) {
      return STATUS_FAIL;
    }
    m_loaded = true;
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

}
