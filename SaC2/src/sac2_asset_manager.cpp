#include <SFML/Graphics.hpp>

#include "sac2_asset.hpp"
#include "sac2_asset_manager.hpp"
#include "sac2_asset_buffer.hpp"
#include "sac2_asset_font.hpp"
#include "sac2_asset_image.hpp"
#include "sac2_asset_music.hpp"
#include "sac2_asset_sound.hpp"
#include "sac2_asset_sprite.hpp"
#include "sac2_asset_text.hpp"

namespace sac2
{

status_t AssetManager::get_sprite(AssetSprite& sprite, const sac2_asset_id_t& id)
{
  asset_image_it iter = m_images.find(id);

  if (m_images.end() == iter) {
    AssetImage* image = new AssetImage;
    image->load(m_resource(ASSET_IMAGE, id));
    m_images.insert(std::make_pair(iter->first, image));
    sprite.load(iter->second->get_asset());
    return STATUS_MISS;
  }  // if NOT found
  iter->second->load();
  sprite.load(iter->second->get_asset());
  return STATUS_SUCCESS;
}
/*
status_t AssetManager::add_asset(sac2_asset_type_t type,
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

status_t AssetManager::load_asset(sac2_asset_type_t type)
{
  return STATUS_SUCCESS;
}

status_t AssetManager::delete_asset(sac2_asset_type_t type,
                                         const sac2_asset_id_t& id)
{
  return STATUS_SUCCESS;
}

status_t AssetManager::load_sprite(AssetSprite& sprite,
                                        const sac2_asset_id_t& id)
{
  std::map<sac2_asset_id_t, AssetImage*>::iterator iter;
  iter = m_images.find(id);
  if (m_images.end() == iter) { return STATUS_MISS; }  // if NOT found
  iter->second->load();
  sprite.load(iter->second->get_asset());
  return STATUS_SUCCESS;
}

status_t AssetManager::load_font(AssetText& text,
                                      const sac2_asset_id_t& id)
{
  std::map<sac2_asset_id_t, AssetFont*>::iterator iter;
  iter = m_fonts.find(id);
  if (m_fonts.end() == iter) { return STATUS_MISS; }  // if NOT found
  iter->second->load();
  text.set_font(iter->second->get_asset());
  return STATUS_SUCCESS;
}

status_t AssetManager::load_sound(AssetSound& sound,
                                       const sac2_asset_id_t& id)
{
  std::map<sac2_asset_id_t, AssetBuffer*>::iterator iter;
  iter = m_sounds.find(id);
  if (m_sounds.end() == iter) { return STATUS_MISS; }
  iter->second->load();
  sound.load_sound(iter->second->get_asset());
  return STATUS_SUCCESS;
}

status_t AssetManager::load_music(AssetMusic& music,
                                       const sac2_asset_id_t& id)
{
  std::map<sac2_asset_id_t, AssetMusic*>::iterator iter;
  iter = m_musics.find(id);
  if (m_musics.end() == iter) { return STATUS_MISS; }
//  iter->second->load();
//  music.load(iter->second->get_asset());
  return STATUS_SUCCESS;
}
*/
status_t AssetManager::initialize()
{
/*
  if (true == m_initialized) {
    return STATUS_ALREADY;
  }  // if already initialized

  for (sac2_res_it iter = Res::image.begin();
       iter != Res::image.end();
       ++iter) {
    m_images.insert(std::make_pair(iter->first,
                                   new AssetImage(iter->second)));
  }  // add image type resource

  for (sac2_res_it iter = Res::font.begin();
       iter != Res::font.end();
       ++iter) {
    m_fonts.insert(std::make_pair(iter->first,
                                   new AssetFont(iter->second)));
  }  // add font type resource

  for (sac2_res_it iter = Res::sound.begin();
       iter != Res::sound.end();
       ++iter) {
    m_sounds.insert(std::make_pair(iter->first,
                                   new AssetBuffer(iter->second)));
  }

  for (sac2_res_it iter = Res::music.begin();
       iter != Res::music.end();
       ++iter) {
    m_musics.insert(std::make_pair(iter->first,
                                   new AssetMusic(iter->second)));
  }
*/
  m_initialized = true;
  return STATUS_SUCCESS;
}

void AssetManager::load_image(const sac2_asset_id_t& id)
{
  asset_image_it iter = m_images.find(id);
  if (m_images.end() == iter) {
    m_images.insert(std::make_pair(iter->first, new AssetImage));
  }
}

status_t AssetManager::update() {}

/*void AssetManager::load_sprite(const sac2_asset_id_t& id)
{
  asset_sprite_it iter = m_sprites.find(id);
  if (m_sprites.end() == iter) {
    sac2_asset_map_t res_it = m_resource.m_images.find(id);
    if (m_resource.m_images.end() != res_it) {
      m_sprites.insert(std::make_pair(id, new AssetSprite()));
    }
  }  // if the sprite is NOT loaded yet
}
*/
}  // namespace sac2
