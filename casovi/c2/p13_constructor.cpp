// constructor

#include <iostream>

// Konstruktor je metod koji ima isto ime kao i sama klasa i nema povratni tip (čak ni void).
// Konstruktor se koristi za kreiranje objekata.
// Može imati proizvoljan broj argumenata i proizvoljne tipove argumenata.
// Ovaj konstruktor ima public vidljivost što znači da bilo ko ga može koristiti.
// Tipično se u konstruktoru inicijaliziraju članovi klase.
// To se može uraditi u tijelu konstruktora (između zagrada {}) ili u listi za inicijalizaciju (više o njoj kasnije).
// Konstruktor kao i svaka funkcija obavezno mora imati tijelo (blok koda {}), pa makar bio prazan.

struct Tacka
{
    // Ovo je konstruktor klase Tacka koji ima dva parametra, oba su tipa double i imaju nazive x i y.
    Tacka(double x, double yy)
    {
      // Svaka klasa ima pointer this koji se može koristiti unutar (non-static) metoda.
      // Tipično se koristi kada je ime neke varijable dvosmisleno ili u cilju bolje čitljivosti koda.
      // U ovom primjeru imamo parametar konstruktora sa nazivom x i član klase sa nazivom x.
      // Ako bi koristili x unutar ove metode, to bi se odnosilo na parametar x, jer je on "najlokalniji".
      // Dakle, ne možemo direktno pristupiti članu x.
      // Međutim, članu x se može pristupiti preko pointera this.
      // this->x se odnosi na član x i u liniji ispod mu se dodjeljuje vrijednost argumenta proslijeđenom u konstruktor za parametar x.
      this->x = x;
      // Ovaj problem nemamo za član y, jer se parametar zove yy.
      y = yy;
      // U ovom slučaju this->y i y se odnose da istu stvari imaju identično značenje.
    }

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
  Tacka t = Tacka(10, 20);
  t.print();

  // napraviti konstruktor koji ima jedan parametar i postavlja i x i y na proslijedjeni argument
}
