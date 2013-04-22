﻿#include <SFML/Graphics.hpp>

#include "sac2_asset.hpp"
#include "sac2_asset_manager.hpp"
#include "sac2_asset_image.hpp"
#include "sac2_asset_music.hpp"
#include "sac2_asset_sound.hpp"
#include "sac2_asset_sprite.hpp"

namespace sac2
{

AssetImage* AssetManager::get_asset(sac2_asset_type_t type,
                               const sac2_asset_id_t& id) const
{
  if (ASSET_IMAGE == type) {
    std::map<sac2_asset_id_t, AssetImage*>::const_iterator iter;
    iter = m_images.find(id);
    if (m_images.end() != iter) {
      return iter->second;
    }
  }
  // TODO implement get_asset() for other type of asset
  return 0;
}


sac2_status_t AssetManager::add_asset(sac2_asset_type_t type,
                                      const sac2_asset_id_t& id)
{
  if (ASSET_IMAGE == type) {
    std::map<sac2_asset_id_t, AssetImage*>::iterator iter;
    iter = m_images.find(id);
    if (m_images.end() == iter) {
      AssetImage* image(new AssetImage(id));
//      if (STATUS_SUCCESS != image->load_asset()) { return STATUS_MISS; }
      m_images.insert(std::pair<sac2_asset_id_t, AssetImage*>(id, image));
      return STATUS_SUCCESS;
    }
    else { return STATUS_ALREADY; }
  }
  return STATUS_INVAL;
  // TODO implement add_asset() for other type of asset
}

sac2_status_t AssetManager::load_asset(sac2_asset_type_t type)
{
  return STATUS_SUCCESS;
}

sac2_status_t AssetManager::delete_asset(sac2_asset_type_t type,
                                         const sac2_asset_id_t& id)
{
  return STATUS_SUCCESS;
}

sac2_status_t AssetManager::load_sprite(AssetSprite& sprite,
                                        const sac2_asset_id_t& id)
{
  std::map<sac2_asset_id_t, AssetImage*>::iterator iter;
  iter = m_images.find(id);
  if (m_images.end() == iter) { return STATUS_MISS; }  // if NOT found
  iter->second->load();
  sprite.load(iter->second->get_asset());
  return STATUS_SUCCESS;
}

sac2_status_t AssetManager::initialize()
{
  if (true == m_initialized) {
    return STATUS_ALREADY;
  }  // if already initialized

  for (sac2_res_it iter = Res::image.begin();
       iter != Res::image.end();
       ++iter) {
    m_images.insert(std::make_pair(iter->first,
                                   new AssetImage(iter->second)));
  }  // add resource
  m_initialized = true;
  return STATUS_SUCCESS;
}

}  // namespace sac2
