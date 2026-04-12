// string

#include <iostream>
#include <string>

int main()
{
  std::string str1;
  std::string str2 { "str2" };
  std::string str3("str3");
  std::string str4 = "str4";

  std::cout << str1.size() << ": " << str1 << std::endl;
  std::cout << str2.size() << ": " << str2 << std::endl;
  std::cout << str3.size() << ": " << str3 << std::endl;
  std::cout << str4.size() << ": " << str4 << std::endl;

  auto all = str1 + str2 + str3 + str4;
  std::cout << all.size() << ": " << all << std::endl;

  auto& nesto = str2;
  std::cout << nesto << std::endl;

  str2[2] = 'X';
  std::cout << str2 << std::endl;
  std::cout << nesto << std::endl;
}
