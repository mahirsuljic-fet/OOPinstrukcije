// while:
// https://en.cppreference.com/w/cpp/language/while.html

#include <iostream>

int main()
{
  int n;

  /////////////////////////////////////////

  n = 0;
  while (n < 10)
  {
    std::cout << "n -> " << n << std::endl;
    n++;
  }
  std::cout << std::endl;

  /////////////////////////////////////////

  n = 10;
  while (!(n % 7 == 0))
  {
    n++;
  }
  std::cout << "Prvi dvocifreni broj djeljiv sa 7 je " << n << std::endl;

  /////////////////////////////////////////
  n = 0;
  while (true)
  {
    n++;
    if (n == 20) break;
    if (n >= 10 && n < 15) continue;
    std::cout << n << " ";
  }
  std::cout << std::endl;
}
