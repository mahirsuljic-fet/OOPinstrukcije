// Osnovno vezano za funkcije:
// https://en.cppreference.com/w/cpp/language/functions.html

#include <iostream>

void hello()
{
  std::cout << "Hello World!" << std::endl;
}

int getTen()
{
  return 10;
}

int sum(int a, int b)
{
  return a + b;
}

void foo();
void bar(int x);
void tar(int);

int main()
{
  hello();

  int ten = getTen();
  int result = sum(10, 20);

  foo();
  bar(10);
  tar(20);

  return 0;
}

void foo() { std::cout << "foo" << std::endl; }

void bar(int n) { std::cout << "bar: " << n << std::endl; }

void tar(int n) { std::cout << "tar: " << n << std::endl; }
