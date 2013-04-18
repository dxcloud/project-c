#include "sac2_asset_image.hpp"

namespace sac2
{

sac2_status_t AssetImage::load_asset()
{
  if (false == m_load) {
    m_load = m_asset.LoadFromFile(m_filename);
    if (false == m_load) { return STATUS_FAIL; }
  }
  return STATUS_SUCCESS;
}

sac2_status_t AssetImage::delete_asset()
{
  p_asset_manager->delete_asset(ASSET_IMAGE, m_filename);
  return STATUS_SUCCESS;
}

}
