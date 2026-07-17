// Šta kompajler generiše za nas (special member functions):
// https://en.cppreference.com/w/cpp/language/default_constructor
// https://en.cppreference.com/w/cpp/language/copy_constructor
// https://en.cppreference.com/w/cpp/language/move_constructor

#include <iostream>

// Ako ih ne definišemo, kompajler će automatski generisati:
// 1. Default konstruktor       - Foo()           - ako nema nijednog konstruktora
// 2. Copy konstruktor          - Foo(const Foo&) - uvijek (osim ako eksplicitno izbrišemo)
// 3. Move konstruktor          - Foo(Foo&&)      - ako nema copy/destructor/...
// 4. Copy operator=            - Foo& operator=(const Foo&)
// 5. Move operator=            - Foo& operator=(Foo&&)
// 6. Destruktor                - ~Foo()
//
// Važno: ako definišemo BILO KOJI konstruktor, DEFAULT konstruktor se VIŠE ne generiše!
// Ako i dalje želimo default konstruktor, moramo ga sami napisati.

class Foo
{
  public:
    // = default kaze kompajleru: "generiši default verziju"
    Foo() = default;
    Foo(const Foo&) = default;
    Foo& operator=(const Foo&) = default;
    ~Foo() = default;

    // = delete kaze: "ukloni ovaj metod"
    Foo(Foo&&) = delete;
    Foo& operator=(Foo&&) = delete;

    // Ako definišemo ovaj konstruktor, gubimo default konstruktor
    // (zato smo gore eksplicitno napisali Foo() = default)
    Foo(int a, double b) : a_ { a }, b_ { b }
    {
      std::cout << "Custom konstruktor(" << a_ << ", " << b_ << ")" << std::endl;
    }

    int a_ = 0;
    double b_ = 0.0;
};

class BezDefaultKonstruktora
{
  public:
    // Ovo je jedini konstruktor - nema default konstruktora
    BezDefaultKonstruktora(int x) : x_(x) { }
    int x_;
};

int main()
{
  Foo f1;                  // default konstruktor
  Foo f2(10, 20);          // custom konstruktor
  Foo f3(f2);              // copy konstruktor
  Foo f4 = f2;             // copy konstruktor
  // Foo f5 = std::move(f2); // GREŠKA: move je deleted

  f1 = f2;                 // copy operator=

  // BezDefaultKonstruktora b1;     // GREŠKA: nema default konstruktora
  BezDefaultKonstruktora b2(5);    // OK

  std::cout << "f2: " << f2.a_ << ", " << f2.b_ << std::endl;
  std::cout << "f3 (kopija od f2): " << f3.a_ << ", " << f3.b_ << std::endl;
}
