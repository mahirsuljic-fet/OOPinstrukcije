// struct

#include <iostream>

struct Tacka
{
    double x;
    double y;
};

int main(int argc, char* argv[])
{
  Tacka t1 = Tacka {
    10.0,
    11.0
  };

  Tacka t2 = {
    20.0,
    22.0
  };

  Tacka t3 {
    30.0,
    33.0
  };

  std::cout << "Tacka 1:\n"
            << "  x -> " << t1.x << "\n"
            << "  y -> " << t1.y << "\n"
            << std::endl;

  std::cout << "Tacka 2:\n"
            << "  x -> " << t2.x << "\n"
            << "  y -> " << t2.y << "\n"
            << std::endl;

  std::cout << "Tacka 3:\n"
            << "  x -> " << t3.x << "\n"
            << "  y -> " << t3.y << "\n"
            << std::endl;
}

// Napisati funkciju koja printa tacku

// Napraviti tacku na heap-u i isptintati je
