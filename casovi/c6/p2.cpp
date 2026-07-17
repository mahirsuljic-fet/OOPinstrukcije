#include <functional>
#include <iostream>
#include <vector>

template <typename T>
T mnozi(T x, T y) { return x * y; }

template <typename Tip, typename Lambda>
void pozovi_lambdu(const Tip& vrijednost, const Lambda& lambda)
{
  lambda(vrijednost);
}

int main(int argc, char* argv[])
{
  // pozovi_lambdu(20, [](int x) { std::cout << x << std::endl; });
  // pozovi_lambdu(
  //   "test",
  //   [](std::string x) {
  //     std::cout << x << std::endl;
  //     return 10; });

  mnozi(10, 20);

  return 0;
}
