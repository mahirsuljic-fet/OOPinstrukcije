#include <iostream>

struct Complex
{
    // private:
    double re;
    double im;

    // friend Complex operator*(int x, Complex c);
    // friend std::string;

    // public:
    Complex operator+(Complex b)
    {
      return Complex { this->re + b.re, this->im + b.im };
    }

    Complex operator*(int x) { return { re * x, im * x }; }
};

// friend

Complex operator*(int x, Complex c) { return { c.re * x, c.im * x }; }

std::ostream& operator<<(std::ostream& out, const Complex& c)
{
  out << "re: " << c.re << ", im: " << c.im;
  return out;
}

int main()
{
  Complex ca { 10, 10 };
  Complex cb { 20, 20 };

  ca * 5;
  5 * ca;

  auto novi = ca + cb;
  std::cout << novi << std::endl;
}
