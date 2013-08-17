//////////////////////////////////////////////////////////////////////////////
//! \file sac2_manager.inl
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (develpment version)
//! \date
//!     2013-07-03
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_MANAGER_HPP_INCLUDE
#define SAC2_MANAGER_HPP_INCLUDE

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
// T* Manager<T>::p_manager
//////////////////////////////////////////////////////////////////////////////
template<class T>
T* Manager<T>::p_manager = 0;

//////////////////////////////////////////////////////////////////////////////
// Manager<T>::Manager
//////////////////////////////////////////////////////////////////////////////
template<class T>
inline Manager<T>::Manager()
{
  // do nothing
}

//////////////////////////////////////////////////////////////////////////////
// Manager<T>::~Manager
//////////////////////////////////////////////////////////////////////////////
template<class T>
inline Manager<T>::~Manager()
{
  // do nothing
}

//////////////////////////////////////////////////////////////////////////////
// T& Manager<T>::instance
//////////////////////////////////////////////////////////////////////////////
template<typename T>
inline T& Manager<T>::instance()
{
  if (0 == p_manager) {
    p_manager = new T;
    p_manager->initialize();
  }
  return (*p_manager);
}

//////////////////////////////////////////////////////////////////////////////
// void Manager<T>::destroy
//////////////////////////////////////////////////////////////////////////////
template<typename T>
inline void Manager<T>::destroy()
{
  if (0 != p_manager) {
    p_manager->cleanup();
    delete p_manager;
    p_manager = 0;
  }
}

//////////////////////////////////////////////////////////////////////////////
// void Manager<T>::initialize
//////////////////////////////////////////////////////////////////////////////
template<typename T>
inline void Manager<T>::initialize()
{
  // do nothing
}

//////////////////////////////////////////////////////////////////////////////
// void Manager<T>::initialize
//////////////////////////////////////////////////////////////////////////////
template<typename T>
inline void Manager<T>::update(float dt)
{
  // do nothing
}

//////////////////////////////////////////////////////////////////////////////
// void Manager<T>::cleanup
//////////////////////////////////////////////////////////////////////////////
template<typename T>
inline void Manager<T>::cleanup()
{
  // do nothing
}

}  // namespace sac2

#endif  //! SAC2_MANAGER_HPP_INCLUDE
