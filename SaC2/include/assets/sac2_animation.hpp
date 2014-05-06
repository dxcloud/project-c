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

namespace sac2
{

// Forward declaration
class AnimateSprite;

//////////////////////////////////////////////////////////////////////////////
//! \class Animation
//! \brief
//!     This class hold frames for animation purposes.
//! \see
//!     AnimationState, AnimationStateMachine
//////////////////////////////////////////////////////////////////////////////
class Animation
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Public default constructor.
  ////////////////////////////////////////////////////////////////////////////
  Animation();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Public default destructor.
  ////////////////////////////////////////////////////////////////////////////
  ~Animation();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Add a frame to the animation.
  //! \param[in] frame
  //!     Frame structure data.
  //! \see
  //!     frame_t
  ////////////////////////////////////////////////////////////////////////////
  status_t add_frame(frame_t frame);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Play the animation.
  ////////////////////////////////////////////////////////////////////////////
  status_t play();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Pause the animation.
  ////////////////////////////////////////////////////////////////////////////
  status_t pause();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Stop the animation.
  ////////////////////////////////////////////////////////////////////////////
  status_t stop();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Enable/Disable the animation to loop.
  //! \param[in] enable
  //!     Set \b true to enable the animation to loop, \b false otherwise.
  ////////////////////////////////////////////////////////////////////////////
  void set_repeat_enabled(bool enable=true);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Update the animation.
  //! \param[in] dt
  //!     Elapsed time since the last update.
  //! \details
  //!     This method must be called at each iteration.
  ////////////////////////////////////////////////////////////////////////////
  void update(AnimateSprite* sprite, float dt);

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \typedef frame_list_t
  //! \brief
  //!     Vector of frames.
  ////////////////////////////////////////////////////////////////////////////
  typedef std::vector<frame_t> frame_list_t;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Current state of the animation.
  //!     The current state could be: \b RUNNING, \b PAUSED or \b STOPPED
  ////////////////////////////////////////////////////////////////////////////
  state_t m_anim_state;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Vector containing different frames of the animation.
  ////////////////////////////////////////////////////////////////////////////
  frame_list_t m_frame_list;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Enable the animation to loop if it is \b true.
  ////////////////////////////////////////////////////////////////////////////
  bool m_repeat;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Count the duration of the animation. The value is reset to 0 when
  //!     the methode \b pause() is called.
  ////////////////////////////////////////////////////////////////////////////
  float m_frame_time;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Current index of the frame to be displayed.
  ////////////////////////////////////////////////////////////////////////////
  size_t m_frame_index;
};  // class Animation

}  // namespace sac2

#endif  //! SAC2_ANIMATION_HPP

