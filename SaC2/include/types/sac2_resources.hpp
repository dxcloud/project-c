/*!
 * \file    sac2_resources.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013 - 04 -20
 * \brief   Allows to access resource by \b Identifier
 * \details \b Res is defined as a \b static \b struct
 */

#ifndef SAC2_RESOURCES_HPP
#define SAC2_RESOURCES_HPP

#include <map>
#include <string>

#include "sac2_type.hpp"


class AssetManager;

namespace sac2
{

//! Associates a resource name with an \b Identifier
class Resource {
  friend class AssetManager;

public:
  /*!
   * \brief
   */
  Resource();

  /*!
   * \brief
   */
  ~Resource();

  /**!
   * \brief
   */
  status_t create(const std::string& filename);

  const std::string& operator()(sac2_asset_type_t type, const sac2_asset_id_t& id) const;

  status_t set_font(const sac2_asset_id_t& id, const std::string& filepath);
  status_t set_image(const sac2_asset_id_t& id, const std::string& filepath);
  status_t set_music(const sac2_asset_id_t& id, const std::string& filepath);
  status_t set_sound(const sac2_asset_id_t& id, const std::string& filepath);

private:
  Resource(const Resource&);
  Resource& operator=(const Resource&);

  sac2_asset_map_t m_fonts;   //!< Font type resource name
  sac2_asset_map_t m_images;  //!< Image type resource name
  sac2_asset_map_t m_musics;  //!< Music type resource name
  sac2_asset_map_t m_sounds;  //!< Sound type resource name
};

//! Constant iterator for \b Res
typedef sac2_asset_map_t::iterator sac2_resource_it;
typedef sac2_asset_map_t::const_iterator sac2_resource_const_it;

inline Resource::Resource()
{

}

inline Resource::~Resource()
{
  
}

}  //! namespace sac2

#endif  //! SAC2_RESOURCES_HPP
