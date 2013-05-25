#include "sac2_asset_buffer.hpp"

namespace sac2
{

status_t AssetBuffer::load()
{
  if (false == m_loaded) {
    if (false == m_asset.loadFromFile(m_filename)) {
      return STATUS_FAIL;
    }
    m_loaded = true;
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

}
