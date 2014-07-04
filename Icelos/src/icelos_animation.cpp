#include <icelos_animation.hpp>
#include <icelos_animated_sprite.hpp>
#include <icelos_render_manager.hpp>

namespace icelos
{

Animation::Animation():
  m_animation_status(STOPPED),
  m_frames(),
  m_repeat(true),
  m_frame_time(time::ZERO),
  m_frame_index(0)
{
  // nothing to do
}

Animation::~Animation()
{
  // nothing to do
}

void Animation::set_repeat(bool enable)
{
  m_repeat = enable;
}

void Animation::add_frame(frame_t frame)
{
  m_frames.push_back(frame);
}

void Animation::play()
{
  m_animation_status = PLAYING;
}

void Animation::pause()
{
  m_animation_status = PAUSED;
}

void Animation::stop()
{
  m_frame_index = 0;
  m_frame_time = time::ZERO;
  m_animation_status = STOPPED;
}

void Animation::update(AnimatedSprite* sprite)
{
  if (PLAYING != m_animation_status) { return; }  // animation is stopped

  frame_t frame = m_frames[m_frame_index];
  sprite->set_rect(frame.clip);

  m_frame_time += RenderManager::instance().get_elapsed().to_milliseconds();  // add frame time
  if (frame.duration < m_frame_time) {
    m_frame_time = time::ZERO;  // reset frame time
    ++m_frame_index;  // next frame
    if (m_frames.size() <= m_frame_index) {
      if (true == m_repeat) { m_frame_index = 0; }  // if repeat enabled
      else { stop(); }  // end of animation
    }  // if last frame
  }  // if current time is bigger than the duration of the frame

}

bool Animation::is_paused() const
{
  return (PAUSED == m_animation_status);
}

bool Animation::is_playing() const
{
  return (PLAYING == m_animation_status);
}

bool Animation::is_stopped() const
{
  return (STOPPED == m_animation_status);
}


}

