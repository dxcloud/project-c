#include <iostream>
#include <vector>

#include <sac2_type.hpp>
#include <sac2_vector2d.hpp>

#define MATH_PI 3.141592653589793

using namespace sac2;

void test_vector()
{
  vector_t v;
  vector_t v1;
  vector_t v2(1.0F, 1.5F);
  vector_t v3(v1);
  vector_t v4 = v2;
  vector_t v5;
  v5(2.0F, 9.5F);
  v5.x = 1.9F;
  std::cout << "v1 = " << v1 << std::endl;
  std::cout << "v2 = " << v2 << std::endl;
  std::cout << "v3 = " << v3 << std::endl;
  std::cout << "v4 = " << v4 << std::endl;
  std::cout << "v5 = " << v5 << std::endl;
  std::cout << "-----------" << std::endl;
  v4 = -v4;
  std::cout << "v4 = -v4 => " << v4 << std::endl;
  v3 += v5;
  std::cout << "v3 += v5 => " << v3 << std::endl;
  v1 = v1(1.0F, 1.0F) * 2;
  std::cout << "v1 = v1(1., 1.) * 2 => " << v1 << std::endl;
  v2 = v1 + v3 + ~v4;
  std::cout << "~" << v4 << " => " << ~v4 << std::endl;
  std::cout << "v2 = v1 + v3 + ~v4 => " << v2 << std::endl;
  std::cout << v3 << " cross " << 2 * v3 << " = " << v3.cross(2 * v3) << std::endl;
  std::cout << "norm " << v(3., 4.) << " = " << v(3.,4.).norm() << std::endl;
  std::cout << v(1., 1.);
  std::cout << " -> normalized = "<< v.normalized() << std::endl;
  std::cout << v << " -> orthogonal = "<< v.orthogonal() << std::endl;
  std::cout << "angle " << v << " = " << v.angle() << std::endl;
  std::cout << "PI/4 = " << cts::QUARTER_PI << std::endl;
  std::cout << v << " -> projected onto (0,-1) = "<< v.projected(vector_t::n_unit_y) << std::endl;
  std::cout << v << " dot " << v.orthogonal() << " = " << v.dot(v.orthogonal()) << std::endl;
  std::cout << "angle (-1,0) - (0,1) = " << vector_t::n_unit_x.angle(vector_t::zeros) << std::endl;
  std::cout << "/0 = " << v(2.,2.) / 0.000001 << std::endl;

  vector_t temp;
  std::vector<vector_t> v_null_list;
  v_null_list.push_back(temp(0.0F,0.0F));
  v_null_list.push_back(temp(1,0.0F));
  v_null_list.push_back(temp(0.00001F,0.0F));
  v_null_list.push_back(temp(0.00000001F,0.0F));
  v_null_list.push_back(temp(0.0000000001F,0.0F));
  v_null_list.push_back(temp(-0.0000000001F,0.0F));
  v_null_list.push_back(temp(cts::EPSILON,0.0F));
  for (unsigned int i(0); i < v_null_list.size(); ++i) {
   std::cout << v_null_list[i];
    if (vector_t::zeros != v_null_list[i]) { std::cout << " != "; }
    else { std::cout << " == "; }
    std::cout << vector_t::zeros << std::endl;
  }
}



int main()
{
  float pi(MATH_PI);

  std::cout << "simple accuracy PI = " << pi << std::endl;
  std::cout << "sac2: PI = " << cts::PI << std::endl;
  std::cout << "sac2: E = " << cts::E << std::endl;

  std::cout << abs(0.00001-0.0) << std::endl;
  float deg_angle(45);
  float rad_angle(cts::PI / 2.0);
  std::cout << "m_pi " << M_PI << "-- " << 3.1415927 << std::endl;
  std::cout << deg_angle << " deg = " << radians(deg_angle) << " rad" << std::endl;
  std::cout << rad_angle << " rad = " << degrees(rad_angle) << " deg" << std::endl;

  test_vector();

  return 0;
}