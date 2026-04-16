// vector

#include <iostream>
#include <vector>

void print_vector(std::vector<int>);

int main()
{
  std::vector<int> vec1;
  std::vector<int> vec2 = { 1, 2, 3 };
  std::vector vec3 = { 0, 1, 2, 3, 4, 5 };

  print_vector(vec1);
  print_vector(vec2);
  print_vector(vec3);

  vec3[2] = 10;
  print_vector(vec3);

  vec3.push_back(20);
  print_vector(vec3);

  vec3.pop_back();
  print_vector(vec3);

  vec3.clear();
  print_vector(vec3);
}

void print_vector(std::vector<int> vec)
{
  std::cout << vec.size() << " elemenata: ";
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << std::endl;
}
