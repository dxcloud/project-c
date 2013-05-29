/*!
 * \file    sac2_manager.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Singleton Pattern template
 */

#ifndef SAC2_MANAGER_HPP
#define SAC2_MANAGER_HPP

#include "sac2_type.hpp"

namespace sac2
{

template<class T>

/*!
 * \class   Manager
 * \brief   Template for Manager type class
 * \details The class is implemented with Singleton Pattern
 */
class Manager
{
public:

  /*!
   * \brief  Get an instance of the class
   * \return Unique instance
   */
  static T* create();

  /*!
   * \brief  Destroy the class if NOT destroyed yet
   * \return SaC2 status
   */
  static status_t destroy();

  /*!
   * \brief  Tell whether the manager is initialized
   * \return 
   */
  bool is_initialized();

  /*!
   * \brief   Initialize the manager
   * \details If the derivated class uses specific member datas, overrides
   *          this method
   * \return  SaC2 status
   */
  virtual status_t initialize();

  /*!
   * \brief
   * \return
   */
  virtual status_t update();

  /*!
   * \brief  Clean before destroying the class
   * \return SaC2 status
   */
  virtual status_t cleanup();

protected:
  /*!
   * \brief   Constructor
   * \details Proctected
   */
  Manager();

  /*!
   * \brief   Destuctor
   * \details Protected
   */
  virtual ~Manager();

protected:
  bool      m_initialized;  //!< \b true if the class is initialized

private:

  static T* p_manager;  //!< Unique instance
};  // class Manager


//----------------------------------------------------------------------------
//  Manager::p_manager
//----------------------------------------------------------------------------
template<typename T>
T* Manager<T>::p_manager = 0;

//----------------------------------------------------------------------------
//  Manager::Manager
//----------------------------------------------------------------------------
template<typename T>
inline Manager<T>::Manager():
  m_initialized(false)
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Manager::~Manager
//----------------------------------------------------------------------------
template<typename T>
inline Manager<T>::~Manager()
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Engine::create
//----------------------------------------------------------------------------
template<typename T>
inline T* Manager<T>::create()
{
  if (0 == p_manager) {
    p_manager = new T;
    return static_cast<T*>(p_manager);
  }
  return p_manager;
}

//----------------------------------------------------------------------------
//  Manager::is_initialized
//----------------------------------------------------------------------------
template<typename T>
inline bool Manager<T>::is_initialized()
{
  return m_initialized;
}

//----------------------------------------------------------------------------
//  Manager::initialize
//----------------------------------------------------------------------------
template<typename T>
inline status_t Manager<T>::initialize()
{
  m_initialized = true;
  return STATUS_SUCCESS;
}

//----------------------------------------------------------------------------
//  Manager::update
//----------------------------------------------------------------------------
template<typename T>
inline status_t Manager<T>::update()
{
  return STATUS_SUCCESS;
}

//----------------------------------------------------------------------------
//  Manager::destroy
//----------------------------------------------------------------------------
template<typename T>
inline status_t Manager<T>::destroy()
{
  if (0 != p_manager) {
    delete p_manager;
    p_manager = 0;
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

//----------------------------------------------------------------------------
//  Manager::cleanup
//----------------------------------------------------------------------------
template<typename T>
inline status_t Manager<T>::cleanup()
{
  // do nothing
  return STATUS_SUCCESS;
}

}

#endif  //! SAC2_MANAGER_HPP
