//////////////////////////////////////////////////////////////////////////////
//! \file sac2_animation_state.inl
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (alpha)
//! \date
//!     2014-05-05
//! \brief
//!     Provides 2D animation manipulation class.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_ANIMATION_STATE_HPP_INL
#define SAC2_ANIMATION_STATE_HPP_INL

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
//! AnimationState::AnimationState
//////////////////////////////////////////////////////////////////////////////
inline AnimationState::AnimationState():
  m_animation()
{
  // do nothing
}

//////////////////////////////////////////////////////////////////////////////
//! AnimationState::~AnimationState
//////////////////////////////////////////////////////////////////////////////
inline AnimationState::~AnimationState()
{
  // do nothing
}

//////////////////////////////////////////////////////////////////////////////
//! AnimationState::update
//////////////////////////////////////////////////////////////////////////////
inline animation_state_t AnimationState::update(animation_state_t state,
                                                float dt)
{
  return handle(state, dt);
}

//////////////////////////////////////////////////////////////////////////////
//! AnimationState::animation
//////////////////////////////////////////////////////////////////////////////
inline Animation& AnimationState::animation()
{
  return m_animation;
}

} // namspace sac2

#endif // SAC2_ANIMATION_STATE_HPP_INCLUDE

