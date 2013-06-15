#include "sac2_asset_image.hpp"

namespace sac2
{

status_t AssetImage::load()
{
/*  if (false == m_loaded) {
    if (false == m_asset.LoadFromFile(m_filename)) {
      return STATUS_FAIL;
    }
    m_asset.SetSmooth(false);
    m_loaded = true;
    return STATUS_SUCCESS;
  }
*/
  return STATUS_ALREADY;

}

status_t AssetImage::load(const std::string& filename)
{
    if (false == m_asset.loadFromFile(filename)) {
      return STATUS_FAIL;
    }
    return STATUS_SUCCESS;
}

}
