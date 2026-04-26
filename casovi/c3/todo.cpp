#include <iostream>
#include <string>
#include <vector>

class TODOList
{
    struct ElementListe
    {
        void print() const
        {
          std::cout << "- " << opis << std::endl;
        }

        std::string opis;
    };

  public:
    TODOList(const std::string& naslov_param)
      : naslov(naslov_param), elementi() { }

    void print() const
    {
      std::cout << naslov << std::endl;
      for (int i = 0; i < elementi.size(); i++)
        elementi[i].print();
    }

    void add_element(const std::string& opis_elementa)
    {
      ElementListe novi_el = ElementListe { opis_elementa };
      elementi.push_back(novi_el);
    }

  private:
    std::vector<ElementListe> elementi;
    std::string naslov;
};

int main()
{
  // TODOList lista = TODOList("Nasa lista");
  TODOList lista("Nasa lista");
  lista.add_element("kola");
  lista.print();
  lista.add_element("voda");
  lista.print();
}
