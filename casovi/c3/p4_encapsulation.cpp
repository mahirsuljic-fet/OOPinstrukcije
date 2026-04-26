// encapsulation

#include <iostream>

// U praksi se javlja potreba za skrivanjem implementacije dijelova programa.
// Ovo se tipično radi zbog sigurnosti i/ili pojednostavljenja korištenja datog koda.
// To skrivanje implementacije se naziva enkapsulacija.
// Jedna vrlo česta primjena enkapsulacije je nad članovima klase/strukture.
// Recimo da želimo onemogućiti korisniku da promijeni stanje nekog člana.
// Ili npr. da promijeni samo sve članove istovremeno.
// Ili npr. imamo strukturu Tacka i želimo omogućiti promjenu koordinata tačke na kartezijeve koordinate i polarne koordinate.
// Sve ovo nam omogućava enkapsulacija.
// Skrivanjem implementacije i ograničavanja čemu korisnik ima pristup osiguravamo da naši objekti se ponašaju tačno onako kako želimo.
// Za još jedan primjer zamislimo neku klasu koja pohranjuje objekte.
// Ta klasa recimo ima član koji govori koliko je pohranjeno objekata.
// Bez enkapsulacije korisnik može da promijeni taj član i da kaže da je u objektu te klase pohranjeno više ili manje objektana nego što stvarno jeste.
// Ovime se narušava stabilnost cijelog sistema i cijeli objekat koji se koristi za pohranu postaje nevalidan.
//
// Glavni oblik enkapsulacije je korištenem tzv. access modifiers, odnosno modifikatora pristupa.
// U c++ postoje tri:
// - public, vidljivo svima
// - private, vidljivo samo unutar klase
// - protected, vidljivo unutar klase i u naslijeđenim klasama, ovo ćemo za sada ignorisati
// Tipično konstruktori i većina metoda se podese tako da imaju public pristup dok članovi imaju private pristup.

struct Tacka
{
  public: // sve nakon ovoga ima public pristup
    Tacka(double x, double y)
      : x_(x), y_(y) { }

    void print()
    {
      std::cout << "Tacka:\n"
                << "  x -> " << x_ << "\n"
                << "  y -> " << y_ << "\n"
                << std::endl;
    }

    // Vrlo često se kreiraju metodi koji vraćaju vrijednosti nekih članova klase.
    // Ti metodi se nazivaju getteri (kao get, dohvati) i omogućavaju pristup vrijednostima private članova.
    // Analogno mogu se kreirati i metodi koji postavljaju vrijednosti članova i nazivaju se setteri (kao set, postavi).
    double get_x() { return x_; }
    double get_y() { return y_; }
    void set_x(double novi_x) { x_ = novi_x; }
    void set_y(double novi_y) { y_ = novi_y; }

  private: // sve nakon ovoga ima private pristup
    // Često se može vidjeti da private članovi (i metode) imaju sufix ili prefix _, kao članovi x_ i y_ ispod.
    // Ovime se povećava čitljivost koda jer omogućava da pogledom na ime člana zaključimo da li je private ili public.
    double x_;
    double y_;
};

int main()
{
  Tacka t = Tacka(10, 20); // ok jer je konstruktor Tacka(double,double) public
  t.print();               // ok jer je metod print public
  // std::cout << t.x_ << std::endl; // pristup nije moguć jer je x_ private
  std::cout << t.get_x() << std::endl; // ok jer je metod get_x public

  // napraviti set metode (settere) za x_ i y_
  t.set_x(30);
  t.set_y(30);
  t.print();
}
