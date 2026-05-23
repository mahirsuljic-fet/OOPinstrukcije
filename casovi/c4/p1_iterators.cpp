#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  for (auto it = vec.begin(); it != vec.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  for (auto it = vec.cbegin(); it < vec.cend(); it += 2)
    std::cout << *it << " ";
  std::cout << std::endl;

  for (auto el : vec)
    std::cout << el << " ";
  std::cout << std::endl;
  
  for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  for (auto it = vec.crbegin(); it != vec.crend(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}
