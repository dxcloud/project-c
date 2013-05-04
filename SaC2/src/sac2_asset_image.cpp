﻿#include "sac2_asset_image.hpp"

namespace sac2
{

sac2_status_t AssetImage::load()
{
  if (false == m_loaded) {
    if (false == m_asset.LoadFromFile(m_filename)) {
      return STATUS_FAIL;
    }
    m_asset.SetSmooth(false);
    m_loaded = true;
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

}
