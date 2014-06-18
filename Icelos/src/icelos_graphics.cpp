#include <icelos_graphics.hpp>
#include <icelos_render_manager.hpp>
#include <icelos_math.hpp>

namespace icelos
{

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
Graphics::Graphics():
  p_sdl_texture(0),
  m_src_rect(),
  m_position(),
  m_size(),
  m_angle(math::cfloat::ZERO),
  m_center(),
  m_sdl_flip(SDL_FLIP_NONE)
{
  // nothing to do
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
Graphics::~Graphics()
{
  // nothing to do
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
const vector_t& Graphics::get_position() const
{
  return m_position;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
const vector_t& Graphics::get_size() const
{
  return m_size;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
float Graphics::get_rotation() const
{
  return m_angle;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
const rect_t& Graphics::get_rect() const
{
  return m_src_rect;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::set_position(int32_t x, int32_t y)
{
  m_position.x = x;
  m_position.y = y;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::set_position(const vector_t& position)
{
  set_position(position.x, position.y);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::set_size(int32_t w, int32_t h)
{
  m_size.w = (0 > w) ? 0 : w;
  m_size.h = (0 > h) ? 0 : h;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::set_size(const vector_t& size)
{
  set_size(size.w, size.h);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::set_rotation(float ang_deg, int32_t x, int32_t y)
{
  m_angle = math::cfloat::round_angle(ang_deg);
  m_center.x = x;
  m_center.y = y;
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::set_rotation(float ang_deg, const vector_t& center)
{
  set_rotation(ang_deg, center.x, center.y);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::set_rect(int32_t x, int32_t y, int32_t w, int32_t h, bool reset)
{
  m_src_rect.x = x;
  m_src_rect.y = y;
  m_src_rect.w = (0 > w) ? 0 : w;
  m_src_rect.h = (0 > h) ? 0 : h;


  if (true == reset) { reset_rect(); }
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::set_rect(const rect_t& rect, bool reset)
{
  set_rect(rect.x, rect.y, rect.w, rect.h, reset);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::move(int32_t x, int32_t y)
{
  set_position(m_position.x + x, m_position.y + y);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::move(const vector_t& distance)
{
  set_position(m_position.x + distance.x, m_position.y + distance.y);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::resize(int32_t w, int32_t h)
{
  set_size(m_size.w  + w, m_size.h + h);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::resize(const vector_t& size)
{
  set_size(m_size.w  + size.w, m_size.h + size.h);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::scale(float x, float y)
{
  set_size(m_size.w * x, m_size.h * y);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::scale(float factor)
{
  set_size(m_size.w * factor, m_size.w * factor);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::rotate(float ang_deg, int32_t x, int32_t y)
{
  set_rotation(m_angle + ang_deg, x, y);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::rotate(float ang_deg, const vector_t& center)
{
  set_rotation(m_angle + ang_deg, center.x, center.y);
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::flip(bool horizontal, bool vertical)
{
  if ((true == horizontal) and (false == vertical)) {
    m_sdl_flip = SDL_FLIP_HORIZONTAL;
  }
  else if ((false == horizontal) and (true == vertical)) {
    m_sdl_flip = SDL_FLIP_VERTICAL;
  }
  else if ((true == horizontal) && (true == vertical)) {
    m_sdl_flip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
  }
  else { m_sdl_flip = SDL_FLIP_NONE; }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::render()
{
  RenderManager::instance().draw(this);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Graphics::reset_rect()
{
  m_size.w = m_src_rect.w; // adjust size
  m_size.h = m_src_rect.h;
}

} // namespace icelos

