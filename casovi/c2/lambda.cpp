#include <functional>
#include <iostream>
#include <string>

int main()
{
  auto sum = [](int x, int y) {
    return x + y;
  };

  std::cout << "sum: " << sum(10, 20) << std::endl;

  //////////////////////////////////////////////////////////////////////////////////////

  std::string msg = "Hello World!";
  auto print_message = []() {
    std::cout << msg << std::endl;
  };
  print_message();

  //////////////////////////////////////////////////////////////////////////////////////

  int n = 10;
  auto print_double_n = [n] {
    n *= 2;
    std::cout << n << std::endl;
  };
  print_double_n();
  n = 20;
  print_double_n();

  //////////////////////////////////////////////////////////////////////////////////////

  auto concat_string =
    [](const std::string& s1, const std::string& s2) -> std::string { return s1 + s2; };
  concat_string(10, 20);

  //////////////////////////////////////////////////////////////////////////////////////

  std::function<int(int)> double_f = [](int x) { return 2 * x; };
  std::function<int(int)> triple_f = [](int x) { return 3 * x; };
  std::function<int(int)> square_f = [](int x) { return x * x; };

  int apply_func(int, const std::function<int(int)>&);

  int x = 10;
  std::cout << "double_f: " << apply_func(x, double_f) << std::endl;
  std::cout << "triple_f: " << apply_func(x, triple_f) << std::endl;
  std::cout << "square_f: " << apply_func(x, square_f) << std::endl;
}

int apply_func(int value, const std::function<int(int)>& func)
{
  return func(value);
}
