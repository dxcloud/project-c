#include "sac2_asset_buffer.hpp"

namespace sac2
{

status_t AssetBuffer::load()
{

    if (false == m_asset.loadFromFile(m_filename)) {
      return STATUS_FAIL;
    }
    return STATUS_SUCCESS;

}

}
