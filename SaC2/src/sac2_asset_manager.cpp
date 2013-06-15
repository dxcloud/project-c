#include <SFML/Graphics.hpp>

#include "sac2_asset.hpp"
#include "sac2_asset_manager.hpp"
#include "sac2_asset_buffer.hpp"
#include "sac2_asset_font.hpp"
#include "sac2_asset_image.hpp"
#include "sac2_asset_music.hpp"
#include "sac2_asset_sound.hpp"
#include <sac2_asset_sprite.hpp>
#include "sac2_asset_text.hpp"
#include <sac2_texture.hpp>

namespace sac2
{

//----------------------------------------------------------------------------
//  AssetManager::AssetManager
//----------------------------------------------------------------------------
AssetManager::AssetManager():
  Manager<AssetManager>(),
  m_asset_table(),
  m_textures()
{
  Manager<AssetManager>::initialize();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("AssetManager::constructor - succesfully initialized");
#endif
}

//----------------------------------------------------------------------------
//  AssetManager::~AssetManager
//----------------------------------------------------------------------------
AssetManager::~AssetManager()
{
  cleanup();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("AssetManager::destructor - succesfully destroyed");
#endif
}

//----------------------------------------------------------------------------
//  AssetManager::cleanup
//----------------------------------------------------------------------------
void AssetManager::cleanup()
{
  for (texture_iter_t iter(m_textures.begin()); iter != m_textures.end(); ++iter) {
    delete iter->second;
    iter->second = 0;
  }
  m_textures.clear();
}

//----------------------------------------------------------------------------
//  AssetManager::load_sprite
//----------------------------------------------------------------------------
/*
status_t AssetManager::load_sprite(AssetSprite& sprite, asset_id_t id)
{
  texture_iter_t iter(m_textures.find(id));
  Logger::log_debug("texture iter try to find");
  if (m_textures.end() == iter) {
    Logger::log_debug("...not found");
    resource_it res_iter(m_resource.m_table.find(id));
    Logger::log_debug("resource iter try to find");
    if (m_resource.m_table.end() == res_iter) { return STATUS_MISS; }
    sf::Texture* texture(new sf::Texture);
    Logger::log_debug("new texture");
    if (false == texture->loadFromFile(res_iter->second)) {
      Logger::log_error("error loading");
      delete texture;
      return STATUS_ERROR;
    }
    m_textures.insert(std::make_pair(id, texture));
  }  // if NOT found
  sprite.load(*m_textures[id]);
  return STATUS_SUCCESS;
}
*/

//----------------------------------------------------------------------------
//  AssetManager::load_texture
//----------------------------------------------------------------------------
status_t AssetManager::load_texture(asset_id_t id)
{
  resource_iter_t res_iter(m_asset_table.m_table.find(id));
  if (m_asset_table.m_table.end() == res_iter) { return STATUS_MISS; }
  sf::Texture* texture(new sf::Texture);
  if (false == texture->loadFromFile(res_iter->second)) {
    delete texture;
    return STATUS_FAIL;
  }
  m_textures.insert(std::make_pair(id, texture));
  return STATUS_SUCCESS;
}

//----------------------------------------------------------------------------
//  AssetManager::unload_texture
//----------------------------------------------------------------------------
status_t AssetManager::unload_texture(asset_id_t id)
{
  texture_iter_t texture_iter(m_textures.find(id));
  if (m_textures.end() == texture_iter) { return STATUS_CANCEL; }
  delete texture_iter->second;
  texture_iter->second = 0;
  m_textures.erase(texture_iter);
  return STATUS_SUCCESS;
}

//----------------------------------------------------------------------------
//  AssetManager::get_sprite
//----------------------------------------------------------------------------
status_t AssetManager::get_sprite(AssetSprite& sprite, asset_id_t id)
{
  texture_iter_t texture_iter(m_textures.find(id));
  if (m_textures.end() == texture_iter) {
    if (STATUS_SUCCESS != load_texture(id)) {
      return STATUS_ERROR;
    }
  }
  sprite.load(*(m_textures[id]));
  return STATUS_SUCCESS;
}


void AssetManager::update() {

}
/*
AssetSprite* AssetManager::get_sprite(asset_id_t id)
{
  texture_iter_t iter(m_textures.find(id));
  if (m_textures.end() == iter) {
    resource_it res_iter(AssetTable::m_table.find(id));
    if (m_resource.m_table.end() == res_iter) { return 0; }
    m_textures[id] = new sf::Texture;
    m_textures[id]->loadFromFile(res_iter->second);
  }
  AssetSprite *sprite(new AssetSprite);
  sprite->load(*(m_textures[id]));
  return sprite;
}
*/
/*
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

void AssetManager::initialize()
{

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

  m_initialized = true;
}

void AssetManager::load_image(const sac2_asset_id_t& id)
{
  asset_image_it iter = m_images.find(id);
  if (m_images.end() == iter) {
    m_images.insert(std::make_pair(iter->first, new AssetImage));
  }
}

void AssetManager::update() {

}

void AssetManager::load_sprite(const sac2_asset_id_t& id)
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
