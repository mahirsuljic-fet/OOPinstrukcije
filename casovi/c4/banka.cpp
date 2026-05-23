// bankovni racun:
//   balance_
//   deposit(...)
//   withdraw(...)
//   status()

// banka:
//   kolekcija racuna
//   operacije na racunima

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class BankovniRacun
{
  public:
    BankovniRacun(const std::string& naziv)
      : naziv { naziv }
    {
      std::cout << "Pozdrav " << this->naziv << std::endl;
    }

    void dodaj_pare(double vrijednost)
    {
      pare += vrijednost;
    }

    double uzmi_pare(double vrijednost)
    {
      if (vrijednost <= pare)
      {
        pare -= vrijednost;
        return vrijednost;
      }
      else
      {
        return 0.0;
      }
    }

    void ispis() const
    {
      std::cout << "Pozdrav " << naziv << " imas " << pare << "KM" << std::endl;
    }

    std::string get_naziv() const { return naziv; }

  private:
    std::string naziv;
    double pare = 0.0;
};

int main()
{
  std::vector<BankovniRacun> vektor_racuna;

  //////////////////////////////////////////////////////////////////////////////////////

  BankovniRacun meho = BankovniRacun("Meho");

  meho.ispis();

  meho.dodaj_pare(10.0);
  meho.ispis();

  std::cout << "Podigli ste " << meho.uzmi_pare(10.0) << "KM" << std::endl;
  meho.ispis();

  std::cout << "Podigli ste " << meho.uzmi_pare(10.0) << "KM" << std::endl;
  meho.ispis();

  //////////////////////////////////////////////////////////////////////////////////////

  vektor_racuna.push_back(meho);
  vektor_racuna.push_back(BankovniRacun("foo"));
  vektor_racuna.push_back(BankovniRacun("bar"));
  vektor_racuna.push_back(BankovniRacun("tar"));

  for (auto el : vektor_racuna)
    el.ispis();
  std::cout << std::endl;

  std::sort(
    vektor_racuna.begin(),
    vektor_racuna.end(),
    [](const BankovniRacun& lhs, const BankovniRacun& rhs) { return lhs.get_naziv() < rhs.get_naziv(); });

  for (auto el : vektor_racuna)
    el.ispis();
  std::cout << std::endl;
}
