#include <icelos_text.hpp>
#include <icelos_resource_manager.hpp>

namespace icelos
{

Text::Text():
  Graphics()
{
  m_color = color::WHITE;
}


Text::Text(const string_t text):
  Graphics(),
  m_text(text)
{

}

Text::~Text()
{
  cleanup();
}

void Text::cleanup()
{
  if (0 != p_sdl_texture) {
    SDL_DestroyTexture(p_sdl_texture);
    p_sdl_texture = 0;
  }
}


void Text::set_font(resource_id_t id)
{
  p_sdl_font = ResourceManager::instance().get_sdl_font(id);
  update();
}

// void Text::set_size(size_t size)
// {
// 
// }

void Text::update()
{
  cleanup();
  SDL_Surface* surface = TTF_RenderText_Solid(p_sdl_font,
                                              m_text.c_str(),
                                              m_color.color);
//   p_sdl_texture = SDL_CreateTextureFromSurface(ResourceManager::instance().p_sdl_renderer, surface);
  p_sdl_texture = ResourceManager::instance().get_sdl_font_texture(surface);
  SDL_FreeSurface(surface);
  SDL_QueryTexture(p_sdl_texture, 0, 0, &(m_sdl_src_rect.w), &(m_sdl_src_rect.h));
  m_sdl_dest_rect = m_sdl_src_rect;
}

const string_t& Text::get_text() const
{
  return m_text;
}

void Text::set_text(const string_t& text)
{
  m_text = text;
  update();
}

} // namespace icelos

