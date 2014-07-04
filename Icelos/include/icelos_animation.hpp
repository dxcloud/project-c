#ifndef ICELOS_ANIMATIONS_HPP
#define ICELOS_ANIMATIONS_HPP

#include <icelos_type.hpp>

namespace icelos
{

// forward declaration
class AnimatedSprite;

/// @class Animation
class Animation
{
public:
  /// @brief Public default constructor.
  Animation();

  /// @brief Public destructor.
  ~Animation();

  /// @brief Enable the animation to replay after it ends.
  void set_repeat(bool enable=true);

  /// @brief Add a new frame.
  void add_frame(frame_t frame);

  /// @brief Play the animation.
  void play();

  /// @brief Pause the animation.
  void pause();

  /// @brief Stop the animation.
  void stop();

  /// @brief Check whether the animation is playing.
  bool is_playing() const;

  /// @brief Check whether the animations is paused.
  bool is_paused() const;

  /// @brief Check whether the animation is stopped.
  bool is_stopped() const;

protected:
  void update(AnimatedSprite* sprite);

private:
  friend class AnimatedSprite;

private:
  typedef std::vector<frame_t> frame_vector_t;

private:
  state_t         m_animation_status;
  frame_vector_t  m_frames;
  bool            m_repeat;
  uint32_t        m_frame_time;
  uint32_t        m_frame_index;
};

}

#endif

