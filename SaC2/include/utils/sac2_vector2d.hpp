/*!
 * \file sac2_vector2d.hpp
 */

#ifndef SAC2_VECTOR_2D_HPP
#define SAC2_VECTOR_2D_HPP

#include <iostream>

#include <SFML/System/Vector2.hpp>

#include <sac2_math.hpp>

namespace sac2
{

class Vector2D
{
public:
  static const Vector2D zeros;
  static const Vector2D ones;
  static const Vector2D n_ones;
  static const Vector2D unit_x;
  static const Vector2D unit_y;
  static const Vector2D n_unit_x;
  static const Vector2D n_unit_y;

public:
  Vector2D();
  Vector2D(float v_x, float v_y);
  Vector2D(const Vector2D& vector);
  Vector2D(const sf::Vector2f& vector);
  ~Vector2D();

  Vector2D& operator=(const Vector2D& vector);

  bool operator==(const Vector2D& vector) const;
  bool operator!=(const Vector2D& vector) const;

  Vector2D operator-() const;
  Vector2D operator+(const Vector2D& vector) const;
  Vector2D operator-(const Vector2D& vector) const;
  Vector2D operator*(float scalar) const;
  Vector2D operator/(float scalar) const;
  Vector2D operator~() const;
  Vector2D operator()(float v_x, float v_y);

  Vector2D& operator+=(const Vector2D& vector);
  Vector2D& operator-=(const Vector2D& vector);
  Vector2D& operator*=(float scalar);
  Vector2D& operator/=(float scalar);

  bool is_collinear(const Vector2D& vector) const;
  bool is_perpendicular(const Vector2D& vector) const;

  float dot(const Vector2D& vector) const;
  float cross(const Vector2D& vector) const;
  float norm() const;
  float norm_2() const;

  float angle() const;
  float angle(const Vector2D& vector) const;

  Vector2D orthogonal() const;
  Vector2D projected(const Vector2D& vector) const;
  Vector2D normalized() const;

public:
  float x;
  float y;
};

std::ostream& operator<<(std::ostream& out, const Vector2D& vector);
Vector2D operator*(float scalar, const Vector2D& vector);

}

#include <sac2_vector2d.inl>

#endif  //! SAC2_VECTOR_2D_HPP
