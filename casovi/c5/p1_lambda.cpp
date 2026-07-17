// Lambda - primjeri korištenja za rješavanje problema:
// https://en.cppreference.com/w/cpp/language/lambda

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Lambda izrazi su anonimne funkcije koje možemo kreirati "na licu mjesta".
// Korisne su kada trebamo funkciju koja će se koristiti samo jednom,
// ili kada trebamo "uhvatiti" (capture) varijable iz okolnog opsega.
//
// Sintaksa: [capture](parametri) { tijelo }
// - capture: varijable koje lambda "pamti" (po vrijednosti ili referenci)
// - parametri: kao i kod običnih funkcija
// - tijelo: kod koji se izvršava

int main()
{
  std::vector<int> brojevi = { 5, 3, 8, 1, 9, 2, 7, 4, 6 };

  // Primjer 1: sortiranje sa custom kriterijem
  std::cout << "Sortirano opadajuće: ";
  std::sort(brojevi.begin(), brojevi.end(),
    [](int a, int b) { return a > b; });
  for (int n : brojevi) std::cout << n << " ";
  std::cout << std::endl;

  // Primjer 2: std::find_if - pronaći prvi paran broj
  auto it = std::find_if(brojevi.begin(), brojevi.end(),
    [](int n) { return n % 2 == 0; });
  if (it != brojevi.end())
    std::cout << "Prvi parni broj: " << *it << std::endl;

  // Primjer 3: std::count_if - prebrojati brojeve veće od 5
  int granica = 5;
  int brojač = std::count_if(brojevi.begin(), brojevi.end(),
    [granica](int n) { return n > granica; });
  std::cout << "Brojeva vecih od " << granica << ": " << brojač << std::endl;

  // Primjer 4: std::for_each - ispisati svaki broj pomnožen sa 2
  std::cout << "Pomnozeni sa 2: ";
  std::for_each(brojevi.begin(), brojevi.end(),
    [](int n) { std::cout << n * 2 << " "; });
  std::cout << std::endl;

  // Primjer 5: lambda koja mijenja vanjsku varijablu (capture po referenci)
  int suma = 0;
  std::for_each(brojevi.begin(), brojevi.end(),
    [&suma](int n) { suma += n; });
  std::cout << "Suma: " << suma << std::endl;

  // Primjer 6: std::remove_if - ukloniti sve brojeve manje od 5
  brojevi.erase(std::remove_if(brojevi.begin(), brojevi.end(),
    [](int n) { return n < 5; }), brojevi.end());
  std::cout << "Nakon uklanjanja brojeva manjih od 5: ";
  for (int n : brojevi) std::cout << n << " ";
  std::cout << std::endl;

  // Primjer 7: lambda sa std::vector<std::string>
  std::vector<std::string> imena = { "Ana", "Boris", "Cvijo", "Dino", "Ema" };

  std::sort(imena.begin(), imena.end(),
    [](const std::string& a, const std::string& b) {
      return a.size() > b.size();
    });
  std::cout << "Imena sortirana po dužini (opadajuće): ";
  for (const auto& ime : imena) std::cout << ime << " ";
  std::cout << std::endl;

  // Primjer 8: lambda koja vraća vrijednost
  auto kvadrat = [](int x) { return x * x; };
  std::cout << "Kvadrat od 7: " << kvadrat(7) << std::endl;
}
