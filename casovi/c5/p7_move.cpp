// Move semantika: zašto je move brži od copy:
// https://en.cppreference.com/w/cpp/utility/move

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

// lvalue (left value)  - nešto sto ima adresu, može stati sa lijeve strane =
// rvalue (right value) - privremena vrijednost, nema adresu (npr. 42, "string", povrat funkcije)
//
// std::move pretvara lvalue u rvalue, sto dozvoljava move umjesto copy.
// Move je brži od copy jer umjesto kopiranja svih podataka, samo "prebacimo"
// pokazivače (ili druge resurse) iz izvornog objekta u novi.
//
// Nakon move-a, izvorni objekat je u validnom ali nedefinisanom stanju.

int main()
{
  std::cout << "Pravim veliki vektor (100,000,000 intova)..." << std::endl;
  std::vector<int> v1(100'000'000, 42);

  // Copy: sahovski sporo za ogroman vektor
  auto t1 = std::chrono::high_resolution_clock::now();
  std::vector<int> v2 = v1; // copy konstruktor
  auto t2 = std::chrono::high_resolution_clock::now();
  auto trajanje_copy = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
  std::cout << "Copy: " << trajanje_copy.count() << " ms" << std::endl;

  // Move: trenutno, samo "prebacimo" podatke
  auto t3 = std::chrono::high_resolution_clock::now();
  std::vector<int> v3 = std::move(v1); // move konstruktor
  auto t4 = std::chrono::high_resolution_clock::now();
  auto trajanje_move = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
  std::cout << "Move: " << trajanje_move.count() << " ms" << std::endl;

  // Nakon move-a, v1 je prazan (više ne posjeduje podatke)
  std::cout << "v1.size() nakon move-a: " << v1.size() << std::endl;
  std::cout << "v2.size() (copy): " << v2.size() << std::endl;
  std::cout << "v3.size() (move): " << v3.size() << std::endl;

  // Move je koristan i za std::string
  std::string dugi_string(1'000'000, 'x');
  std::cout << "\nDugi string dužine: " << dugi_string.size() << std::endl;

  auto t5 = std::chrono::high_resolution_clock::now();
  std::string kopija = dugi_string; // copy
  auto t6 = std::chrono::high_resolution_clock::now();
  std::cout << "String copy: "
            << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count()
            << " us" << std::endl;

  auto t7 = std::chrono::high_resolution_clock::now();
  std::string premjesten = std::move(dugi_string); // move
  auto t8 = std::chrono::high_resolution_clock::now();
  std::cout << "String move: "
            << std::chrono::duration_cast<std::chrono::microseconds>(t8 - t7).count()
            << " us" << std::endl;
}
