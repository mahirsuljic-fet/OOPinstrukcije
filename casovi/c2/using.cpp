#include <iostream>

void pozdrav1()
{
  std::cout << "Pozdrav 1!" << std::endl;
}

void pozdrav2()
{
  using std::cout, std::endl;
  cout << "Pozdrav 2!" << endl;
}

void pozdrav3()
{
  using namespace std;
  cout << "Pozdrav 3!" << endl;
}

int main()
{
  pozdrav1();
  pozdrav2();
  pozdrav3();

  using duzina = double;
  using sirina = double;

  duzina d = 10.0;
  sirina s = 20.0;
}
