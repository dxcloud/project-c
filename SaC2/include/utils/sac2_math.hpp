#ifndef SAC2_MATH_HPP
#define SAC2_MATH_HPP

#include <cmath>

namespace sac2
{


namespace constants
{

const float ZERO(0.0F);


}

//using constants::ZERO;

class Math
{
public:
  static const float PI;
  static const float TWO_PI;
  static const float HALF_PI;
  static const float QUARTER_PI;
  static const float LOG10_2;
  static const float LN_2;
  static const float SQRT_2;
  static const float E;
  static const float EPSILON;

};

float radians(float deg);
float degrees(float rad);


}

#endif  //! SAC2_MATH_HPP
