// std::map operator[] i implicitna konstrukcija objekata:
// https://en.cppreference.com/w/cpp/container/map/operator_at

#include <iostream>
#include <map>
#include <string>

// std::map je kontejner koji pohranjuje parove ključ-vrijednost.
// Kljucevi su jedinstveni i elementi su sortirani po ključu.
//
// BITNO: operator[] kod std::map radi drugačije nego kod std::vector.
// Ako ključ NE postoji, operator[] će:
//   1. Kreirati NOVI par (ključ, vrijednost) sa DEFAULT vrijednoscu za vrijednost
//   2. Vratiti referencu na tu novu vrijednost
// Ovo znači da operator[] UVIJEK kreira element ako ne postoji!

struct Foo
{
    std::string naziv_;

    Foo()
    {
      std::cout << "  Pravim Foo (default konstruktor)" << std::endl;
    }

    Foo(const std::string& s) : naziv_(s)
    {
      std::cout << "  Pravim Foo (\"" << s << "\")" << std::endl;
    }

    ~Foo()
    {
      std::cout << "  Uništavam Foo (\"" << naziv_ << "\")" << std::endl;
    }
};

int main()
{
  std::cout << "Kreiram mapu..." << std::endl;
  std::map<int, Foo> brojevi;

  // operator[] sa desne strane (čitanje):
  // Ako ključ ne postoji, kreira se NOVI Foo (default konstruktor)!
  // Zato pristup brojevi[1] kreira Foo, čak iako ga samo čitamo!
  std::cout << "\nPristupam brojevi[1] (ne postoji):" << std::endl;
  brojevi[1]; // <-- OVDJE se kreira Foo!

  // operator[] sa lijeve strane (pisanje):
  std::cout << "\nDodjeljujem brojevi[2] = Foo(\"dva\"):" << std::endl;
  brojevi[2] = Foo { "dva" }; // kreira se Foo("dva"), zatim se kopira

  // Alternativa: insert (ne kreira element ako vec postoji)
  std::cout << "\nInsert brojevi[3] sa \"tri\":" << std::endl;
  brojevi.insert({ 3, Foo { "tri" } });

  // at() metoda - ako ključ ne postoji, baca iznimku (ne kreira element)
  std::cout << "\nPristupam brojevi.at(1):" << std::endl;
  try
  {
    std::cout << "  Vrijednost: " << brojevi.at(1).naziv_ << std::endl;
  }
  catch (std::out_of_range&)
  {
    std::cout << "  Kljuc ne postoji (at je bacio iznimku)" << std::endl;
  }

  // Zato treba biti oprezan sa operator[] kada samo želimo provjeriti
  // da li ključ postoji - bolje koristiti .find() ili .count()
  std::cout << "\nProvjera da li 10 postoji (find):" << std::endl;
  if (brojevi.find(10) == brojevi.end())
    std::cout << "  10 ne postoji (nije kreiran)" << std::endl;

  // Sa operator[] bi se 10 kreirao:
  std::cout << "\nProvjera da li 10 postoji (operator[]):" << std::endl;
  if (brojevi[10].naziv_ == "") // <-- OVDJE se kreira Foo(10)!
    std::cout << "  10 ne postoji, ALI je upravo kreiran!" << std::endl;

  std::cout << "\nKraj programa - uništavanje mape:" << std::endl;
}
