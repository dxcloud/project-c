////////////////////////////////////////////////////////////////////////////////
/// @file    icelos_vector.hpp
/// @brief   Provides 2D vector utilities.
/// @date    2014-05-14
/// @version 0.1 (alpha)
/// @author  Chengwu Huang <chengwhuang@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef ICELOS_VECTOR_HPP
#define ICELOS_VECTOR_HPP

#include <cmath>
//#include <SDL2/SDL_rect.h>

namespace icelos
{

////////////////////////////////////////////////////////////////////////////////
/// @class   Vector
/// @brief   Templated class for 2D vector manipulation.
/// @note
///   There are two non-trivial operators: @b '~' and @b '!'.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
class Vector
{
public:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public default constructor.
  //////////////////////////////////////////////////////////////////////////////
  Vector();

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public overload constructor.
  /// @param[in] x
  ///   X coordinate of the vector.
  /// @param[in] y
  ///   Y coordinate of the vector.
  //////////////////////////////////////////////////////////////////////////////
  Vector(T x, T y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public copy constructor.
  /// @param[in] vector
  ///   Vector to copy.
  //////////////////////////////////////////////////////////////////////////////
  Vector(const Vector<T>& vector);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public Assignment operator.
  /// @param[in] vector
  ///   Vector to copy.
  /// @return
  ///   Copied vector.
  //////////////////////////////////////////////////////////////////////////////
  Vector<T>& operator=(const Vector<T>& vector);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override binary member operator @b '+'.
  /// @param[in] vector
  ///   Vector operand.
  /// @return
  ///   Result of operation @b '+' between two vectors.
  //////////////////////////////////////////////////////////////////////////////
  Vector<T> operator+(const Vector<T>& vector) const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override binary member operator @b '-'.
  /// @param[in] vector
  ///   Vector operand.
  /// @return
  ///   Result of operation @b '-' between two vectors.
  //////////////////////////////////////////////////////////////////////////////
  Vector<T> operator-(const Vector<T>& vector) const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override binary member operator @b '*'.
  /// @param[in] scalar
  ///   Scalar operand.
  /// @return
  ///   Return vector (x * scalar, x * scalar).
  //////////////////////////////////////////////////////////////////////////////
  template <typename U>
  Vector<T> operator*(U scalar) const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override binary member operator @b '/'.
  /// @param[in] scalar
  ///   Scalar operand.
  /// @return
  ///   Return vector (x / scalar, y / scalar).
  //////////////////////////////////////////////////////////////////////////////
  template <typename U>
  Vector<T> operator/(U scalar) const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override member operator @b '+='.
  /// @param[in] vector
  ///   Vector operand.
  /// @return
  ///   Reference of the result of operation @b '+='.
  //////////////////////////////////////////////////////////////////////////////
  Vector<T>& operator+=(const Vector<T>& vector);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override member operator @b '-='.
  /// @param[in] vector
  ///   Vector operand.
  /// @return
  ///   Reference of the result of operation @b '-='.
  //////////////////////////////////////////////////////////////////////////////
  Vector<T>& operator-=(const Vector<T>& vector);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override binary member operator @b '*'.
  /// @param[in] scalar
  ///   Scalar operand.
  /// @return
  ///   Reference of the result of operation @b '*'.
  //////////////////////////////////////////////////////////////////////////////
  template <typename U>
  Vector<T>& operator*=(U scalar);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override binary member operator @b '/'.
  /// @param[in] scalar
  ///   Scalar operand.
  /// @return
  ///   Reference of the result of operation @b '/'.
  //////////////////////////////////////////////////////////////////////////////
  template <typename U>
  Vector<T>& operator/=(U scalar);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override unary operator @b '!'.
  /// @return
  ///   Return vector (-x, y).
  //////////////////////////////////////////////////////////////////////////////
  Vector<T> operator!() const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override unary operator @b '~'.
  /// @return
  ///   Return vector (x, -y).
  //////////////////////////////////////////////////////////////////////////////
  Vector<T> operator~() const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override unary member operator @b '-'.
  /// @return
  ///   Return vector (-x, -y).
  //////////////////////////////////////////////////////////////////////////////
  Vector<T> operator-() const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Dot product.
  /// @param[in] vector
  ///   Vector operand.
  /// @return
  ///   Return dot product between two vectors.
  //////////////////////////////////////////////////////////////////////////////
  T dot(const Vector<T>& vector) const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Cross product.
  /// @param[in] vector
  ///   Vector operand.
  /// @return
  ///   Return cross product between two vectors.
  //////////////////////////////////////////////////////////////////////////////
  T cross(const Vector<T>& vector) const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Computes norm 2 of the vector.
  /// @return
  ///   Return norm 2 of the vector.
  //////////////////////////////////////////////////////////////////////////////
  T norm2() const;

public:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief X coordinate or width.
  //////////////////////////////////////////////////////////////////////////////
  union
  {
    T x;
    T w;
  };

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Y coordinate or height.
  //////////////////////////////////////////////////////////////////////////////
  union
  {
    T y;
    T h;
  };
}; // class Vector

////////////////////////////////////////////////////////////////////////////////
/// @relates Vector
/// @brief   Public override binary operator @b '*'.
/// @param[in] scalar
///   Scalar operand.
/// @param[in] vector
///   Vector operand.
/// @return
///   Result of the operation @b '*' between scalar and vector.
////////////////////////////////////////////////////////////////////////////////
template <typename T, typename U>
Vector<T> operator*(T scalar, const Vector<U>& vector);

typedef Vector<int32_t> vector_t;

typedef Vector<float>   fvector_t;
typedef Vector<double>  dvectort_t;
typedef Vector<int8_t>  cvector_t;
typedef Vector<int16_t> svector_t;
typedef Vector<int32_t> ivector_t;
typedef Vector<int64_t> lvector_t;

} // namespace icelos

#include <icelos_vector.inl>

#endif /// ICELOS_VECTOR_HPP

