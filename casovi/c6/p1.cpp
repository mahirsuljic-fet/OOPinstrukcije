#include <cstddef>
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
    Godiste godine(unsigned short trenutna_godina) const { return trenutna_godina - godiste_; }

    void ispis() const
    {
      std::cout << "Ime: " << ime_ << std::endl
                << "Prezime: " << prezime_ << std::endl
                << "Godiste: " << godiste_ << std::endl;
    }

  private:
    std::string ime_;
    std::string prezime_;
    Godiste godiste_;
};

std::ostream& operator<<(std::ostream& out, const Osoba& osoba)
{
  osoba.ispis();
  return out;
}

std::vector<Osoba> filter(
  const std::vector<Osoba>& vec,
  const std::function<bool(Osoba)>& predicate)
{
  std::vector<Osoba> filtrirani_vec;

  for (Osoba el : vec)
    if (predicate(el))
      filtrirani_vec.push_back(el);

  return filtrirani_vec;
}

int main()
{
  std::vector<Osoba> vec;
  const std::size_t br_unesenih_osoba = 3;

  vec.push_back(Osoba("Test 1", "Test 1", 2001));
  vec.push_back(Osoba("Test 2", "Test 2", 2002));
  vec.push_back(Osoba("Test 3", "Test 3", 2003));
  vec.push_back(Osoba("Test 4_", "Test 4", 2004));
  vec.push_back(Osoba("Test 5_", "Test 5", 2005));
  vec.push_back(Osoba("Test 6_", "Test 6", 2006));
  vec.push_back(Osoba("Test 7", "Test 7", 2007));
  vec.push_back(Osoba("Test 8", "Test 8", 2008));
  vec.push_back(Osoba("Test 9", "Test 9", 2009));

  // for (int i = 0; i < br_unesenih_osoba; i++)
  // {
  //   std::string ime, prezime;
  //   Godiste godiste;
  //
  //   std::cout << "Unesi ime: ";
  //   std::cin >> ime;
  //   std::cout << "Unesi prezime: ";
  //   std::cin >> prezime;
  //   std::cout << "Unesi godiste: ";
  //   std::cin >> godiste;
  //
  //   Osoba osoba = Osoba(ime, prezime, godiste);
  //   vec.push_back(osoba);
  //
  //   osoba.ispis();
  // }
  //
  // std::cout << std::endl;
  // std::cout << std::string(10, '-');
  // std::cout << std::endl;
  // std::cout << std::endl;
  //
  // for (const auto& el : vec)
  //   std::cout << el << std::endl;
  // // el.ispis();
  //
  // std::cout << std::endl;
  // std::cout << std::string(10, '-');
  // std::cout << std::endl;
  // std::cout << std::endl;
  //
  // bool uspijeh = false;
  // while (!uspijeh)
  // {
  //   try
  //   {
  //     std::size_t red_br;
  //
  //     std::cout << "Unesi redni broj: ";
  //     std::cin >> red_br;
  //
  //     const auto& osoba = vec.at(red_br - 1);
  //     std::cout << "Izabrana osoba\n";
  //     std::cout << osoba << std::endl;
  //
  //     uspijeh = true;
  //   }
  //   catch (std::out_of_range ex)
  //   {
  //     std::cout << "Bacena iznimka!" << std::endl;
  //   }
  // }

  auto filtrirani_vec = filter(vec, [](Osoba o) -> bool { return o.godine(2026) > 20; });

  for (const auto& el : filtrirani_vec)
    std::cout << el << std::endl;

  filtrirani_vec = filter(vec, [](Osoba o) -> bool { return o.ime().length() > 6; });

  for (const auto& el : filtrirani_vec)
    std::cout << el << std::endl;

  return 0;
}
