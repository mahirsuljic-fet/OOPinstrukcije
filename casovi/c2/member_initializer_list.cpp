// member initializer list

#include <iostream>

// Lista za inicijalizaciju dolazi odma nakon parametara konstruktora i počinje sa :.
// Nakon : se navode članovi klase uz zagrade () ili {} putem kojih se konstruišu.
// Članovi u listi za inicijalizaciju su odvojeni zarezom (,).
// Bitna stvar je to što se prvo izvrši lista za inicijalizaciju prije ulazka u tijelo konstruktora.
// Članovi se inicijaliziraju redoslijedom kako su navedeni u listi za inicijalizaciju.
// Ukoliko se lista za inicijalizaciju izostavi članovi se definišu onako kako je navedeno u njihovoj deklaraciji i redoslijedom kako su deklarisani.

struct Tacka
{
    // Prvo se inicijalizira član x sa vrijednosti argumenta x.
    // Zatim se inicijalizira y sa vrijednosti argumenta y.
    // Ovdje nije potrebno koristiti this jer kompajler može sam zaključiti da se radi o članovima.
    // x prije zagrada se odnosi na član x, a x unutar zagrada se odnosi na parametar x.
    Tacka(double x, double y)
      : x(x), y(y) { }

    // Prvo se inicijalizira x sa vrijednosti argumenta a.
    // Nema ništa više u listi za inicijalizaciju pa se ostali članovi inicijaliziraju prema njihovim definicijama.
    // Član y ima default vrijednost 10, pa se inicijalizira na vrijednost 10.
    Tacka(double a)
      : x(a) { }

    // Prvo se vrši inicijalizacija y pa x kako je navedeno prvi deklaraciji članova.
    // y je inicijalizirano na 10
    // x je nedefenisano (jer je primitivni tip)
    // Zatim ulazimo u tijelo konstruktora gdje inicijaliziramo x.
    // U ovom slučaju korištenje x prije eksplicitne inicijalizacije unutar tijela konstruktora je nedefinisano ponašanje.
    Tacka() { x = 20; }

    void print()
    {
      std::cout << "Tacka:\n"
                << "  x -> " << x << "\n"
                << "  y -> " << y << "\n"
                << std::endl;
    }

    double y = 10;
    double x;
};

int main()
{
  Tacka t = Tacka(10, 20);
  t.print();
}
