//////////////////////////////////////////////////////////////////////////////
//! \file sac2_animation.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (alpha)
//! \date
//!     2014-05-04
//! \brief
//!     Provides 2D animation manipulation class.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_ANIMATION_HPP
#define SAC2_ANIMATION_HPP

#include <sac2_type.hpp>
#include <sac2_sprite_asset.hpp>

#include <SFML/Graphics.hpp>

namespace sac2
{
//////////////////////////////////////////////////////////////////////////////
//! \class Animation
//! \brief
//!     
//! \see
//!     AnimationState, AnimationStateMachine
//////////////////////////////////////////////////////////////////////////////

class Animation
{
public:
  Animation();
  ~Animation();
  status_t add_frame(frame_t frame);
  status_t set_sprite_sheet(asset_id_t id);
  status_t play();
  status_t pause();
  status_t stop();
  void set_repeat_enabled(bool enable=true);
  void update(float dt);
private:
  typedef std::vector<frame_t> frame_list_t;

  state_t m_anim_state;
  frame_list_t m_frame_list;

  bool m_repeat;
  SpriteAsset m_sprite;
  float m_frame_time;
  size_t m_frame_index;
};


}

#endif  //! SAC2_ANIMATION_HPP

