// class

#include <iostream>

class Tacka
{
    void test() { std::cout << "Test" << std::endl; }

  public:
    Tacka(double x, double y)
      : x_(x), y_(y) { }

    void print()
    {
      std::cout << "Tacka:\n"
                << "  x -> " << x_ << "\n"
                << "  y -> " << y_ << "\n"
                << std::endl;
    }

    void print_and_increment()
    {
      print();
      increment();
    }

    double get_x() { return x_; }
    double get_y() { return y_; }

  private:
    double x_;
    double y_;

    void increment()
    {
      x_++;
      y_++;
    }
};

int main()
{
  Tacka t = Tacka(10, 20);

  t.print();

  // std::cout << t.x << std::endl;
  std::cout << t.get_x() << std::endl;

  t.print_and_increment();
  t.print_and_increment();

  // t.increment();
  // t.test();
}
