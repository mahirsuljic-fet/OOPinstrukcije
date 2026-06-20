#include <iostream>
#include <stdexcept>
#include <vector>

struct Foo
{
    std::string x;
    Foo(const std::string& x) : x(x) { std::cout << "Pravim " << x << std::endl; }
    ~Foo() { std::cout << "Unistavam " << x << std::endl; }
};

int main()
{
  std::vector<int> vec;
  try
  {
    Foo a("a");
    Foo b("b");
    throw 385;
    Foo c("c");
    // auto _ = vec.at(10);
    // std::cout << "Sve ok :)\n";
    // throw std::out_of_range("range");
    // throw std::runtime_error("runtime");
    // throw "nesto";
    // throw 5;
  }
  catch (std::out_of_range& ex)
  {
    std::cout << "Jarane nemoj: " << ex.what() << std::endl;
  }
  catch (std::exception& ex)
  {
    std::cout << "exception: " << ex.what() << std::endl;
  }
  catch (...)
  {
    std::cout << "sve!\n";
  }
  // throw std::runtime_error("Neki razlog");
  std::cout << "kdjfgksdf" << std::endl;
}
