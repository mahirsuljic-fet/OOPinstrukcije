// reference parameters

#include <iostream>
#include <vector>

void show_size1(std::vector<int>);
void show_size2(std::vector<int>&);
void show_size3(const std::vector<int>&);

int main()
{
  std::vector<int> vec(1'000'000'000);

  std::cout << "Pozivam funkcije" << std::endl;

  show_size3(vec);
  show_size2(vec);
  show_size1(vec);
}

void show_size1(std::vector<int> vec) { std::cout << "show_size1: " << vec.size() << std::endl; }
void show_size2(std::vector<int>& vec) { std::cout << "show_size2: " << vec.size() << std::endl; }
void show_size3(const std::vector<int>& vec) { std::cout << "show_size3: " << vec.size() << std::endl; }
