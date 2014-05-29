#include <icelos_resource_manager.hpp>
#include <icelos_render_manager.hpp>

namespace icelos
{

const ResourceManager::resource_table_t ResourceManager::RESOURCE_TABLE =
{
  { 1, "button.png" },
  { 2, "roses_kingdom.ttf" }
};

ResourceManager::ResourceManager():
  Manager<ResourceManager>(),
  p_sdl_renderer(0),
  m_sdl_texture_map(),
  m_sdl_font_map()
{
  // nothing to do
}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::update()
{
  // nothing to do
}

// status_t ResourceManager::load(resource_id_t id, resource_type_t type)
// {
//   if (RESOURCE_TEXTURE == type) { return load_texture(id); }
//   else if (RESOURCE_FONT == type) { return load_font(id); }
//   return STATUS_CANCEL;
// }

status_t ResourceManager::load_texture(resource_id_t id)
{
  OUT("load texture")
  texture_map_t::const_iterator it(m_sdl_texture_map.find(id));
  if (m_sdl_texture_map.end() != it) {
    return STATUS_ALREADY;
  } // texture already loaded

  resource_table_t::const_iterator res_it(RESOURCE_TABLE.find(id));
  if (RESOURCE_TABLE.end() == res_it) {
    OUT("texture not found")
    return STATUS_MISS;
  } // texture id not found

  SDL_Surface* surface = IMG_Load((res_it->second).c_str());
  if (0 == surface) {
    OUT("suface fail")
    return STATUS_FAIL;
  }

  SDL_Texture* texture = SDL_CreateTextureFromSurface(p_sdl_renderer, surface);
  m_sdl_texture_map.insert(std::make_pair(id, texture));

  SDL_FreeSurface(surface);
  surface = 0;

  OUT("texture loaded")
  return STATUS_SUCCESS;
}

status_t ResourceManager::load_font(resource_id_t id, uint32_t font_size)
{
  font_map_t::const_iterator it(m_sdl_font_map.find(id));
  if (m_sdl_font_map.end() != it) {
    return STATUS_ALREADY;
  } // font already loaded

  resource_table_t::const_iterator res_it(RESOURCE_TABLE.find(id));
  if (RESOURCE_TABLE.end() == res_it) {
    OUT("font not found")
    return STATUS_MISS;
  } // font id not found

  TTF_Font* font(TTF_OpenFont((res_it->second).c_str(), font_size));
  if (0 == font) {
    std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
    return STATUS_FAIL;
  }
  m_sdl_font_map.insert(std::make_pair(id, font));
  return STATUS_SUCCESS;
}

SDL_Texture* ResourceManager::get_sdl_texture(resource_id_t id) const
{
//   OUT("get texture")
  texture_map_t::const_iterator it(m_sdl_texture_map.find(id));
  if (m_sdl_texture_map.end() != it) { return it->second; }
//   OUT("return 0")
  return 0; // texture not found
}

TTF_Font* ResourceManager::get_sdl_font(resource_id_t id) const
{
  OUT("get texture")
  font_map_t::const_iterator it(m_sdl_font_map.find(id));
  if (m_sdl_font_map.end() != it) { return it->second; }
  OUT("return 0")
  return 0; // texture not found
}

SDL_Texture* ResourceManager::get_sdl_font_texture(SDL_Surface* surface)
{
  return SDL_CreateTextureFromSurface(p_sdl_renderer, surface);
}

void ResourceManager::initialize()
{
  p_sdl_renderer = RenderManager::instance().p_sdl_renderer;
}

void ResourceManager::cleanup()
{
  for (texture_map_t::iterator it(m_sdl_texture_map.begin()); m_sdl_texture_map.end() != it; ++it) {
    SDL_DestroyTexture(it->second);
    it->second = 0;
    OUT("texture" << it->first << "destroyed")
  }
  m_sdl_texture_map.clear();

  for (font_map_t::iterator it(m_sdl_font_map.begin()); m_sdl_font_map.end() != it; ++it) {
    TTF_CloseFont(it->second);
    it->second = 0;
  }
  m_sdl_font_map.clear();
}


} // namespace icelos

