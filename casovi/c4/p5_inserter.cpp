#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  auto ins = std::inserter(vec, vec.begin());

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
