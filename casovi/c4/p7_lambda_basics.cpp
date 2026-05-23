#include <iostream>
#include <string>

int main()
{
  auto lambda = [](const std::string& str) { std::cout << str << std::endl; };
  lambda("foo");
}
