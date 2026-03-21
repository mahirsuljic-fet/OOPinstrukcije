// Scope:
// https://en.cppreference.com/w/cpp/language/scope.html

#include <iostream>

int a = 10;

int main()
{
  std::cout << a << std::endl;

  int a = 20;
  std::cout << a << std::endl;

  {
    a = 33;

    double a = 30.2;
    std::cout << a << std::endl;
  }

  std::cout << a << std::endl;
}
