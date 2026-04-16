#include <iostream>

// c++ podržava default argumente za parametre.
// To znači da ako se pri pozivu funkcije ne proslijedi argument za taj parametar koristit će se default argument.
// Default argument se daje tako što nakon deklaracije parametra se doda = VRIJEDNOST (u primjeru ispod = 0).
// Ovo omogućava korištenje različitog broja argumenata pri pozivu funcije bez overloadanja iste.
// Moguće je imati više default argumenata, ali u tom slučaju svi parametri desno od njega moraju također imati default argumente.
// Npr.:
//   void funkcija(int x, int y = 10, int z = 20) je ok
//   void funkcija(int x, int y = 10, int z) nije validno (ne bi bilo moguće izostaviti z pri pozivu funkcije pa je i defualt argument za y besmislen)
unsigned int max(unsigned int a, unsigned int b, unsigned int c = 0)
{
  if (a > b && a > c) return a;
  if (b > a && b > c) return b;
  return c;
}

int main()
{
  unsigned int a = 10;
  unsigned int b = 5;
  unsigned int c = 20;

  std::cout << "max1: " << max(a, b) << std::endl;    // poziv bez argumenta za c, koristi se default argument c = 0
  std::cout << "max2: " << max(a, b, c) << std::endl; // poziv sa argumentom za c, koristi se c = 20
}
