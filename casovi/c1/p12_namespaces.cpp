// Namespace:
// https://en.cppreference.com/w/cpp/language/namespace.html

#include <iostream>

int n = 10;

namespace Foo
{

int n = 20;
int x = 20;

namespace Bar
{
  int n = 30;
  int x = 30;
} // Bar end

} // Foo end

int main()
{
  std::cout << "n -> " << n << std::endl;
  std::cout << "::n -> " << ::n << std::endl;

  std::cout << "Foo::n -> " << Foo::n << std::endl;
  std::cout << "Foo::x -> " << Foo::x << std::endl;

  std::cout << "Foo::Bar::n -> " << Foo::Bar::n << std::endl;
  std::cout << "Foo::Bar::x -> " << Foo::Bar::x << std::endl;

  using namespace Foo;

  // std::cout << "using Foo, n -> " << n << std::endl;
  std::cout << "using Foo, x -> " << x << std::endl;
  std::cout << "using Foo, Bar::n -> " << Bar::n << std::endl;
  std::cout << "using Foo, Bar::x -> " << Bar::x << std::endl;
}
