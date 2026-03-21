// c++ stl headers:
// https://en.cppreference.com/w/cpp/headers.html

#include "mymath.hpp"

#include <iostream>

int main()
{
  std::cout << "PI je " << PI << std::endl;
  std::cout << sum(10, 20) << std::endl;
  std::cout << mult(10, 20) << std::endl;
  print_secret();

  return 0;
}
