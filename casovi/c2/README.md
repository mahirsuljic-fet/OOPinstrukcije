## [`p01_stack_heap`](p01_stack_heap.cpp)

``` cpp
// stack i heap

int main()
{
  // Stack:
  //

  // Heap:
  //

  int stack_x = 10;

  // Stack:
  //   stack_x

  {
    // Stack:
    //   stack_x
    //
    double stack_y = 20.0;

    // Stack:
    //   stack_x
    //   stack_y
  }

  // Stack:
  //   stack_x

  // Heap:
  //

  int* heap_x = new int;
  *heap_x = 10;

  // Stack:
  //   stack_x
  //   heap_x

  // Heap:
  //   *heap_x

  {
    // Stack:
    //   stack_x
    //   heap_x

    // Heap:
    //   *heap_x

    double* heap_y = new double(20.0);

    // Stack:
    //   stack_x
    //   heap_x
    //   heap_y

    // Heap:
    //   *heap_x
    //   *heap_y
  }

  // Stack:
  //   stack_x
  //   heap_x

  // Heap:
  //   *heap_x
  //   *heap_y

  delete heap_x;

  // Stack:
  //   stack_x
  //   heap_x

  // Heap:
  //   *heap_y
}

// Stack:
//

// Heap:
//   *heap_y
```


## [`p02_string`](p02_string.cpp)

``` cpp
// string

#include <iostream>
#include <string>

int main()
{
  std::string str1;
  std::string str2 { "str2" };
  std::string str3("str3");
  std::string str4 = "str4";

  std::cout << str1.size() << ": " << str1 << std::endl;
  std::cout << str2.size() << ": " << str2 << std::endl;
  std::cout << str3.size() << ": " << str3 << std::endl;
  std::cout << str4.size() << ": " << str4 << std::endl;

  auto all = str1 + str2 + str3 + str4;
  std::cout << all.size() << ": " << all << std::endl;

  auto& nesto = str2;
  std::cout << nesto << std::endl;

  str2[2] = 'X';
  std::cout << str2 << std::endl;
  std::cout << nesto << std::endl;
}
```


## [`p03_vector`](p03_vector.cpp)

``` cpp
// vector

#include <iostream>
#include <vector>

void print_vector(std::vector<int>);

int main()
{
  std::vector<int> vec1;
  std::vector<int> vec2 = { 1, 2, 3 };
  std::vector vec3 = { 0, 1, 2, 3, 4, 5 };

  print_vector(vec1);
  print_vector(vec2);
  print_vector(vec3);

  vec3[2] = 10;
  print_vector(vec3);

  vec3.push_back(20);
  print_vector(vec3);

  vec3.pop_back();
  print_vector(vec3);

  vec3.clear();
  print_vector(vec3);
}

void print_vector(std::vector<int> vec)
{
  std::cout << vec.size() << " elemenata: ";
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << std::endl;
}
```


## [`p04_typedef`](p04_typedef.cpp)

``` cpp
int main()
{
  typedef double duzina;
  typedef double sirina;

  duzina d = 20.0;
  sirina s = 10.0;
}
```


## [`p05_using`](p05_using.cpp)

``` cpp
#include <iostream>

void pozdrav1()
{
  std::cout << "Pozdrav 1!" << std::endl;
}

void pozdrav2()
{
  using std::cout, std::endl;
  cout << "Pozdrav 2!" << endl;
}

void pozdrav3()
{
  using namespace std;
  cout << "Pozdrav 3!" << endl;
}

int main()
{
  pozdrav1();
  pozdrav2();
  pozdrav3();

  using duzina = double;
  using sirina = double;

  duzina d = 10.0;
  sirina s = 20.0;
}
```


## [`p06_function_overloading`](p06_function_overloading.cpp)

``` cpp
// Function overloading

#include <iostream>

// c++ podržava tzv. function overloading.
// Overloading podrazumijeva da se neka oznaka može koristiti na više načina.
// Ovo je jedna vrsta polimorfizma.
// Polimorfizam je sposobnost jedne stvari da se ponaša kao druga stvar (poli - više, morph - oblik,forma,transformacija).
//
// Konkretno, overloadanje funkcija omogućava da više funkcija ima isto ime.
// Overloadane funkcije se mogu razlikovati u broju i vrsti parametara.
// Mogu se razlikovati i po povratnom tipu ali ne samo po povratnom tipu (mora biti još neka razlika).

// Ovdje imamo primjer dvije funkcije.
// Obje se zovu suma i imaju dva parametra.
// Prva ima parametere i povratni tip tipa int, dok druga ima iste tipa double.
int suma(int a, int b);
double suma(double a, double b);

// Ovdje imamo primjer dvije funkcije.
// Obje se zovu pozdrav, ali jedna nema parametara, dok druga ima jedan parametar tipa std::string.
void pozdrav();
void pozdrav(std::string poruka);

///////////////////////////////////////////////////////////

int main()
{
  // Kompajler automatski zaključuje koju funkcjiu treba pozvati.
  // Vidi poziv funkcije suma i zna da ima dvije opcije:
  //   int suma(int, int);
  //   double suma(double, double);
  // Za prvi poziv vidi da su oba argumenta tipa int, pa poziva funkciju int suma(int, int);
  // Za drugi poziv vidi da su oba argumenta tipa double, pa poziva funkciju double suma(double, double);
  std::cout << "Suma 1: " << suma(10, 10) << std::endl;
  std::cout << "Suma 2: " << suma(10.5, 10.5) << std::endl;

  // Ovdje još lakše odlučuje koju funkciju da pozove jer jedna ima argument, a druga nema.
  pozdrav();
  pozdrav("test");
}

///////////////////////////////////////////////////////////

int suma(int a, int b)
{
  std::cout << "Suma int int" << std::endl;
  return a + b;
}

double suma(double a, double b)
{
  std::cout << "Suma double double" << std::endl;
  return a + b;
}

void pozdrav()
{
  std::cout << "Pozdrav!" << std::endl;
}

void pozdrav(std::string poruka)
{
  std::cout << "Pozdrav: " << poruka << "!" << std::endl;
}
```


## [`p07_reference_parameters`](p07_reference_parameters.cpp)

``` cpp
// reference parameters

#include <iostream>
#include <vector>

void show_size1(std::vector<int>);
void show_size2(std::vector<int>&);
void show_size3(const std::vector<int>&);

int main()
{
  std::vector<int> vec(1'000'000'000);

  std::cout << "Pozivam funkcije" << std::endl;

  show_size3(vec);
  show_size2(vec);
  show_size1(vec);
}

void show_size1(std::vector<int> vec) { std::cout << "show_size1: " << vec.size() << std::endl; }
void show_size2(std::vector<int>& vec) { std::cout << "show_size2: " << vec.size() << std::endl; }
void show_size3(const std::vector<int>& vec) { std::cout << "show_size3: " << vec.size() << std::endl; }
```


## [`p08_default_arguments`](p08_default_arguments.cpp)

``` cpp
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
```


## [`p09_struct`](p09_struct.cpp)

``` cpp
// struct

#include <iostream>

struct Tacka
{
    double x;
    double y;
};

int main(int argc, char* argv[])
{
  Tacka t1 = Tacka {
    10.0,
    11.0
  };

  Tacka t2 = {
    20.0,
    22.0
  };

  Tacka t3 {
    30.0,
    33.0
  };

  std::cout << "Tacka 1:\n"
            << "  x -> " << t1.x << "\n"
            << "  y -> " << t1.y << "\n"
            << std::endl;

  std::cout << "Tacka 2:\n"
            << "  x -> " << t2.x << "\n"
            << "  y -> " << t2.y << "\n"
            << std::endl;

  std::cout << "Tacka 3:\n"
            << "  x -> " << t3.x << "\n"
            << "  y -> " << t3.y << "\n"
            << std::endl;
}

// Napisati funkciju koja printa tacku

// Napraviti tacku na heap-u i isptintati je
```


## [`p10_method`](p10_method.cpp)

``` cpp
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
}

// napraviti metod koji vraca zbir vrijednosti x i y
```


## [`p11_const_methods`](p11_const_methods.cpp)

``` cpp
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
```


## [`p12_static_methods`](p12_static_methods.cpp)

``` cpp
// static methods

#include <iostream>

class Tacka
{
  public:
    static void static_pozdrav()
    {
      static unsigned long pozdrav_counter = 1;
      std::cout << "Pozdrav! Do sada je napravljeno " << counter_ << " tacaka. Metod static_pozdrav je pozvan " << pozdrav_counter << " puta." << std::endl;
      pozdrav_counter++;
    }

    void pozdrav() const
    {
      std::cout << "Pozdrav od tacke sa ID " << id_ << "." << std::endl;
    }

    Tacka(double x, double y) : x_(x), y_(y), id_(counter_++) { }

  private:
    // ignorisati ovaj komentar ispod
    // clang-format off
    static unsigned long counter_; // >>v
    unsigned long id_;             //   v
    double x_;                     //   v
    double y_;                     //   v
};                                 //   v
                                   //   v
unsigned long Tacka::counter_ = 0; // <<<
// ignorisati ovaj komentar ispod
// clang-format on

int main()
{
  Tacka t1(0, 0);
  Tacka t2(0, 0);
  Tacka t3(0, 0);

  Tacka::static_pozdrav();

  t1.static_pozdrav();
  t2.static_pozdrav();
  t3.static_pozdrav();

  t1.pozdrav();
  t2.pozdrav();
  t3.pozdrav();
}
```


## [`p13_constructor`](p13_constructor.cpp)

``` cpp
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
```


## [`p14_member_initializer_list`](p14_member_initializer_list.cpp)

``` cpp
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
```


## [`p15_encapsulation`](p15_encapsulation.cpp)

``` cpp
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
}
```


## [`p16_class`](p16_class.cpp)

``` cpp
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
```


## [`p17_destructor`](p17_destructor.cpp)

``` cpp
// destructor

#include <iostream>
#include <string>

static std::string prefix;

class Logger
{
  public:
    using ID = unsigned int;

    Logger() : id_(++id_counter)
    {
      std::cout << prefix << "Logger kreiran sa id " << id_ << std::endl;
    }

    ~Logger()
    {
      std::cout << prefix << "Logger sa id " << id_ << " unisten" << std::endl;
    }

  private:
    static ID id_counter;
    ID id_;
};

Logger::ID Logger::id_counter = 0;

void os();
void cs();

int main()
{
  Logger l1;
  Logger l2;
  Logger* l3 = new Logger();
  Logger* l4 = new Logger();

  {
    os();
    Logger l5;

    {
      os();
      Logger l6;
      cs();
    }

    Logger();

    Logger l8;
    delete l3;
    cs();
  }

  Logger l9;
}

void os() { prefix.push_back('\t'); }
void cs() { prefix.pop_back(); }
```


## [`p18_operator_overloading`](p18_operator_overloading.cpp)

``` cpp
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
```


## [`p19_lambda`](p19_lambda.cpp)

``` cpp
#include <functional>
#include <iostream>
#include <string>

// Lambda je anonimna funkcija.
// Anonimna zato jer nema ime (kao što npr. void foo(); ima ime foo).
// Zašto su korisne? Zašto ne "obične" funkcije?
// Korisne su uglavnom zbog jednostavnosti, praktičnosti i mogućnosti spremanja vrijednosti i referenciranja varijabli.
// Recimo, moguće je napraviti funkciju koja uzima drugu funkciju (koristi se češće nego što se na prvu čini).
// Npr. funkcija koja filtrira elemente u nekom kontejneru uzima neku funkciju na osnovu koje zaključuje da li element treba ostaviti u kontejneru ili ne.
// Lambda može i da "uhvati" (capture-a) "vanjske" varijable, i to po referenci ili po vrijednosti.
// Ako lambda capture-a neku varijablu po vrijednosti, ona napravi kopiju te varijable koju može kasnije koristiti.
// Ta kopija više nema nikakve veze sa orginalnom varijablom i promjena jedne ne utične na drugu.
// Analogno, ako capture-a po referenci, napravi referencu na tu varijablu koju može kasnije koristiti.
// Ta referenca i orginalna varijabla su ekvivalentne (u pogledu da pokazuju na istu stvar).
// Dakle, promjena jedne podrazumijeva promjenu i druge.
//
// Lambda ima tri glavna dijela:
// - capture clause [...]
// - lista parametara (...)
// - tijelo lambde {...}
// Sintaksa za kreiranje lambde: [varijable za capture-anje] (parametri) { izrazi }
// List parametara i tijelo lambde se koristi isto kao i kod običnih funkcija.
// U capture clause se navode varijable koje će lambda "zapamtiti".
// Ako se ispored naziva varijable doda &, onda će se ta varijabla capture-ati po referenci, u suprotnom se radi capture po vrijednosti.
// Postoje i dvije posebne capture clause:
// - [=], capture-a sve varijable vidljive u opsegu gdje se lambda kreira po vrijednosti
// - [&], capture-a sve varijable vidljive u opsegu gdje se lambda kreira po referenci
// Lambda se poziva isto kao i obična funkcija.
//
// Moguće je eksplicitno navesti povratni tip lambde dodavanjem -> TIP između liste parametara i tijela lambde,
// npr.: [](int x) -> int { return x*x; }
// Po default-u nije moguće mijenjati vrijednosti varijabli koje su capture-ane po vrijednosti.
// Ukoliko želimo promijeniti vrijednosti tih varijabli potrebno je dodati ključnu riječ mutable između liste parametara i tijela lambde,
// npr.: [x]() mutable { x = 10; }, napomena: ovdje se i dalje mijenja x iz lambde, a ne orginalni x (jer je kopija, a ne referenca)
// Ukoliko želimo eksplicitno navesti i povratni tip i označiti lambdu kao mutable, prvo se navodi mutable, pa ondat -> TIP.
//
// Interno, kompajler lambdu pretvara u klasu.
// Svaka capture-ana varijabla se pretvara u jedan član te klase.
// Ako je capture po vrijednosti onda se vrijednost varijable kopira u taj član.
// Ako je capture po referenci, taj član ima tip reference i vezuje se za datu varijablu.
// Lista parametara i tijelo funkcije se koristi za generisanje operatora ().
// Lambda se može pretvoriti u pointer na funkciju ili u std::function, ali se tipično koristi auto za zaključivanje tipa ako želimo dati ime lambdi.
// Pointeri na funkcije se gotovo nikada ne koriste u c++, to je ostalo od c jezika, umjesto toga se koristi std::function.
// Sintaksa za std::function je: std::function< POVRATNI_TIP ( TIPOVI_PATAMETARA ) >
// npr.: std::function<void(int,double)> je funkcija koja ima dva parametra, prvi je int, drugi je double i ne vraća ništa (void).
// Ukoliko je lista parametara prazna moguće je izostaviti je.

int main()
{
  auto sum = [](int x, int y) {
    return x + y;
  };

  std::cout << "sum: " << sum(10, 20) << std::endl;

  //////////////////////////////////////////////////////////////////////////////////////

  std::string msg = "Hello World!";
  auto print_message = [&msg]() {
    std::cout << msg << std::endl;
  };
  print_message();

  //////////////////////////////////////////////////////////////////////////////////////

  int n = 10;
  auto print_double_n = [n]() mutable { // pokušati capture po referenci
    n *= 2;
    std::cout << n << std::endl;
  };
  print_double_n();
  n = 20;
  print_double_n();

  //////////////////////////////////////////////////////////////////////////////////////

  auto concat_string =
    [](const std::string& s1, const std::string& s2) -> std::string { return s1 + s2; };
  concat_string("abc", "def");

  //////////////////////////////////////////////////////////////////////////////////////

  std::function<int(int)> double_f = [](int x) { return 2 * x; };
  std::function<int(int)> triple_f = [](int x) { return 3 * x; };
  std::function<int(int)> square_f = [](int x) { return x * x; };

  int apply_func(int, const std::function<int(int)>&);

  int x = 10;
  std::cout << "double_f: " << apply_func(x, double_f) << std::endl;
  std::cout << "triple_f: " << apply_func(x, triple_f) << std::endl;
  std::cout << "square_f: " << apply_func(x, square_f) << std::endl;
}

int apply_func(int value, const std::function<int(int)>& func)
{
  return func(value);
}
```
