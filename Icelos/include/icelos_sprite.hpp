////////////////////////////////////////////////////////////////////////////////
/// @file    icelos_graphics.hpp
/// @brief   Provides Icelos color manipulation class.
/// @date    2014-05-28
/// @version 0.1 (alpha)
/// @author  Chengwu Huang <chengwhuang@gmail.com>
////////////////////////////////////////////////////////////////////////////////
#ifndef ICELOS_SPRITE_HPP
#define ICELOS_SPRITE_HPP

#include <icelos_graphics.hpp>

namespace icelos
{

class Sprite: public Graphics
{
public:
  Sprite();
  ~Sprite();
  void set_texture(resource_id_t id);

private:
  friend class Renderer;
}; // class Sprite

} // namespace icelos

#endif // ICELOS_SPRITE_HPP

