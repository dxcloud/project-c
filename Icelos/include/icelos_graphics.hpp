////////////////////////////////////////////////////////////////////////////////
/// @file    icelos_graphics.hpp
/// @brief   Prodives interface for graphics element.
/// @date    2014-05-17
/// @version 0.1 (alpha)
/// @author  Chengwu Huang <chengwhuang@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef ICELOS_GRAPHICS_HPP
#define ICELOS_GRAPHICS_HPP

// icelos include
#include <icelos_type.hpp>

namespace icelos
{

class RenderManager;

////////////////////////////////////////////////////////////////////////////////
/// @class   Graphics
/// @brief   Base class for any graphics element.
////////////////////////////////////////////////////////////////////////////////
class Graphics
{
public:
  ivector_t get_position() const;
  ivector_t get_scale() const;
  void set_position(int32_t x, int32_t y);
  void set_position(ivector_t position);
  void set_scale(int32_t x, int32_t y);
  void set_scale(ivector_t scale);
  void move(int32_t x, int32_t y);
  void move(ivector_t offset);
  void scale(int32_t x, int32_t y);
  void scale(ivector_t factor);
  void render();

protected:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public virtual constructor.
  //////////////////////////////////////////////////////////////////////////////
  Graphics();

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public virtual constructor.
  //////////////////////////////////////////////////////////////////////////////
  virtual ~Graphics();

protected:
  SDL_Texture* p_sdl_texture;
  SDL_Rect     m_sdl_src_rect;
  SDL_Rect     m_sdl_dest_rect;

private:
//   friend class Renderer;
//   friend class RenderWindow;
  friend class RenderManager;
};

inline Graphics::Graphics():
  p_sdl_texture(0),
  m_sdl_src_rect(),
  m_sdl_dest_rect()
{
  // nothing to do
}

inline Graphics::~Graphics()
{
  // nothing to do
}

}

#endif /// ICELOS_GRAPHICS_HPP

