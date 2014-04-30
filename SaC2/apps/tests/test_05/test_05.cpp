#include <iostream>
#include <iomanip>

#include <sac2_status.hpp>
#include <sac2_version.hpp>

using namespace sac2;

int main()
{

  // Size of SaC2 typedef type
  std::cout << "uint8_t: " << sizeof(uint8_t) << std::endl;
  std::cout << "uint16_t: " << sizeof(uint16_t) << std::endl;
  std::cout << "uint32_t: " << sizeof(uint32_t) << std::endl;
  std::cout << "uint64_t: " << sizeof(uint64_t) << std::endl;
  std::cout << "nullptr: " << sizeof(nullptr) << "; " << sizeof(0) << std::endl;

  // Version
  Version v1;
  Version v2(1, 2, 3, 4);
  Version v3(v2);
  std::cout << "Version: " << v1.info() << " and " << v2.info() << std::endl;
  std::cout << "Version number: " << std::setbase(16) << v3() << std::endl;

  v3(MAJOR) = 5;
  std::cout << "Version major: " << (uint32_t) v3(MAJOR) << std::endl;

  if (v1 != v3) { std::cout << "Different version! " << std::endl; }
  if (v1 < v3) { std::cout << v1.info() << " < " << v3.info() << std::endl; }
  v1 = v3;
  if (v3 >= v1) { std::cout << v3.info() << " >= " << v1.info() << std::endl; }

  // Status code
  Status s1(33);
  std::cout << "s1 - status code: " << s1() << std::endl;
  Status s2;
  std::cout << "s2 - status code: " << s2() << std::endl;
  s2 = 1;
  std::cout << "s2 - status code: " << s2() << std::endl;
  s2 = STATUS_ALREADY;
  std::cout << "s2 - status code: " << s2() << std::endl;

  if (s1 != s2) { std::cout << s1() << " != " << s2() << std::endl; }
  s2 = s1;
  std::cout << Status::status_info(s1()) << std::endl;
  if (s1 == s2) { std::cout << s1() << " == " << s2() << std::endl; }

  Status::print_status_table();
  std::cout << "Status: " << Status::status_info(Status::status_cast(5)) << std::endl;
  return 0;
}
