// constructor

#include <iostream>

struct Tacka
{
    Tacka(double x, double y)
    {
      this->x = x;
      this->y = y;
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
