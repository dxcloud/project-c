#ifndef ICELOS_RECTANGLE_INL
#define ICELOS_RECTANGLE_INL

namespace icelos
{

template <typename T>
inline Rectangle<T>::Rectangle():
  x(static_cast<T>(0)),
  y(static_cast<T>(0)),
  w(static_cast<T>(0)),
  h(static_cast<T>(0))
{
  // nothing to do
}

template <typename T>
inline Rectangle<T>::Rectangle(T rx, T ry, T rw, T rh):
  x(rx),
  y(ry),
  w(rw),
  h(rh)
{
  // nothing to do
}

template <typename T>
inline Rectangle<T>::Rectangle(const Vector<T>& position, const Vector<T>& size):
  x(position.x),
  y(position.y),
  w(size.x),
  h(size.y)
{
  // nothing to do
}


template <typename T>
inline Rectangle<T>::Rectangle(const Rectangle<T>& rectangle):
  x(rectangle.x),
  y(rectangle.y),
  w(rectangle.w),
  h(rectangle.h)
{
  // nothing to do
}


template <typename T>
inline Rectangle<T>::~Rectangle()
{
  // nothing to do
}

template <typename T>
inline Rectangle<T>& Rectangle<T>::operator=(const Rectangle<T>& rectangle)
{
  x = rectangle.x;
  y = rectangle.y;
  w = rectangle.w;
  h = rectangle.h;
  return (*this);
}

} // namespace icelos

#endif /// ICELOS_RECTANGLE_INL

