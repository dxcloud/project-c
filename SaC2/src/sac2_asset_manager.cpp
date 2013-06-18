#include <SFML/Graphics.hpp>

#include "sac2_asset.hpp"
#include <sac2_asset_manager.hpp>
#include "sac2_asset_buffer.hpp"
#include "sac2_asset_font.hpp"
#include "sac2_asset_music.hpp"
#include "sac2_asset_sound.hpp"
#include <sac2_asset_sprite.hpp>
#include "sac2_asset_text.hpp"

namespace sac2
{

//----------------------------------------------------------------------------
//  AssetManager::AssetManager
//----------------------------------------------------------------------------
AssetManager::AssetManager():
  Manager<AssetManager>(),
  m_font_map(),
  m_sound_map(),
  m_texture_map()
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

status_t AssetManager::get_music(asset_id_t id, AssetMusic& music)
{
  asset_const_iter_t res_iter(m_asset_table.find(id));
  if (m_asset_table.end() == res_iter) { return STATUS_MISS; }
  return music.load(res_iter->second);
}

//----------------------------------------------------------------------------
//  AssetManager::get_sprite
//----------------------------------------------------------------------------
status_t AssetManager::get_sprite(asset_id_t id, AssetSprite& sprite)
{
  return get_asset<texture_map_t,
                   texture_iter_t,
                   sf::Texture,
                   AssetSprite>(id, sprite, m_texture_map);
}

//----------------------------------------------------------------------------
//  AssetManager::get_sound
//----------------------------------------------------------------------------
status_t AssetManager::get_sound(asset_id_t id, AssetSound& sound)
{
  return get_asset<sound_map_t,
                   sound_iter_t,
                   sf::SoundBuffer,
                   AssetSound>(id, sound, m_sound_map);
}

//----------------------------------------------------------------------------
//  AssetManager::cleanup
//----------------------------------------------------------------------------
void AssetManager::cleanup()
{
  for (texture_iter_t iter(m_texture_map.begin()); iter != m_texture_map.end(); ++iter) {
    delete iter->second;
    iter->second = 0;
  }
  m_texture_map.clear();
}

//----------------------------------------------------------------------------
//  AssetManager::load_texture
//----------------------------------------------------------------------------
status_t AssetManager::load_texture(asset_id_t id)
{
  return load_asset<texture_map_t, sf::Texture>(id, m_texture_map);
}

//----------------------------------------------------------------------------
//  AssetManager::load_sound
//----------------------------------------------------------------------------
status_t AssetManager::load_sound(asset_id_t id)
{
  return load_asset<sound_map_t, sf::SoundBuffer>(id, m_sound_map);
}

//----------------------------------------------------------------------------
//  AssetManager::unload_texture
//----------------------------------------------------------------------------
status_t AssetManager::unload_texture(asset_id_t id)
{
  return unload_asset<texture_map_t, texture_iter_t>(id, m_texture_map);
}

//----------------------------------------------------------------------------
//  AssetManager::update
//----------------------------------------------------------------------------
void AssetManager::update() {

}

}  // namespace sac2
