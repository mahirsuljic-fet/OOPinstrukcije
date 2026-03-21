// static:
// https://en.cppreference.com/w/cpp/language/storage_duration.html

#include <iostream>

int i = 10;
static int si = 10;
extern int ei;

int foo()
{
  static int x = 20;
  x += 10;
  return x;
}

int bar()
{
  int x = 20;
  x += 10;
  return x;
}

int main()
{
  std::cout << "foo1: " << foo() << std::endl;
  std::cout << "foo2: " << foo() << std::endl;
  std::cout << "foo3: " << foo() << std::endl;

  std::cout << "bar1: " << bar() << std::endl;
  std::cout << "bar2: " << bar() << std::endl;
  std::cout << "bar3: " << bar() << std::endl;
}
