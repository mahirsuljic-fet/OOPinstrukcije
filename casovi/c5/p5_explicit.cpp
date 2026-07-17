// explicit konstruktor:
// https://en.cppreference.com/w/cpp/language/explicit

#include <iostream>
#include <string>

// Kljucna riječ explicit ispred konstruktora sprečava implicitnu konverziju.
// Implicitna konverzija je kada kompajler automatski pretvara jedan tip u drugi.
// To može biti korisno, ali može prouzrokovati i neočekivano ponašanje.

struct Broj
{
    // Konstruktor BEZ explicit - dozvoljava implicitnu konverziju
    Broj(int x)
    {
      std::cout << "Broj(" << x << ")" << std::endl;
    }
};

struct EksplicitniBroj
{
    // Konstruktor SA explicit - NE dozvoljava implicitnu konverziju
    explicit EksplicitniBroj(int x)
    {
      std::cout << "EksplicitniBroj(" << x << ")" << std::endl;
    }
};

void func(Broj b)
{
  std::cout << "func(Broj)" << std::endl;
}

void func(std::string s)
{
  std::cout << "func(string)" << std::endl;
}

void func_eksplicitni(EksplicitniBroj eb)
{
  std::cout << "func(EksplicitniBroj)" << std::endl;
}

int main()
{
  // Implicitna konverzija: int se pretvara u Broj
  Broj b1 = 42;      // poziva Broj(42) automatski
  Broj b2 { 42 };
  func(100);          // 100 se pretvara u Broj

  std::cout << std::endl;

  // explicit sprečava implicitnu konverziju:
  // EksplicitniBroj eb1 = 42;  // GREŠKA!
  // func_eksplicitni(100);     // GREŠKA!

  // Moramo eksplicitno pozvati konstruktor:
  EksplicitniBroj eb1 { 42 };
  EksplicitniBroj eb2(42);
  func_eksplicitni(EksplicitniBroj(100));

  std::cout << std::endl;

  // Zašto je explicit koristan?
  // Bez explicit, "test" bi se mogao pretvoriti u Foo, a mi to ne želimo:
  struct Foo
  {
      explicit Foo(const char* x) { }
  };

  func("test"); // poziva func(string), ne func(Broj) - radi zahvaljujuci explicit

  // Jos jedan primjer:
  // std::vector<int> v = 5;   // GREŠKA: vector(int) je explicit
  // std::string s = 'a';      // GREŠKA: string(char) je explicit
}
