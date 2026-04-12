// method

#include <iostream>

struct Tacka
{
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
  t.print();
}

// napraviti metod koji vraca zbir vrijednosti x i y
