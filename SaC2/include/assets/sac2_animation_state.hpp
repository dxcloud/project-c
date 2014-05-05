#ifndef SAC2_ANIMATION_STATE_HPP
#define SAC2_ANIMATION_STATE_HPP

#include <sac2_animation.hpp>

namespace sac2
{

typedef uint32_t animation_state_t;

//////////////////////////////////////////////////////////////////////////////
//! \class AnimationState
//! \brief
//! \see
//!     Animation, AnimationStateMachine
//////////////////////////////////////////////////////////////////////////////
class AnimationState
{
public:
  AnimationState() {}
  virtual ~AnimationState() {}
  animation_state_t update(animation_state_t state, float dt) {
    return handle(state, dt);
  }
protected:
  Animation& animation() { return m_animation; }
private:
  virtual animation_state_t handle(animation_state_t state, float dt) = 0;
private:
  Animation m_animation;
};

typedef std::map<animation_state_t, AnimationState*> animation_state_map_t;

//////////////////////////////////////////////////////////////////////////////
//! \class AnimationStateMachine
//! \brief
//! \see
//!     AnimationState
//////////////////////////////////////////////////////////////////////////////
class AnimationStateMachine
{
public:
  AnimationStateMachine(): m_animation_map(), m_current(0) {}
  ~AnimationStateMachine() {}

  void add_animation_state(animation_state_t id, AnimationState* state) {
    m_animation_map.insert(std::make_pair(id, state));
    // initialize current state to the first inserted state
    if (0 == m_current) { m_current = state; }
  }

  void update(animation_state_t state, float dt) {
    animation_state_t next_state = m_current->update(state, dt);
    m_current = m_animation_map.at(next_state);
  }

protected:
  animation_state_map_t m_animation_map;  // Collection of animation states
  AnimationState* m_current;
};  // class AnimationStateMachine

}  // namspace sac2

#endif  //! SAC2_ANIMATION_STATE_HPP

