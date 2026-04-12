#include <iostream>

struct Tacka
{
    Tacka operator+(const Tacka& other)
    {
      Tacka nova_tacka = {
        this->x + other.x,
        this->y + other.y
      };

      return nova_tacka;
    }

    Tacka operator-(const Tacka& other)
    {
      return Tacka {
        this->x - other.x,
        this->y - other.y
      };
    }

    Tacka operator*(int n)
    {
      return {
        x * n,
        y * n,
      };
    }

    void print()
    {
      std::cout << "Tacka:\n"
                << "  x -> " << x << "\n"
                << "  y -> " << y << "\n"
                << std::endl;
    }

    double x, y;
};

Tacka operator*(int n, const Tacka& tacka)
{
  return {
    tacka.x * n,
    tacka.y * n,
  };
}

int main()
{
  Tacka t1 = { 10, 20 };
  Tacka t2 = { 20, 30 };

  t1.print();
  t2.print();

  Tacka zbir = t1 + t2;
  Tacka razlika = t1 - t2;
  Tacka umnozak1 = t1 * 2;
  Tacka umnozak2 = 2 * t1;

  zbir.print();
  razlika.print();
  umnozak1.print();
  umnozak2.print();
}
