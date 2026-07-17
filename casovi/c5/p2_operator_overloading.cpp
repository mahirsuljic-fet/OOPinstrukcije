// Operator overloading i friend:
// https://en.cppreference.com/w/cpp/language/operators

#include <iostream>

// Operator overloading omogućava da nas tip (struktura/klasa) podrzava
// standardne C++ operatore (+, -, *, <<, itd.).
//
// Operatore možemo overload-ati na dva načina:
// 1. Kao METOD unutar strukture/klase (prvi argument je this)
// 2. Kao GLOBALNU FUNKCIJU (svi argumenti se navode eksplicitno)
//
// Kljucna riječ friend dozvoljava globalnoj funkciji pristup private
// članovima strukture/klase.

struct Complex
{
  public:
    Complex(double re, double im) : re_ { re }, im_ { im } { }

    // Operator + kao METOD.
    // Prvi operand (lijevi) je this, drugi (desni) je b.
    Complex operator+(const Complex& b) const
    {
      return Complex { this->re_ + b.re_, this->im_ + b.im_ };
    }

    // Operator * kao METOD: Complex * int
    Complex operator*(int x) const
    {
      return { re_ * x, im_ * x };
    }

    // Friend deklaracije: globalne funkcije ispod će moci pristupiti
    // privatinim članovima re_ i im_.
    friend Complex operator*(int x, const Complex& c);
    friend std::ostream& operator<<(std::ostream&, const Complex&);

  private:
    double re_;
    double im_;
};

// Operator * kao GLOBALNA funkcija: int * Complex
// Ovo ne može biti metod jer int nije nas tip.
// Zato nam treba friend da pristupimo re_ i im_.
Complex operator*(int x, const Complex& c)
{
  return { c.re_ * x, c.im_ * x };
}

// Operator << za ispis na std::cout (mora biti globalna funkcija).
// Zato sto je std::ostream sa LIJEVE strane operatora, a ne nas tip.
// Da je metod, pozivali bismo c.operator<<(cout) sto nije prirodno.
std::ostream& operator<<(std::ostream& out, const Complex& c)
{
  out << "re: " << c.re_ << ", im: " << c.im_;
  return out;
}

int main()
{
  Complex ca { 10, 10 };
  Complex cb { 20, 20 };

  // Complex + Complex (metod)
  auto zbir = ca + cb;
  std::cout << "Zbir: " << zbir << std::endl;

  // Complex * int (metod)
  auto umnožak1 = ca * 5;
  std::cout << "ca * 5: " << umnožak1 << std::endl;

  // int * Complex (globalna funkcija)
  auto umnožak2 = 5 * ca;
  std::cout << "5 * ca: " << umnožak2 << std::endl;
}
