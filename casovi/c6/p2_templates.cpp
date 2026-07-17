// Template (generički tipovi):
// https://en.cppreference.com/w/cpp/language/templates

#include <cstring>
#include <iostream>
#include <string>

// Template je šablon za kreiranje funkcija ili klasa.
// Umjesto da pišemo istu funkciju za int, double, string,... napišemo je
// jednom sa parametrom T i kompajler sam generiše posebnu verziju za svaki tip.
//
// Kako kompajler odabere koju funkciju da pozove:
// 1. Traži FUNKCIJU SA TAČNO ISTIM POTPISOM (exact match)
// 2. Ako nema, pokušava TEMPLATE funkciju
// 3. Ako ni to ne uspije, pokušava IMPLICITNU KONVERZIJU
// 4. Ako ništa ne radi -> GREŠKA (compilation error)
//
// Kada pozovemo template funkciju, kompajler na osnovu argumenta
// zaključi koji je T i GENERISE tu funkciju za taj tip.
// Ovo se dešava u vrijeme kompilacije, nema overhead-a u runtime-u.

// Template funkcija - T će se zaključiti na osnovu argumenta
template <typename T>
T maksimum(T a, T b)
{
  return (a > b) ? a : b;
}

// Template funkcija sa dva različita tipa
template <typename T, typename U>
auto zbir(T a, U b)
{
  return a + b;
}

// Template funkcija koja prima lambdu:
// Lambda je anonimna funkcija, svaka lambda ima JEDINSTVENI tip.
// Zato pišemo template: da prihvatimo bilo koji tip lambde.
template <typename Tip, typename Lambda>
void primijeni(const Tip& vrijednost, Lambda lambda)
{
  lambda(vrijednost);
}

// Template klasa
template <typename T>
class Pair
{
  public:
    Pair(T prvi, T drugi) : prvi_(prvi), drugi_(drugi) { }
    T prvi() const { return prvi_; }
    T drugi() const { return drugi_; }

  private:
    T prvi_;
    T drugi_;
};

// Obična funkcija (non-template) - za poređenje sa template-om
int maksimum_int(int a, int b)
{
  return (a > b) ? a : b;
}

// Specijalizacija: ako bas želimo drugačije ponašanje za određeni tip
template <>
const char* maksimum<const char*>(const char* a, const char* b)
{
  return (std::strcmp(a, b) > 0) ? a : b;
}

int main()
{
  // Kompajler zaključuje T = int
  std::cout << "maksimum(10, 20): " << maksimum(10, 20) << std::endl;

  // Kompajler zaključuje T = double
  std::cout << "maksimum(3.14, 2.71): " << maksimum(3.14, 2.71) << std::endl;

  // Kompajler zaključuje T = std::string
  std::string a = "ana";
  std::string b = "boris";
  std::cout << "maksimum(ana, boris): " << maksimum(a, b) << std::endl;

  // Specijalizacija za const char* (poredi leksikografski)
  std::cout << "maksimum(\"ana\", \"boris\"): " << maksimum("ana", "boris") << std::endl;

  // Dva različita tipa: T = int, U = double
  std::cout << "zbir(10, 3.14): " << zbir(10, 3.14) << std::endl;

  // Template sa lambdom - Lambda je neki tip koji kompajler zaključi
  primijeni(20, [](int x) { std::cout << "Vrijednost: " << x << std::endl; });
  primijeni("Zdravo", [](const std::string& s) { std::cout << "Poruka: " << s << std::endl; });

  // Template klasa
  Pair<int> par(10, 20);
  std::cout << "Pair: " << par.prvi() << ", " << par.drugi() << std::endl;

  // Eksplicitno navođenje template parametra (ako želimo)
  std::cout << "Eksplicitno: " << maksimum<double>(10.5, 20.5) << std::endl;
}
