#include <iostream>

struct Foo
{
    explicit Foo(const char* x) { }
};

void func(Foo) { std::cout << "Foo" << std::endl; }
void func(std::string) { std::cout << "string" << std::endl; }

int main()
{
  func("test");
}
