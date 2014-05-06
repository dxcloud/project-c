//////////////////////////////////////////////////////////////////////////////
//! \file sac2_game_object.cpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.2 (alpha)
//! \date
//!     2013-04-08: Initial develepment.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_GAME_OBJECT_HPP
#define SAC2_GAME_OBJECT_HPP

namespace sac2
{

typedef unsigned int object_id_t;

class GameObject
{
public:
  GameObject() {}
  virtual ~GameObject() {}
};  // class GameObject

}

#endif //! SAC2_GAME_OBJECT_HPP

