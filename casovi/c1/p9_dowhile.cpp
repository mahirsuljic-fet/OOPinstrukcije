// do-while:
// https://en.cppreference.com/w/cpp/language/do.html

#include <iostream>

int main()
{
  do
  {
    std::cout << "Hello World!" << std::endl;
  }
  while (false);

  ///////////////////////////////////////////

  std::cout << "do-while:" << std::endl;
  int n = 0;
  do
  {
    std::cout << n << " ";
  }
  while (++n < 10);
  std::cout << std::endl;

  std::cout << "while:" << std::endl;
  n = 0;
  while (++n < 10)
    std::cout << n << " ";
  std::cout << std::endl;
}
