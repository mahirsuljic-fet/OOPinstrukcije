#include <iostream>

class Tacka
{
  public:
    Tacka(double x, double y) : x_(x), y_(y) { }

    void pozdrav()
    {
      std::cout << "Pozdrav!" << std::endl;
      // x_++;
    }

    void pozdrav() const
    {
      std::cout << "Connst pozdrav!" << std::endl;
      // x_++;
    }

  private:
    double x_;
    double y_;
};

int main()
{
  Tacka t1 { 10, 10 };
  const Tacka t2 { 10, 10 };

  t1.pozdrav();
  t2.pozdrav();
}
