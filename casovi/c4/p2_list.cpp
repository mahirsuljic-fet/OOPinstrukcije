#include <forward_list>
#include <iostream>
#include <list>

int main()
{
  std::list<int> lista = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  lista.begin()++;
  lista.begin()--;

  for (auto it = lista.begin(); it != lista.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}
