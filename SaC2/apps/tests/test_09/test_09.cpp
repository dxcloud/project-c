#include <iostream>

#include <sac2_bounding_box.hpp>
#include <sac2_bounding_circle.hpp>

using namespace sac2;

void test_box()
{
  point_t p1(0.5,0.5);
  point_t p2(2.,2.);
  BoundingBox b1(p1, p2), b2(0., 0., 1., 1.);

  std::cout << b1.get_center() << std::endl;
  std::cout << b2.get_center() << std::endl;

  if (b1.intersect(b2)) {
    std::cout << "Collision !!" << std::endl;
  }
  BoundingBox b3;
  b2 = b3;

  if (!b1.intersect(b2)) {
    std::cout << "No Collision !!" << std::endl;
  }
}

void test_circle()
{
  point_t p(0.0F, 0.0F);
  float r(1.0F);
  BoundingCircle c1(p, r);
  BoundingCircle c2(c1);
  std::cout << c1.get_center() << std::endl;
  std::cout << c2.get_center() << std::endl;
  std::cout << distance(c1.get_center(), c2.get_center()) << std::endl;
  if (c1.intersect(c2)) {
    std::cout << "Collision !!" << std::endl;
  }
  BoundingCircle c3;
  c2 = c3;
  c2(0.0,2.0,1.0);
  std::cout << c2.get_center() << std::endl;
  std::cout << distance(c1.get_center(), c2.get_center()) << std::endl;
  if (!c1.intersect(c2)) {
    std::cout << "No Collision !!" << std::endl;
  }
}

int main()
{
  test_box();
  std::cout << "test_circle" << std::endl;
  test_circle();

  return 0;
}
