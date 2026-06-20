#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v1(100000000);
  // ...
  // std::vector<int> v2 = v1; // std::vector&
  std::vector<int> v2 = std::move(v1); // std::vector&&

  return 0;
}
