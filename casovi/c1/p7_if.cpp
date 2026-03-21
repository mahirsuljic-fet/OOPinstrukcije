// if:
// https://en.cppreference.com/w/cpp/language/if.html

#include <iostream>

int main()
{
  int x = 10;

  //////////////////////////////////////////////////////////////////////////////

  if (x == 10)
  {
    std::cout << "x je 10" << std::endl;
  }
  else
  {
    std::cout << "x nije 10" << std::endl;
  }

  //////////////////////////////////////////////////////////////////////////////

  if (true)
    std::cout << "Uvijek se ispisuje" << std::endl;

  if (false)
    std::cout << "Nikad se ne ispisuje" << std::endl;

  //////////////////////////////////////////////////////////////////////////////

  if (x == 20)
    std::cout << "x je 10" << std::endl;
  else if (x % 2 == 0)
    std::cout << "x nije 10, ali je djeljiv sa 2 (paran je)" << std::endl;
  else
    std::cout << "x nije ni 10, niti je djeljiv sa 2 (neparan je)" << std::endl;

  //////////////////////////////////////////////////////////////////////////////

  if (x % 3 == 0)
  {
    if (x % 2 == 0)
      std::cout << "x je djeljiv i sa 3 i sa 2" << std::endl;
    else
      std::cout << "x je djeljiv sa 3, ali ne i sa 2" << std::endl;
  }
  else
    std::cout << "x nije djeljiv sa 3" << std::endl;
}
