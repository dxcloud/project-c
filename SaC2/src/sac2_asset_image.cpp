#include "sac2_asset_image.hpp"

namespace sac2
{

sac2_status_t AssetImage::load_asset()
{
  if (false == m_load) {
    m_load = p_image->LoadFromFile(m_filename);
    if (false == m_load) { return STATUS_MISS; }
  }
  return STATUS_SUCCESS;
}

sac2_status_t AssetImage::delete_asset()
{
  if (true == m_load) {
    delete p_image;
    p_image = 0;
    m_load = false;
  }
  return STATUS_SUCCESS;
}

}