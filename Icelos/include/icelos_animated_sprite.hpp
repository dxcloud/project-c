#ifndef ICELOS_ANIMATED_SPRITE_HPP
#define ICELOS_ANIMATED_SPRITE_HPP

// icelos include
#include <icelos_sprite.hpp>

namespace icelos
{

// forward declaration
class Animation;

/// @class AnimatedSprite
/// @brief This class manages animated sprite.
class AnimatedSprite:
  public Sprite
{
public:
  /// @brief Public default constructor.
  AnimatedSprite();

  /// @brief Public destructor.
  virtual ~AnimatedSprite();

  /// @brief Add an animation.
  /// @param[in] id
  ///   ID of the animation to add.
  /// @param[in] animation
  ///   Pointer to the animation to add.
  /// @return
  ///   Status code.
  status_t add_animation(animation_id_t id, Animation* animation);

  /// @brief Remove an animation.
  /// @param[in] id
  ///   ID of the animation to remove.
  /// @return
  ///   Status code.
  status_t remove_animation(animation_id_t id);

  /// @brief Set an animation to play.
  /// @param[in] id
  ///   ID of the animation to be played.
  /// @param[in] play
  ///   Whether this parameter is set to @b true, the animation starts playing.
  /// @return
  ///   Status code:
  ///   - @b STATUS_SUCCESS
  ///   - @b STATUS_MISS: animation not found
  status_t set_animation(animation_id_t id, bool play=true);

  /// @brief Get the animation given by @b id.
  /// @param[in] id
  ///   ID of the animation.
  /// @return
  ///   Pointer to the current animation, 0 whether not found.
  Animation* animation(animation_id_t id) const;

  /// @brief Display the sprite.
  /// @details
  ///   The method updates the animation, then displays it.
  void render();

private:
  /// @brief Update the current animation.
  void update();

private:
  typedef std::map<animation_id_t, Animation*> animation_map_t;
  typedef animation_map_t::iterator animation_iter_t;
  typedef animation_map_t::const_iterator animation_citer_t;

private:
  /// @brief Collection of animations.
  animation_map_t  m_animations;

  /// @brief Pointer to the current animation.
  Animation*       p_current;
}; // class AnimatedSprite

} // namespace icelos

#endif // ICELOS_ANIMATED_SPRITE_HPP

