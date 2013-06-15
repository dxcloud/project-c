#include "sac2_asset_font.hpp"

namespace sac2
{

status_t AssetFont::load()
{
    if (false == m_asset.loadFromFile(m_filename)) {
      return STATUS_FAIL;
    }
    return STATUS_SUCCESS;
}

}
