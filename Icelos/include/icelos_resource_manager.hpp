#ifndef ICELOS_RESOURCE_MANAGER_HPP
#define ICELOS_RESOURCE_MANAGER_HPP

#include <icelos_manager.hpp>

namespace icelos
{

class Text;

class Sprite;

class RenderManager;

class ResourceManager:
  public Manager<ResourceManager>
{
public:
  void update();
  status_t load_texture(resource_id_t id);
  status_t load_font(resource_id_t id, uint32_t font_size);

protected:
  void initialize();
  void cleanup();

private:
  ResourceManager();
  ~ResourceManager();
  ResourceManager(const ResourceManager&);
  ResourceManager& operator=(const ResourceManager&);

  SDL_Texture* get_sdl_texture(resource_id_t id) const;
  TTF_Font* get_sdl_font(resource_id_t id) const;
  SDL_Texture* get_sdl_font_texture(SDL_Surface* suface);

private:
  friend class Manager<ResourceManager>;
  friend class RenderManager;
  friend class Sprite;
  friend class Text;

private:
  typedef std::map<resource_id_t, SDL_Texture*>   texture_map_t;
  typedef std::map<resource_id_t, TTF_Font*>      font_map_t;
  typedef std::map<resource_id_t, const string_t> resource_table_t;


private:
  static const resource_table_t RESOURCE_TABLE;

private:
  SDL_Renderer*                 p_sdl_renderer;
  texture_map_t                 m_sdl_texture_map;
  font_map_t                    m_sdl_font_map;
};

}

#endif

