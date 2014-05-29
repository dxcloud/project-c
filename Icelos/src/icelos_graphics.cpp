#include <icelos_graphics.hpp>
#include <icelos_render_manager.hpp>

namespace icelos
{

ivector_t Graphics::get_position() const
{
  return ivector_t(m_sdl_dest_rect.x, m_sdl_dest_rect.y);
}

ivector_t Graphics::get_scale() const
{
  return ivector_t(m_sdl_dest_rect.w, m_sdl_dest_rect.h);
}

void Graphics::set_position(int32_t x, int32_t y)
{
  m_sdl_dest_rect.x = x;
  m_sdl_dest_rect.y = y;
}


void Graphics::set_position(ivector_t position)
{
  m_sdl_dest_rect.x = position.x;
  m_sdl_dest_rect.y = position.y;
}

void Graphics::set_scale(int32_t x, int32_t y)
{
  m_sdl_dest_rect.w = x;
  m_sdl_dest_rect.h = y;
}

void Graphics::set_scale(ivector_t scale)
{
  m_sdl_dest_rect.w = scale.x;
  m_sdl_dest_rect.h = scale.y;
}

void Graphics::move(int32_t x, int32_t y)
{
  m_sdl_dest_rect.x += x;
  m_sdl_dest_rect.y += y;
}

void Graphics::move(ivector_t offset)
{
  m_sdl_dest_rect.x += offset.x;
  m_sdl_dest_rect.y += offset.y;
}

void Graphics::scale(int32_t x, int32_t y)
{
  m_sdl_dest_rect.w += x;
  m_sdl_dest_rect.h += y;
}

void Graphics::scale(ivector_t factor)
{
  m_sdl_dest_rect.x += factor.x;
  m_sdl_dest_rect.y += factor.y;
}

void Graphics::render()
{
  RenderManager::instance().add_graphics(this);
}



} // namespace icelos

