// Function overloading

#include <iostream>

int suma(int a, int b);
double suma(double a, double b);

void pozdrav();
void pozdrav(std::string poruka);

///////////////////////////////////////////////////////////

int main()
{
  std::cout << "Suma 1: " << suma(10, 10) << std::endl;
  std::cout << "Suma 2: " << suma(10.5, 10.5) << std::endl;

  pozdrav();
  pozdrav("test");
}

///////////////////////////////////////////////////////////

int suma(int a, int b)
{
  std::cout << "Suma int int" << std::endl;
  return a + b;
}

double suma(double a, double b)
{
  std::cout << "Suma double double" << std::endl;
  return a + b;
}

void pozdrav()
{
  std::cout << "Pozdrav!" << std::endl;
}

void pozdrav(std::string poruka)
{
  std::cout << "Pozdrav: " << poruka << "!" << std::endl;
}
