#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
  std::list<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  auto ins = std::front_inserter(vec);

  *ins = 10;
  *ins = 20;
  *ins = 30;
  *ins = 40;
  *ins = 50;
  *ins = 60;

  for (auto el : vec)
    std::cout << el << " ";
  std::cout << std::endl;
}

