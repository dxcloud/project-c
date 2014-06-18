////////////////////////////////////////////////////////////////////////////////
/// @file    icelos_graphics.hpp
/// @brief   Prodives interface for graphics element manipulation.
/// @date    2014-05-17
/// @version 0.1 (alpha)
/// @author  Chengwu Huang <chengwhuang@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef ICELOS_GRAPHICS_HPP
#define ICELOS_GRAPHICS_HPP

// icelos include
#include <icelos_type.hpp>
#include <icelos_function.hpp>

namespace icelos
{

class RenderManager;

////////////////////////////////////////////////////////////////////////////////
/// @class   Graphics
/// @brief   Base class for any graphics element.
/// @details
///   A graphics element is any object that can be rendered to a render target.
///   
////////////////////////////////////////////////////////////////////////////////
class Graphics
{
public:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief Get the current position of the object.
  /// @return
  ///   Coordinates of the current position.
  //////////////////////////////////////////////////////////////////////////////
  const vector_t& get_position() const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Get the current size of the object.
  /// @return
  ///   Size of the object.
  //////////////////////////////////////////////////////////////////////////////
  const vector_t& get_size() const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Get the angle of the rotation.
  /// @return
  ///   Angle of the rotation in degrees.
  //////////////////////////////////////////////////////////////////////////////
  float get_rotation() const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Get the source rectangle.
  /// @return
  ///   Source rectangle that defines the area of the texture to rendered.
  //////////////////////////////////////////////////////////////////////////////
  const rect_t& get_rect() const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Set the position of the object.
  /// @param[in] x
  ///   New coordinate x of the object.
  /// @param[in] y
  ///   New coordinate y of the object.
  //////////////////////////////////////////////////////////////////////////////
  void set_position(int32_t x, int32_t y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Set the position of the object.
  /// @param[in] position
  ///   New position of the object.
  //////////////////////////////////////////////////////////////////////////////
  void set_position(const vector_t& position);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Set the size of the object.
  /// @param[in] w
  ///   New width of the object.
  /// @param[in] h
  ///   New height of the object.
  //////////////////////////////////////////////////////////////////////////////
  void set_size(int32_t w, int32_t h);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Set the size of the object.
  /// @param[in] size
  ///   New size of the object.
  //////////////////////////////////////////////////////////////////////////////
  void set_size(const vector_t& size);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Set the orientation of the element.
  /// @param[in] ang_deg
  ///   Angle of rotation in degrees.
  /// @param[in] x
  ///   Coordinate x of the center of the rotation.
  /// @param[in] y
  ///   Coordinate y of the center of the rotation.
  //////////////////////////////////////////////////////////////////////////////
  void set_rotation(float ang_deg, int32_t x, int32_t y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Set the orientation of the element.
  /// @param[in] ang_deg
  ///   Angle of rotation in degrees.
  /// @param[in] center
  ///   Center of the rotation.
  //////////////////////////////////////////////////////////////////////////////
  void set_rotation(float ang_deg, const vector_t& center);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Set the area of the texture to be rendered.
  /// @param[in] x
  ///   New coordinate x of the source rectangle.
  /// @param[in] y
  ///   New coordinate y of the source rectangle.
  /// @param[in] w
  ///   New width of the source rectangle.
  /// @param[in] h
  ///   New height of the source rectangle.
  /// @param[in] reset
  ///   Whether this parameter is set to @b true, reset all transformation
  ///   applied to the object.
  /// @details
  ///   The source rectangle defines the area of the texture to be rendered.
  //////////////////////////////////////////////////////////////////////////////
  void set_rect(int32_t x, int32_t y, int32_t w, int32_t h, bool reset=true);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Set the area of the texture to be rendered.
  /// @param[in] rect
  ///   New source rectangle.
  /// @param[in] reset
  ///   Whether this parameter is set to @b true, reset all transformation
  ///   applied to the object.
  /// @details
  ///   The source rectangle defines the area of the texture to be rendered.
  //////////////////////////////////////////////////////////////////////////////
  void set_rect(const rect_t& rect, bool reset=true);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Move the object relatively to its current position.
  /// @param[in] x
  ///   Distance x to move.
  /// @param[in] y
  ///   Distance y to move.
  //////////////////////////////////////////////////////////////////////////////
  void move(int32_t x, int32_t y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Move the object relatively to its current position.
  /// @param[in] distance
  ///   Distance to move.
  //////////////////////////////////////////////////////////////////////////////
  void move(const vector_t& distance);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Resize the object relatively to its current size.
  /// @param[in] x
  ///   Relative width to resize.
  /// @param[in] y
  ///   Relative height to resize.
  //////////////////////////////////////////////////////////////////////////////
  void resize(int32_t x, int32_t y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Resize the object relatively to its current size.
  /// @param[in] size
  ///   Relative size to resize.
  //////////////////////////////////////////////////////////////////////////////
  void resize(const vector_t& size);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Scale the object relatively to its current size.
  /// @param[in] x
  ///   X scale factor.
  /// @param[in] y
  ///   Y scale factor.
  /// @details
  ///   - > 1, zoom in
  ///   - < 1, zoom out
  ///   - = 1, left unchanged
  //////////////////////////////////////////////////////////////////////////////
  void scale(float x, float y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Scale the object relatively to its current size.
  /// @param[in] factor
  ///   Scale factor.
  /// @details
  ///   - > 1, zoom in
  ///   - < 1, zoom out
  ///   - = 1, left unchanged
  //////////////////////////////////////////////////////////////////////////////
  void scale(float factor);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Rotate the object relatively to its current orientation.
  /// @param[in] and_deg
  ///   Angle of the rotation in degrees.
  /// @param[in] x
  ///   Coordinate x of the center of the rotation.
  /// @param[in] y
  ///   Coordinate y of the center of the rotation.
  //////////////////////////////////////////////////////////////////////////////
  void rotate(float ang_deg, int32_t x, int32_t y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Rotate the object relatively to its current orientation.
  /// @param[in] and_deg
  ///   Angle of the rotation in degrees.
  /// @param[in] center
  ///   Center of the rotation.
  //////////////////////////////////////////////////////////////////////////////
  void rotate(float ang_deg, const vector_t& center);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Flip the texture.
  /// @param[in] horizontal
  ///   Set @b true for a horizontal flip.
  /// @param[in] vertical
  ///   Set @b true for a vertical flip.
  /// @details
  ///   Set both parameters to @b true for a diagonal flip.
  //////////////////////////////////////////////////////////////////////////////
  void flip(bool horizontal=false, bool vertical=false);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Renderer the object.
  //////////////////////////////////////////////////////////////////////////////
  virtual void render();

private:
  friend class RenderManager;

protected:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief Protected virtual constructor.
  /// @note
  ///   This class is NOT allowed to be instanciated, should only be called by
  ///   derivated class.
  //////////////////////////////////////////////////////////////////////////////
  Graphics();

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Protected destructor.
  //////////////////////////////////////////////////////////////////////////////
  virtual ~Graphics();

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Reset the size of the object.
  //////////////////////////////////////////////////////////////////////////////
  void reset_rect();

protected:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief Pointer to SDL Texture.
  //////////////////////////////////////////////////////////////////////////////
  SDL_Texture*      p_sdl_texture;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Source rectangle.
  //////////////////////////////////////////////////////////////////////////////
  rect_t            m_src_rect;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Position of the object.
  //////////////////////////////////////////////////////////////////////////////
  vector_t          m_position;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Size of the object.
  //////////////////////////////////////////////////////////////////////////////
  vector_t          m_size;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Angle of rotation.
  //////////////////////////////////////////////////////////////////////////////
  float             m_angle;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Center of rotation.
  //////////////////////////////////////////////////////////////////////////////
  vector_t          m_center;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Indicates the direction of flip.
  //////////////////////////////////////////////////////////////////////////////
  SDL_RendererFlip  m_sdl_flip;

private:
  friend void func::render_copy(SDL_Renderer* renderer, Graphics* graphics);
}; // class Graphics

} // namespace icelos

#endif /// ICELOS_GRAPHICS_HPP

