////////////////////////////////////////////////////////////////////////////////
/// @file    icelos_vector.hpp
/// @brief   Main include file.
/// @date    2014-05-14
/// @version 0.1 (alpha)
/// @author  Chengwu Huang <chengwhuang@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef ICELOS_VECTOR_HPP
#define ICELOS_VECTOR_HPP

#include <cmath>

namespace icelos
{

template <typename T>
class Vector
{
public:
  Vector();
  Vector(T x, T y);
  Vector(const Vector<T>& vector);
  Vector<T>& operator=(const Vector<T>& vector);
  Vector<T> operator+(const Vector<T>& vector) const;
  Vector<T> operator-(const Vector<T>& vector) const;
  Vector<T>& operator+=(const Vector<T>& vector);
  Vector<T>& operator-=(const Vector<T>& vector);
  Vector<T> operator-() const;
  Vector<T> operator~() const;
  Vector<T> operator*(T scalar) const;
  Vector<T> operator/(T scalar) const;
  T dot(const Vector<T>& vector) const;
  T cross(const Vector<T>& vector) const;
  T norm2() const;
public:
  T x;
  T y;
};

template <typename T>
Vector<T> operator*(T scalar, const Vector<T>& vector);

typedef Vector<float>   fvector_t;
typedef Vector<double>  dvectort_t;
typedef Vector<int8_t>  cvector_t;
typedef Vector<int16_t> svector_t;
typedef Vector<int32_t> ivector_t;
typedef Vector<int64_t> lvector_t;

template <typename T>
inline Vector<T>::Vector():
  x(static_cast<T>(0)),
  y(static_cast<T>(0))
{
  // nothing to do
}

template <typename T>
inline Vector<T>::Vector(T vx, T vy):
  x(vx),
  y(vy)
{
  // nothing to do
}

template <typename T>
inline Vector<T>::Vector(const Vector<T>& vector):
  x(vector.x),
  y(vector.y)
{
  // nothing to do
}

template <typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& vector)
{
  x = vector.x;
  y = vector.y;
  return *this;
}

template <typename T>
inline Vector<T> Vector<T>::operator+(const Vector<T>& vector) const
{
  return Vector<T>(x + vector.x, y + vector.y);
}

template <typename T>
inline Vector<T> Vector<T>::operator-(const Vector<T>& vector) const
{
  return Vector<T>(x - vector.x, y - vector.y);
}

template <typename T>
inline Vector<T>& Vector<T>::operator+=(const Vector<T>& vector)
{
  x += vector.x;
  y += vector.y;
  return *this;
}

template <typename T>
inline Vector<T>& Vector<T>::operator-=(const Vector<T>& vector)
{
  x -= vector.x;
  y -= vector.y;
  return *this;
}

template <typename T>
inline Vector<T> Vector<T>::operator*(T scalar) const
{
  return Vector<T>(scalar * x, scalar * y);
}

template <typename T>
inline Vector<T> Vector<T>::operator/(T scalar) const
{
  return Vector<T>(x / scalar, y / scalar);
}

template <typename T>
inline Vector<T> Vector<T>::operator~() const
{
  return Vector<T>(x, -y);
}

template <typename T>
inline Vector<T> Vector<T>::operator-() const
{
  return Vector<T>(-x, -y);
}

template <typename T>
inline T Vector<T>::dot(const Vector<T>& vector) const
{
  return ((x * vector.x) + (y * vector.y));
}

template <typename T>
inline T Vector<T>::cross(const Vector<T>& vector) const
{
  return ((x * vector.y) - (y * vector.x));
}

template <typename T>
inline T Vector<T>::norm2() const
{
  return ((x * x) + (y * y));
}

template <typename T>
inline Vector<T> operator*(T scalar, const Vector<T>& vector)
{
  return Vector<T>(scalar * vector.x, scalar * vector.y);
}

}

#endif /// ICELOS_VECTOR_HPP

