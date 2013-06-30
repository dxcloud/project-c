/*!
 * \file sac2_math.cpp
 */

#include <limits>

#include <sac2_math.hpp>

namespace sac2
{

const float Math::PI(3.141592654F);
const float Math::TWO_PI(6.283185307F);
const float Math::HALF_PI(1.570796327F);
const float Math::QUARTER_PI(0.785398163F);
const float Math::E(2.718281828F);
const float Math::LOG10_2(0.301029996F);
const float Math::SQRT_2(1.414213562F);
const float Math::LN_2(0.693147181F);
const float Math::EPSILON(std::numeric_limits<float>::epsilon());

float radians(float deg)
{
  return deg * Math::PI / 180.0F;
}

float degrees(float rad)
{
  return rad * 180.0F / Math::PI;
}

}

