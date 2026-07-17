// Iznimke (exceptions) i stack unwinding:
// https://en.cppreference.com/w/cpp/language/exceptions

#include <iostream>
#include <stdexcept>
#include <string>

// Stack unwinding je proces koji se dešava kada se baci iznimka.
// Program automatski uništava SVE objekte na stack-u (od mjesta bacanja
// pa nadalje) dok ne pronađe odgovarajući catch blok.
//
// Redoslijed uništavanja je OBRNUT od redoslijeda kreiranja (LIFO).
// Ovo je važno: destruktori se pozivaju za SVE objekte koji su bili
// kreirani prije bacanja iznimke, ali ne i za one poslije.

struct Foo
{
    std::string naziv_;
    Foo(const std::string& naziv) : naziv_(naziv)
    {
      std::cout << "  Pravim " << naziv_ << std::endl;
    }
    ~Foo()
    {
      std::cout << "  Uništavam " << naziv_ << std::endl;
    }
};

void funkcija()
{
  Foo f1("f1");
  Foo f2("f2");
  std::cout << "  Bacam iznimku..." << std::endl;
  throw std::runtime_error("Greska u funkciji");
  Foo f3("f3"); // <-- OVO SE NIKAD NE KREIRA
}

int main()
{
  std::cout << "Primjer 1: stack unwinding u akciji" << std::endl;
  try
  {
    Foo a("a");
    Foo b("b");
    funkcija();
    Foo c("c"); // <-- OVO SE NIKAD NE KREIRA
  }
  catch (std::runtime_error& e)
  {
    std::cout << "  Uhvaceno: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  // Važno: objekti kreirani na HEAP-U se NE uništavaju automatski!
  std::cout << "Primjer 2: važno - heap objekti se ne uništavaju!" << std::endl;
  try
  {
    Foo stack("stack");
    Foo* heap = new Foo("heap");
    throw std::runtime_error("Greska");
    delete heap; // <-- OVO SE NIKAD NE IZVRSI! MEMORY LEAK!
  }
  catch (std::runtime_error& e)
  {
    std::cout << "  Uhvaceno, al heap objekat nije obrisan!" << std::endl;
  }
  // Rjesenje: koristiti unique_ptr ili delete prije throw-a.
}
