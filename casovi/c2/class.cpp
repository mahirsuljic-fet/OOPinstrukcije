// class

#include <iostream>

// Klasa je šablon za kreiranje objekata.
// Koristi se za modeliranje nekih realnih ili apstraktnih stvari, ili grupisanje funkcioalnosti.
// Klase mogu imati metode i članove (polja).
// Posebni metodi koje klasa može imati su konstruktori i overload-ani operatori.
// Konstruktori služe za kreiranje objekta te klase.
// Overloadani operatori služe za pojednostavljenje korištenja nekih funkcionalnosti (npr. omogućavaju pisanje a + b umjesto sum(a,b)).
// Default vidljivost u klasama (class) je private, dok je u strukturama (struct) public.
// Default vidljivost je glavna razlika između class i struct.
// Sve što vrijedi za klase vrijedi i za strukture.
// Tipično se klase koriste za kompleksnije tipove, dok se strukture koriste za grupisanje srodnih podataka
// (npr. može se sačuvati tačku kao strukturu umjesto dvije varijable za x i y).

// Klasa se kreira sa:
// class NAZIV {
//    ...
// };
// Obavezno je na kraju staviti ;.
class Tacka
{
    // Kreiranje metoda izgleda isto kao definicija funkcije.
    // Moguće je i razdvojiti deklaraciju i implementaciju kao i u običnim funkcijama.
    // Metod test je private (vidljiv samo unutar klase) jer nismo drugačije rekli, a default vidljivost u klasi je private.
    void test() { std::cout << "Test" << std::endl; }

  public:                     // sve nakon ovoga ima vidljivost public dok se drugačije ne kaže
    Tacka(double x, double y) // Ovo je konstruktor klase Tacka koji prima dva argumenta tipa double: x i y.
      : x_(x), y_(y)          // član x_ klase Tacka se konstruiše sa vrijednosti argumenta x, a y_ sa y.
    {                         // Nema potrebe da išta više radimo, svi članovi su inicijalizirani, pa je tijelo konstruktora prazno.
    }

    // Metod print je public jer se nalazi nakon public:.
    void print()
    {
      std::cout << "Tacka:\n"
                << "  x -> " << x_ << "\n"
                << "  y -> " << y_ << "\n"
                << std::endl;
    }

    // Metod print_and_increment je public metod koji poziva dva druga metoda: print i increment.
    // Metod print je isto public, a increment je private.
    // Private metodi se mogu koristiti unutar klase (npr. u drugom metodu kao ovdje), ali ne izvan klase.
    void print_and_increment()
    {
      print();
      increment();
    }

    double get_x() { return x_; }
    double get_y() { return y_; }

  private: // svi metodi i članovi nakon ovoga su private
    // Članovi x_ i y_ su private što znači da im je moguće prisupiti samo unutar klase.
    double x_;
    double y_;

    // Metod increment je private metod što znači da ga je moguće pozvati samo unutar klase.
    void increment()
    {
      x_++;
      y_++;
    }
};

int main()
{
  // Kreiranje objekta t tipa Tacka koristeći konstruktor Tacka(double,double).
  // x_ dobija vrijednost 10
  // y_ dobija vrijednost 20
  Tacka t = Tacka(10, 20);

  // Poziv public metoda print nad objektom t.
  t.print();

  // std::cout << t.x_ << std::endl;   // Ovaj pristup članu bi rezultovao greškom jer je član x_ private.
  std::cout << t.get_x() << std::endl; // Dohvatanje vrijednosti od x_ putem gettera.

  // Poziv metoda print_and_increment nad objektom t što rezultuje promjenom stanja objekta t.
  t.print_and_increment(); // x_ je sada 11, a y_ je 21
  t.print_and_increment(); // x_ je sada 12, a y_ je 22

  // Poziv metoda increment ili test bi rezultovalo greškom jer su private.
  // t.increment();
  // t.test();
}
