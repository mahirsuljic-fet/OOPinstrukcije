#include <iostream>
#include <string>
#include <vector>

struct ElementListe
{
    std::string naziv;
    std::string opis;

    void print() const
    {
      std::cout << naziv << ": " << opis << std::endl;
    }
};

int main()
{
  std::vector<ElementListe> lista;

  ElementListe el1 = {
    "element1",
    "laptop"
  };

  ElementListe el2 = {
    "element2",
    "casa"
  };

  ElementListe el3 = {
    "element3",
    "flasa"
  };

  lista.push_back(el1);
  lista.push_back(el2);
  lista.push_back(el3);

  for (int i = 0; i < lista.size(); i++)
  {
    const ElementListe& el = lista[i];
    el.print();
    // ili
    // lista[i].print();
  }
}
