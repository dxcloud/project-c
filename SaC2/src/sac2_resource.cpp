//#ifdef USE_SAC2_DEFAULT_RESOURCE

#include "sac2_resource.hpp"

namespace sac2 {

#ifdef RESOURCE_PATH
const std::string Resource::m_res_path(RESOURCE_PATH);
#else
const std::string Resource::m_res_path(".");
#endif

//----------------------------------------------------------------------------
//  Ressource::m_textures
//----------------------------------------------------------------------------
asset_map_t Resource::m_textures(set_texture_map());

//----------------------------------------------------------------------------
//  Ressource::set_texture_map
//----------------------------------------------------------------------------
asset_map_t Resource::set_texture_map()
{
  asset_map_t texture_map;
  texture_map.insert(std::make_pair(static_cast<asset_id_t>(IMAGE_01),
                                    m_res_path + "/image/image01.png"));
  texture_map.insert(std::make_pair(static_cast<asset_id_t>(IMAGE_02),
                                    m_res_path + "/image/image02.png"));
  return texture_map;
}
/*
status_t Resource::create(const std::string& filename)
{
  return STATUS_SUCCESS;
}

status_t Resource::set_font(const sac2_asset_id_t& id,
                                     const std::string& filepath)
{
  m_fonts.insert(std::make_pair(id, filepath));
  return STATUS_SUCCESS;
}

status_t Resource::set_image(const sac2_asset_id_t& id,
                                     const std::string& filepath)
{
  m_textures.insert(std::make_pair(id, filepath));
  return STATUS_SUCCESS;
}

status_t Resource::set_music(const sac2_asset_id_t& id,
                                     const std::string& filepath)
{
  m_musics.insert(std::make_pair(id, filepath));
  return STATUS_SUCCESS;
}

status_t Resource::set_sound(const sac2_asset_id_t& id,
                                     const std::string& filepath)
{
  m_sounds.insert(std::make_pair(id, filepath));
  return STATUS_SUCCESS;
}

const std::string& Resource::operator()(sac2_asset_type_t type,
                                        const sac2_asset_id_t& id) const
{
  sac2_resource_const_it iter;
  if (ASSET_FONT == type) { iter = m_fonts.find(id); }
  else if (ASSET_IMAGE == type) { iter = m_images.find(id); }
  else if (ASSET_MUSIC == type) { iter = m_musics.find(id); }
  else if (ASSET_SOUND == type) { iter = m_sounds.find(id); }
  return const_cast<std::string&>(iter->second);
}
*/
}

//#endif
