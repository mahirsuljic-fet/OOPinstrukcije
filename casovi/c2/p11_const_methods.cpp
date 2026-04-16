#include <iostream>

// Svaku varijablu, pa time i svaki objekat u c++ je moguće označiti kao const.
// Time dajemo obećanje da se ta vrijabla neće mijenjati.
// Međutim metodi imaju mogućnost mijenjanja stanja objekta.
// Pozivanjem metoda koji potencijalno mijenja stanje objekta na const objektu bi se narušilo to obećanje.
// Zbog toga, nad const objektima je moguće pozivati samo const metode (i static, ali o njima ćemo govoriti kasnije).
// Metoda se označava konstantnom stavljanjem ključne riječi const nakon liste parametara.
// Unutar const metode nije moguće mijenjati vrijednosti članova klase (promijeniti stanje objekta).
// Const metode se mogu pozivati i na ne-const objektima, ali obrnuto ne važi.
// Moguće je napraviti overload metoda po konstantnosti (isti potpis metoda osim što je jedan const, a drugi ne) i ovo je česta praksa.

class Tacka
{
  public:
    Tacka(double x, double y) : x_(x), y_(y) { }

    // non-const metod pozdrav
    void pozdrav()
    {
      std::cout << "Pozdrav!" << std::endl;
      // x_++; // ok
    }

    // const metod pozdrav
    void pozdrav() const
    {
      std::cout << "Const pozdrav!" << std::endl;
      // x_++; // greška
    }

    void non_const_metod() { }
    void const_metod() const { }

  private:
    double x_;
    double y_;
};

int main()
{
  Tacka t1 { 10, 10 };
  const Tacka t2 { 10, 10 };

  t1.non_const_metod();    // ok
  t1.const_metod();        // ok
  // t2.non_const_metod(); // error jer je t2 const, a non_const_metod nije const
  t2.const_metod();        // ok

  t1.pozdrav(); // poziva non-const pozdrav
  t2.pozdrav(); // poziva const pozdrav
}
