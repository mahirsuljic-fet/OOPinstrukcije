#include <iostream>

// Pored funkcija i metoda moguće je overloadati i operatore.
// Operator u c++ je funkcija.
// Operatore je moguće overloadati na dva načina:
// - kao metod, podrazumijeva objekat nad kojem se poziva operator kao prvi argument
// - kao funkciju, zahtijeva eksplicitno navođenje parametara

struct Tacka
{
    // Overloadanje operatora + za strukturu Tacka.
    // Podrazumijeva se da je objekat na kojem se poziva operator + (s lijeva od +) prvi argument.
    // Dakle, potrebno je samo navesti jedan parametar koji predstavlja objekat koji se nalazi sa desne strane operatora +.
    // U ovom slučaju operator + uzima objekta tipa Tacka po referenci s lijeve strane, objekat tipa Tacka po const referenci sa desne strane i vraća objekat tipa Tacka.
    Tacka operator+(const Tacka& other)
    {
      Tacka nova_tacka = {
        this->x + other.x,
        this->y + other.y
      };

      return nova_tacka;
    }

    // Isto kao i za operator +.
    Tacka operator-(const Tacka& other)
    {
      return Tacka {
        this->x - other.x,
        this->y - other.y
      };
    }

    // Isto kao i za operator +, ali uzima cijeli broj sa desne strane.
    // Potrebno je napomenuti da samo sa ovom definicijom operatora * nije moguće da se napiše: 5 * t, gdje je t tipa Tacka.
    // To je zato jer ova definicija zahtijeva da je s lijeve strane operatora * tip Tacka, a sa desne tip int.
    Tacka operator*(int n)
    {
      return {
        x * n,
        y * n,
      };
    }

    void print()
    {
      std::cout << "Tacka:\n"
                << "  x -> " << x << "\n"
                << "  y -> " << y << "\n"
                << std::endl;
    }

    double x, y;
};

// Ukoliko operator definišemo izvan strukture potrebno je navesti sve parametre.
// Prvi parametar predstavlja objekat s lijeve strane operatora *, a drugi sa desne strane.
// Ova definicija omogućava pisanje npr.: 5 * t, gdje je t tipa Tacka
Tacka operator*(int n, const Tacka& tacka)
{
  return {
    tacka.x * n,
    tacka.y * n,
  };
}

int main()
{
  Tacka t1 = { 10, 20 };
  Tacka t2 = { 20, 30 };

  t1.print();
  t2.print();

  Tacka zbir = t1 + t2;
  Tacka razlika = t1 - t2;
  Tacka umnozak1 = t1 * 2;
  Tacka umnozak2 = 2 * t1;

  zbir.print();
  razlika.print();
  umnozak1.print();
  umnozak2.print();
}
