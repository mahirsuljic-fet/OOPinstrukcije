// Pregled koncepata iz c5: lambde, iznimke, operator<<, std::function
// https://en.cppreference.com/w/cpp/utility/functional/function

#include <functional>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

using Godiste = unsigned short;

class Osoba
{
  public:
    Osoba(const std::string& ime, const std::string& prezime, Godiste godiste)
      : ime_ { ime }, prezime_ { prezime }, godiste_ { godiste } { }

    std::string ime() const { return ime_; }
    std::string prezime() const { return prezime_; }
    Godiste godiste() const { return godiste_; }
    Godiste godine(unsigned short trenutna_godina) const
    {
      return trenutna_godina - godiste_;
    }

  private:
    std::string ime_;
    std::string prezime_;
    Godiste godiste_;
};

// operator<< za ispis Osobe na std::cout
std::ostream& operator<<(std::ostream& out, const Osoba& osoba)
{
  out << osoba.ime() << " " << osoba.prezime()
      << " (" << osoba.godiste() << ")";
  return out;
}

// std::function omogućava da funkciju proslijedimo kao parametar
// Ovdje predicate je funkcija koja uzima Osoba i vraća bool
std::vector<Osoba> filter(
  const std::vector<Osoba>& vec,
  const std::function<bool(const Osoba&)>& predicate)
{
  std::vector<Osoba> rezultat;

  for (const auto& el : vec)
    if (predicate(el))
      rezultat.push_back(el);

  return rezultat;
}

int main()
{
  std::vector<Osoba> osobe;
  osobe.push_back(Osoba("Ana", "Anic", 2001));
  osobe.push_back(Osoba("Boris", "Boric", 2002));
  osobe.push_back(Osoba("Cvijo", "Cvic", 2003));
  osobe.push_back(Osoba("Dino", "Dinic", 2004));
  osobe.push_back(Osoba("Ema", "Emic", 2005));

  // Primjer sa iznimkom: std::vector::at()
  try
  {
    std::size_t indeks;
    std::cout << "Unesi redni broj (1-" << osobe.size() << "): ";
    std::cin >> indeks;

    const auto& osoba = osobe.at(indeks - 1);
    std::cout << "Izabrali ste: " << osoba << std::endl;
  }
  catch (std::out_of_range& e)
  {
    std::cout << "Greska: nepostojeci indeks!" << std::endl;
  }

  // Lambda za filtriranje
  std::cout << "\nOsobe starije od 20 godina (2026):" << std::endl;
  auto starije_od_20 = filter(osobe,
    [](const Osoba& o) { return o.godine(2026) > 20; });
  for (const auto& o : starije_od_20)
    std::cout << "  " << o << std::endl;

  // Lambda sa više uslova
  std::cout << "\nOsobe sa imenom duzim od 4 slova:" << std::endl;
  auto dugo_ime = filter(osobe,
    [](const Osoba& o) { return o.ime().length() > 4; });
  for (const auto& o : dugo_ime)
    std::cout << "  " << o << std::endl;
}
