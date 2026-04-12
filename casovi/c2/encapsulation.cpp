// encapsulation

#include <iostream>

struct Tacka
{
    Tacka(double x, double y)
      : x_(x), y_(y) { }

    void print()
    {
      std::cout << "Tacka:\n"
                << "  x -> " << x_ << "\n"
                << "  y -> " << y_ << "\n"
                << std::endl;
    }

    double get_x() { return x_; }
    double get_y() { return y_; }

  private:
    double x_;
    double y_;
};

int main()
{
  Tacka t = Tacka(10, 20);
  t.print();
  // std::cout << t.x << std::endl;
  std::cout << t.get_x() << std::endl;

  // napraviti set metode za x i y
}
