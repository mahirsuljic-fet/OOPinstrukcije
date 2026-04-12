#include <climits>
#include <iostream>

int max(int a, int b, int c = INT_MIN)
{
  if (a > b && a > c) return a;
  if (b > a && b > c) return b;
  return c;
}

int main()
{
  int a = 10;
  int b = 5;
  int c = 20;

  std::cout << "max1: " << max(a, b) << std::endl;
  std::cout << "max2: " << max(a, b, c) << std::endl;
}
