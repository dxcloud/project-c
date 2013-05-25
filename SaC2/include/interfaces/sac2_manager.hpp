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

  bool is_initialized();

  /*!
   * \brief   Initialize the manager
   * \details If the derivated class uses specific member datas, overrides
   *          this method
   * \return  SaC2 status
   */
  virtual status_t initialize();
  
  virtual status_t update();

  /*!
   * \brief  Clean before destroying the class
   * \return SaC2 status
   */
  virtual status_t cleanup();

  /*!
   * \brief  Destroy the class if NOT destroyed yet
   * \return SaC2 status
   */
  static status_t destroy();

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

  bool      m_initialized;  //!< \b true if the class is initialized

private:

  static T* p_manager;  //!< Unique instance
};  // class Manager


template<typename T>
T* Manager<T>::p_manager = 0;

template<typename T>
inline Manager<T>::Manager():
    m_initialized(false)
{
  
}

template<typename T>
inline Manager<T>::~Manager()
{

}

template<typename T>
inline T* Manager<T>::create()
{
  if (0 == p_manager) {
    p_manager = new T;
    return static_cast<T*>(p_manager);
  }
  return p_manager;
}

template<typename T>
inline bool Manager<T>::is_initialized()
{
  return m_initialized;
}

template<typename T>
inline status_t Manager<T>::initialize()
{
  m_initialized = true;
  return STATUS_SUCCESS;
}

template<typename T>
inline status_t Manager<T>::update()
{
  return STATUS_SUCCESS;
}

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

template<typename T>
inline status_t Manager<T>::cleanup()
{
  // do nothing
  return STATUS_SUCCESS;
}

}

#endif  //! SAC2_MANAGER_HPP
