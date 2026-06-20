#include <iostream>

class Foo
{
  public:
    Foo() = default;
    Foo(Foo&&) = default;
    Foo(const Foo&) = default;
    Foo& operator=(Foo&&) = default;
    Foo& operator=(const Foo&) = default;
    ~Foo() = default;

    Foo(int a, double b) : b { b }, a { a }
    {
      // kjsdhgkldfs
      this->b = 50;
    }

    // private:
    int a = 100;
    double b = 200;
};

int main()
{
  Foo x = Foo(10, 20);
  x.a;
  x.b;

  // Foo f1;
  // Foo f2 {};
  // Foo f3 { f2 };
  // Foo f4;
  // f4 = f2;

  Foo f5 = Foo();
  f5 = Foo();
  Foo f6 = f5;
  f6 = f5;
}
