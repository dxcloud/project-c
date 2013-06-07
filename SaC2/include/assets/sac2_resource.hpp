/*!
 * \file    sac2_resource.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013 - 04 -20
 * \brief   Allows to access resource by \b Identifier
 */

#ifndef SAC2_RESOURCE_HPP
#define SAC2_RESOURCE_HPP

#include <map>
#include <string>

#include <sac2_type.hpp>
#include <sac2_logger.hpp>

namespace sac2
{

class AssetManager;

enum {
  IMAGE_01 = 0x0001,
  IMAGE_02 = 0x0002
};

/*!
 * \class   Resource
 * \brief   Associates a resource name with an \b Identifier
 * \details This class is only used by AssetManager
 */
class Resource {
public:
  friend class AssetManager;

private:
  /*!
   * \brief Private default constructor
   */
  Resource();

  /*!
   * \brief Private default destructor
   */
  ~Resource();

  /**!
   * \brief
   */
//  status_t create(const std::string& filename);

//  const std::string& operator()(sac2_asset_type_t type, const sac2_asset_id_t& id) const;

//  status_t set_font(const sac2_asset_id_t& id, const std::string& filepath);
//  status_t set_texture(asset_id_t& id, const std::string& filepath);
//  status_t set_music(const sac2_asset_id_t& id, const std::string& filepath);
//  status_t set_sound(const sac2_asset_id_t& id, const std::string& filepath);

private:
  /*!
   * \brief Private copy constructor
   */
  Resource(const Resource&);

  /*!
   * \brief Private assignement operator
   */
  Resource& operator=(const Resource&);

  /*!
   * \brief Initialize static attribute \b m_textures
   */
  static asset_map_t set_texture_map();

private:
  static const std::string m_res_path;
//  sac2_asset_map_t m_fonts;   //!< Font type resource name
  static asset_map_t m_textures;  //!< Image type resource name
//  sac2_asset_map_t m_musics;  //!< Music type resource name
//  sac2_asset_map_t m_sounds;  //!< Sound type resource name
};  // class Resource

//! Constant iterator for \b Res
typedef asset_map_t::iterator resource_it;
typedef asset_map_t::const_iterator resource_const_it;

//----------------------------------------------------------------------------
//  Ressource::Resource
//----------------------------------------------------------------------------
inline Resource::Resource()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Resource::constructor - successfully created");
#endif
}

//----------------------------------------------------------------------------
//  Ressource::~Resource
//----------------------------------------------------------------------------
inline Resource::~Resource()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Resource::destructor - successfully destroyed");
#endif
}

}  // namespace sac2

#endif  //! SAC2_RESOURCE_HPP
