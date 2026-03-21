// for:
// https://en.cppreference.com/w/cpp/language/for.html

#include <iostream>

int main()
{
  for (int i = 0; i < 10; i++)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  /////////////////////////////////////

  for (int i = 0; i < 10; i += 2)
    std::cout << i << " ";
  std::cout << std::endl;

  /////////////////////////////////////

  int i = 0;
  for (; i < 10; i += 2)
    std::cout << i << " ";
  std::cout << std::endl;

  /////////////////////////////////////

  i = 0;
  for (; i < 10;)
    std::cout << i++ << " ";
  std::cout << std::endl;

  /////////////////////////////////////

  for (int i = 0; i < 10; ++i)
  {
    if (i == 5) break;
    std::cout << i << " " << std::endl;
  }
  std::cout << std::endl;

  /////////////////////////////////////

  for (int i = 0; i < 10; ++i)
  {
    if (i == 5) continue;
    std::cout << i << " " << std::endl;
  }
  std::cout << std::endl;
}
