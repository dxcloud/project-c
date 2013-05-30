/*!
 * \file    sac2_manager.hpp
 * \author  Chengwu HUANG
 * \version 1.0
 * \date    2013-04-08 - Initial Development
 * \brief   Singleton Pattern template for Manager type classes
 */

#ifndef SAC2_MANAGER_HPP
#define SAC2_MANAGER_HPP

#include <sac2_type.hpp>
#include <sac2_logger.hpp>

namespace sac2
{
/*!
 * \class   Manager
 * \brief   Template for Manager type class
 * \details This class is implemented with Singleton Pattern
 */
template<typename T>
class Manager
{
public:
  /*!
   * \brief  Check whether the manager is initialized
   * \return Return \b true whether the manager is initialized,
   *         \b false otherwise
   */
  bool is_initialized();

  /*!
   * \brief  Get an instance of the class
   * \return Return the unique instance
   */
  static T* create();

  /*!
   * \brief  Destroy the class if NOT destroyed yet
   * \return SaC2 status
   *         - \b STATUS_SUCCESS: successfully destroyed
   *         - \b STATUS_ALREADY: already destroyed
   */
  static void destroy();

  /*!
   * \brief  Update the manager
   * \return SaC2 status
   */
  virtual void update();

protected:
  /*!
   * \brief Protected default constructor
   */
  Manager();

  /*!
   * \brief Protected default destuctor
   */
  virtual ~Manager();

  /*!
   * \brief   Initialize the manager
   * \details If the derivated class uses specific member attributs, override
   *          this method.
   * \return  SaC2 status can be returned
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_FAIL
   *          - \b STATUS_ALREADY
   */
  virtual void initialize();

  /*!
   * \brief   Clean before destroying the class
   * \details Override this method whether member attributs need to be deleted
   * \return  SaC2 status
   */
  virtual void cleanup();

protected:
  bool      m_initialized;  //!< Specify whether the manager is initialized

private:
  static T* p_manager;      //!< Unique instance of the class
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
//  Manager::is_initialized
//----------------------------------------------------------------------------
template<typename T>
inline bool Manager<T>::is_initialized()
{
  return m_initialized;
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
//  Manager::destroy
//----------------------------------------------------------------------------
template<typename T>
inline void Manager<T>::destroy()
{
  if (0 != p_manager) {
    delete p_manager;
    p_manager = 0;
  }
}

//----------------------------------------------------------------------------
//  Manager::update
//----------------------------------------------------------------------------
template<typename T>
inline void Manager<T>::update()
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Manager::initialize
//----------------------------------------------------------------------------
template<typename T>
inline void Manager<T>::initialize()
{
  m_initialized = true;
}

//----------------------------------------------------------------------------
//  Manager::cleanup
//----------------------------------------------------------------------------
template<typename T>
inline void Manager<T>::cleanup()
{
  // do nothing
}

}

#endif  //! SAC2_MANAGER_HPP
