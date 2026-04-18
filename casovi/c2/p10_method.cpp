// method

#include <iostream>

// Funkcije koje su dio neke strukture/klase se nazivaju metodi.
// Metodi imaju istu sintaksu pri definiciji i deklaraciji kao i obične funkcije.
// Za poziv metoda je potrebno kreirati objekat.
// Poziv metoda se vrši koristeći operator . kao i kod pristupa članovima strukture/klase.
// Svaki metod ima pristup svim članovima objekta kojem pripada.
// Poziv metode nad jednim objektom nema efekta na stanje ostalih objekata.
//
// Postoje i static metodi koji imaju drugačiju sintaksu i ponašanje i izuzetci su nekim od ovih pravila, ali više o njima kasnije.

struct Tacka
{
    // Definicija metoda print strukture Tacka koji nema parametara i ne vraća ništa.
    void print()
    {
      std::cout << "Tacka:\n"
                << "  x -> " << x << "\n"
                << "  y -> " << y << "\n"
                << std::endl;
    }

    double x;
    double y;
};

int main()
{
  Tacka t { 10, 20 };
  t.print(); // poziv metoda print nad objektom t
  Tacka t1 { 5, 10 };
  t1.print(); // poziv metoda print nad objektom t
}

// napraviti metod koji vraca zbir vrijednosti x i y
