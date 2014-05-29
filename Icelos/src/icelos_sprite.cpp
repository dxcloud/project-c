#include <icelos_sprite.hpp>
#include <icelos_resource_manager.hpp>
#include <icelos_render_manager.hpp>

namespace icelos
{

Sprite::Sprite():
  Graphics()
{
  // nothing to do
}

Sprite::~Sprite()
{
  // nothing to do
}

void Sprite::set_texture(resource_id_t id)
{
  p_sdl_texture = ResourceManager::instance().get_sdl_texture(id);
  SDL_QueryTexture(p_sdl_texture, 0, 0, &(m_sdl_src_rect.w), &(m_sdl_src_rect.h));
  m_sdl_dest_rect = m_sdl_src_rect;
}

}

