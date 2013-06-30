/*!
 * \file sac2_vector2d.inl
 */

#ifndef SAC2_VECTOR_2D_INL
#define SAC2_VECTOR_2D_INL

namespace sac2
{

inline Vector2D::Vector2D():
  x(0.0F),
  y(0.0F)
{

}

inline Vector2D::Vector2D(float v_x, float v_y):
  x(v_x),
  y(v_y)
{

}

inline Vector2D::Vector2D(const Vector2D& vector):
  x(vector.x),
  y(vector.y)
{

}

inline Vector2D::Vector2D(const sf::Vector2f& vector):
  x(vector.x),
  y(vector.y)
{

}

inline Vector2D::~Vector2D()
{

}

inline Vector2D& Vector2D::operator=(const Vector2D& vector)
{
  this->x = vector.x;
  this->y = vector.y;
  return (*this);
}

inline bool Vector2D::operator==(const Vector2D& vector) const
{
  if (Math::EPSILON < fabs(x - vector.x)) { return false; }
  if (Math::EPSILON < fabs(y - vector.y)) { return false; }
  return true;
}

inline bool Vector2D::operator!=(const Vector2D& vector) const
{
  return !(operator==(vector));
}

inline Vector2D Vector2D::operator-() const
{
  Vector2D result(-x, -y);
  return result;
}

inline Vector2D Vector2D::operator+(const Vector2D& vector) const
{
  Vector2D result(x + vector.x, y + vector.y);
  return result;
}

inline Vector2D Vector2D::operator-(const Vector2D& vector) const
{
  Vector2D result(x - vector.x, y - vector.y);
  return result;
}

inline Vector2D Vector2D::operator~() const
{
  Vector2D result(x, -y);
  return result;
}

inline Vector2D Vector2D::operator*(float scalar) const
{
  Vector2D result(scalar * x, scalar * y);
  return result;
}

inline Vector2D operator*(float scalar, const Vector2D& vector)
{
  Vector2D result(scalar * vector.x, scalar * vector.y);
  return result;
}

inline Vector2D Vector2D::operator/(float scalar) const
{
  Vector2D result;
  if (Math::EPSILON < fabs(scalar)) {
    result(x / scalar, y / scalar);
  }
  return result;
}

inline Vector2D Vector2D::operator()(float v_x, float v_y)
{
  this->x = v_x;
  this->y = v_y;
  return (*this);
}



inline Vector2D& Vector2D::operator+=(const Vector2D& vector)
{
  this->x += vector.x;
  this->y += vector.y;
  return (*this);
}

inline Vector2D& Vector2D::operator-=(const Vector2D& vector)
{
  this->x -= vector.x;
  this->y -= vector.y;
  return (*this);
}

inline Vector2D& Vector2D::operator*=(float scalar)
{
  this->x *= scalar;
  this->y *= scalar;
  return (*this);
}

inline Vector2D& Vector2D::operator/=(float scalar)
{
  if (Math::EPSILON < fabs(scalar)) {
    this->x /= scalar;
    this->y /= scalar;
  }
  return (*this);
}

inline float Vector2D::dot(const Vector2D& vector) const
{
  return ((x * vector.x) + (y * vector.y));
}


inline float Vector2D::cross(const Vector2D& vector) const
{
  return ((x * vector.y) - (y * vector.x));
}


inline float Vector2D::norm() const
{
  return sqrtf(norm_2());
}

inline float Vector2D::norm_2() const
{
  return ((x * x) + (y * y));
}


inline std::ostream& operator<<(std::ostream& os, const Vector2D& vector)
{
  os << "(" << vector.x << ", " << vector.y << ")";
  return os;
}

inline bool Vector2D::is_collinear(const Vector2D& vector) const
{
  if (Math::EPSILON > cross(vector)) { return true; }
  return false;
}

inline bool Vector2D::is_perpendicular(const Vector2D& vector) const
{
  if (Math::EPSILON > dot(vector)) { return true; }
  return false;
}

inline float Vector2D::angle() const
{
  return atan2(y, x);
}

inline float Vector2D::angle(const Vector2D& vector) const
{
  return (angle() - vector.angle());
}

inline Vector2D Vector2D::normalized() const
{
  return ((*this) / norm());
}

inline Vector2D Vector2D::projected(const Vector2D& vector) const
{
  Vector2D result(vector.normalized());
  return (result * dot(vector));
}

inline Vector2D Vector2D::orthogonal() const
{
  Vector2D result(-y, x);
  return result;
}

}

#endif
