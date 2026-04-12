// static methods

#include <iostream>

class Tacka
{
  public:
    static void static_pozdrav()
    {
      static unsigned long pozdrav_counter = 1;
      std::cout << "Pozdrav! Do sada je napravljeno " << counter_ << " tacaka. Metod static_pozdrav je pozvan " << pozdrav_counter << " puta." << std::endl;
      pozdrav_counter++;
    }

    void pozdrav() const
    {
      std::cout << "Pozdrav od tacke sa ID " << id_ << "." << std::endl;
    }

    Tacka(double x, double y) : x_(x), y_(y), id_(counter_++) { }

  private:
    // ignorisati ovaj komentar ispod
    // clang-format off
    static unsigned long counter_; // >>v
    unsigned long id_;             //   v
    double x_;                     //   v
    double y_;                     //   v
};                                 //   v
                                   //   v
unsigned long Tacka::counter_ = 0; // <<<
// ignorisati ovaj komentar ispod
// clang-format on

int main()
{
  Tacka t1(0, 0);
  Tacka t2(0, 0);
  Tacka t3(0, 0);

  Tacka::static_pozdrav();

  t1.static_pozdrav();
  t2.static_pozdrav();
  t3.static_pozdrav();

  t1.pozdrav();
  t2.pozdrav();
  t3.pozdrav();
}
