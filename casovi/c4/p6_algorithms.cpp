#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
  std::vector<int> vec = { 5, 3, 1, 9, 7, 2, 4 };

  // auto lambda = [](int lijevi, int desni) { return lijevi > desni; };
  // std::sort(vec.begin(), vec.end(), lambda);

  // auto it = std::find(vec.begin(), vec.end(), 2);
  // if (it != vec.end())
  //   std::cout << "Broj je na " << (it - vec.begin()) << " ideksu" << std::endl;
  // else
  //   std::cout << "Broja nema" << std::endl;

  auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
  std::cout << "Prvi parni je " << *it << std::endl;
  // if (it != vec.end())
  //   vec.erase(it);

  for (auto el : vec)
    std::cout << el << " ";
  std::cout << std::endl;
}
