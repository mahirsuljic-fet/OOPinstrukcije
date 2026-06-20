#include <iostream>
#include <map>

struct Foo
{
    Foo()
    {
      std::cout << "Pravim default" << std::endl;
    }

    Foo(const std::string& s)
    {
      std::cout << "Pravim string (" << s << ")" << std::endl;
    }
};

int main()
{
  std::map<int, Foo> brojevi;

  brojevi[2] = Foo { "dva" };
  brojevi[1] = Foo { "jedan" };
  brojevi[3] = Foo { "tri" };

  // brojevi.at(10);

  auto x = brojevi[10];

  // for (const auto& el : brojevi)
  // {
  //   std::cout << el.first << " - " << el.second << std::endl;
  // }
}
