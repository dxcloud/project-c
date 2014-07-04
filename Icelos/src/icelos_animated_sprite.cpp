#include <icelos_animated_sprite.hpp>
// #include <icelos_render_manager.hpp>

#include <icelos_animation.hpp>

namespace icelos
{

AnimatedSprite::AnimatedSprite():
  Sprite(),
  m_animations(),
  p_current(nullptr)
{
  // nothing to do
}

AnimatedSprite::~AnimatedSprite()
{
  // nothing to do
}

void AnimatedSprite::update()
{
  if (nullptr == p_current) { return; }
  p_current->update(this);
}

status_t AnimatedSprite::add_animation(animation_id_t id, Animation* animation)
{
  OUT("call add animation_state")
  animation_iter_t it(m_animations.find(id));
  if (m_animations.end() != it) { return STATUS_ALREADY; }
  m_animations.insert(std::make_pair(id, animation));
  return STATUS_SUCCESS;
}

status_t AnimatedSprite::remove_animation(animation_id_t id)
{
  animation_iter_t it(m_animations.find(id));
  if (m_animations.end() == it) { return STATUS_MISS; }
  m_animations.erase(it);
  return STATUS_SUCCESS;
}


// const Animation* AnimatedSprite::get_animation(animation_id_t id) const
// {
//   animation_citer_t it(m_animations.find(id));
//   if (m_animations.end() == it) { return nullptr; }
//   return it->second;
// }

Animation* AnimatedSprite::animation(animation_id_t id) const
{
  animation_citer_t it(m_animations.find(id));
  if (m_animations.end() == it) { return nullptr; }
  return it->second;
}

status_t AnimatedSprite::set_animation(animation_id_t id, bool play)
{
  animation_iter_t it(m_animations.find(id));
  if (m_animations.end() == it) { return STATUS_MISS; }
  p_current = it->second;
  if (true == play) { p_current->play(); }
  return STATUS_SUCCESS;
}


void AnimatedSprite::render()
{
  update();
  Graphics::render();
}

} // namespace icelos

