#ifndef _SAC2_MANAGER_HPP_
#define _SAC2_MANAGER_HPP_

/*!
 * \file    sac2_manager.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Singleton Pattern template
 */

#include "sac2_type.hpp"

namespace sac2
{

template<typename T>

/*!
 * \brief Template for Manager type class
 * \details The class is implemented with Singleton Pattern
 */
class Manager
{
 public:

  /*!
   * \brief  Get an instance of the class
   * \return Unique instance
   */
  static T* get_instance();

  /*!
   * \brief  Destroy the class if NOT destroyed yet
   * \return SaC2 status
   */
  static sac2_status_t finalize();

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

 private:

  static T* p_manager;  //!< Unique instance
}; 


template<typename T>
T* Manager<T>::p_manager = 0;

template<typename T>
inline Manager<T>::Manager()
{
  
}

template<typename T>
inline Manager<T>::~Manager()
{

}

template<typename T>
inline T* Manager<T>::get_instance()
{
  if (0 == p_manager) {
    p_manager = new T;
    return static_cast<T*>(p_manager);
  }
  return p_manager;
}

template<typename T>
inline sac2_status_t Manager<T>::finalize()
{
  if (0 != p_manager) {
    delete p_manager;
    p_manager = 0;
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

}

#endif  //! _SAC2_MANAGER_HPP_
