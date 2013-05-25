#include "sac2_resources.hpp"

namespace sac2 {

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
  m_images.insert(std::make_pair(id, filepath));
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

}
