/// \brief

#ifndef ICELOS_MANAGER_INL
#define ICELOS_MANAGER_INL


namespace icelos
{

template <typename T>
T* Manager<T>::p_manager = 0;


template <typename T>
inline Manager<T>::Manager()
{
  // nothing to do
}

template <typename T>
inline Manager<T>::~Manager()
{
  // nothing to do
}

template <typename T>
inline T& Manager<T>::instance()
{
  if (0 == p_manager) {
    p_manager = new T;
    p_manager->initialize();
  }
  return (*p_manager);
}

template <typename T>
inline void Manager<T>::destroy()
{
  if (0 != p_manager) {
    p_manager->cleanup();
    delete p_manager;
    p_manager = 0;
  }
}

template <typename T>
inline void Manager<T>::initialize()
{
  // nothing to do
}

template <typename T>
inline void Manager<T>::cleanup()
{
  // nothing to do
}

}

#endif

