﻿#ifndef _ASSET_HPP_
#define _ASSET_HPP_

#include <string>

#include "sac2_type.hpp"

namespace sac2
{

class Asset
{
 public:
  Asset(const std::string& filename):
    m_filename(filename)
  {}
  
  virtual ~Asset() {}
  
  bool is_loaded() const { return m_loaded; }

  virtual sac2_status_t load_asset() = 0;
 protected:

  sac2_asset_type m_type;

  const std::string m_filename;

  bool m_loaded;

 private:
};  // class Asset

};

#endif //!_ASSET_HPP_