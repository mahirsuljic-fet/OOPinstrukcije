// Function overloading

#include <iostream>

// c++ podržava tzv. function overloading.
// Overloading podrazumijeva da se neka oznaka može koristiti na više načina.
// Ovo je jedna vrsta polimorfizma.
// Polimorfizam je sposobnost jedne stvari da se ponaša kao druga stvar (poli - više, morph - oblik,forma,transformacija).
//
// Konkretno, overloadanje funkcija omogućava da više funkcija ima isto ime.
// Overloadane funkcije se mogu razlikovati u broju i vrsti parametara.
// Mogu se razlikovati i po povratnom tipu ali ne samo po povratnom tipu (mora biti još neka razlika).

// Ovdje imamo primjer dvije funkcije.
// Obje se zovu suma i imaju dva parametra.
// Prva ima parametere i povratni tip tipa int, dok druga ima iste tipa double.
int suma(int a, int b);
double suma(double a, double b);

// Ovdje imamo primjer dvije funkcije.
// Obje se zovu pozdrav, ali jedna nema parametara, dok druga ima jedan parametar tipa std::string.
void pozdrav();
void pozdrav(std::string poruka);

///////////////////////////////////////////////////////////

int main()
{
  // Kompajler automatski zaključuje koju funkcjiu treba pozvati.
  // Vidi poziv funkcije suma i zna da ima dvije opcije:
  //   int suma(int, int);
  //   double suma(double, double);
  // Za prvi poziv vidi da su oba argumenta tipa int, pa poziva funkciju int suma(int, int);
  // Za drugi poziv vidi da su oba argumenta tipa double, pa poziva funkciju double suma(double, double);
  std::cout << "Suma 1: " << suma(10, 10) << std::endl;
  std::cout << "Suma 2: " << suma(10.5, 10.5) << std::endl;

  // Ovdje još lakše odlučuje koju funkciju da pozove jer jedna ima argument, a druga nema.
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
