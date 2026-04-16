#include <functional>
#include <iostream>
#include <string>

// Lambda je anonimna funkcija.
// Anonimna zato jer nema ime (kao što npr. void foo(); ima ime foo).
// Zašto su korisne? Zašto ne "obične" funkcije?
// Korisne su uglavnom zbog jednostavnosti, praktičnosti i mogućnosti spremanja vrijednosti i referenciranja varijabli.
// Recimo, moguće je napraviti funkciju koja uzima drugu funkciju (koristi se češće nego što se na prvu čini).
// Npr. funkcija koja filtrira elemente u nekom kontejneru uzima neku funkciju na osnovu koje zaključuje da li element treba ostaviti u kontejneru ili ne.
// Lambda može i da "uhvati" (capture-a) "vanjske" varijable, i to po referenci ili po vrijednosti.
// Ako lambda capture-a neku varijablu po vrijednosti, ona napravi kopiju te varijable koju može kasnije koristiti.
// Ta kopija više nema nikakve veze sa orginalnom varijablom i promjena jedne ne utične na drugu.
// Analogno, ako capture-a po referenci, napravi referencu na tu varijablu koju može kasnije koristiti.
// Ta referenca i orginalna varijabla su ekvivalentne (u pogledu da pokazuju na istu stvar).
// Dakle, promjena jedne podrazumijeva promjenu i druge.
//
// Lambda ima tri glavna dijela:
// - capture clause [...]
// - lista parametara (...)
// - tijelo lambde {...}
// Sintaksa za kreiranje lambde: [varijable za capture-anje] (parametri) { izrazi }
// List parametara i tijelo lambde se koristi isto kao i kod običnih funkcija.
// U capture clause se navode varijable koje će lambda "zapamtiti".
// Ako se ispored naziva varijable doda &, onda će se ta varijabla capture-ati po referenci, u suprotnom se radi capture po vrijednosti.
// Postoje i dvije posebne capture clause:
// - [=], capture-a sve varijable vidljive u opsegu gdje se lambda kreira po vrijednosti
// - [&], capture-a sve varijable vidljive u opsegu gdje se lambda kreira po referenci
// Lambda se poziva isto kao i obična funkcija.
//
// Moguće je eksplicitno navesti povratni tip lambde dodavanjem -> TIP između liste parametara i tijela lambde,
// npr.: [](int x) -> int { return x*x; }
// Po default-u nije moguće mijenjati vrijednosti varijabli koje su capture-ane po vrijednosti.
// Ukoliko želimo promijeniti vrijednosti tih varijabli potrebno je dodati ključnu riječ mutable između liste parametara i tijela lambde,
// npr.: [x]() mutable { x = 10; }, napomena: ovdje se i dalje mijenja x iz lambde, a ne orginalni x (jer je kopija, a ne referenca)
// Ukoliko želimo eksplicitno navesti i povratni tip i označiti lambdu kao mutable, prvo se navodi mutable, pa ondat -> TIP.
//
// Interno, kompajler lambdu pretvara u klasu.
// Svaka capture-ana varijabla se pretvara u jedan član te klase.
// Ako je capture po vrijednosti onda se vrijednost varijable kopira u taj član.
// Ako je capture po referenci, taj član ima tip reference i vezuje se za datu varijablu.
// Lista parametara i tijelo funkcije se koristi za generisanje operatora ().
// Lambda se može pretvoriti u pointer na funkciju ili u std::function, ali se tipično koristi auto za zaključivanje tipa ako želimo dati ime lambdi.
// Pointeri na funkcije se gotovo nikada ne koriste u c++, to je ostalo od c jezika, umjesto toga se koristi std::function.
// Sintaksa za std::function je: std::function< POVRATNI_TIP ( TIPOVI_PATAMETARA ) >
// npr.: std::function<void(int,double)> je funkcija koja ima dva parametra, prvi je int, drugi je double i ne vraća ništa (void).
// Ukoliko je lista parametara prazna moguće je izostaviti je.

int main()
{
  auto sum = [](int x, int y) {
    return x + y;
  };

  std::cout << "sum: " << sum(10, 20) << std::endl;

  //////////////////////////////////////////////////////////////////////////////////////

  std::string msg = "Hello World!";
  auto print_message = [&msg]() {
    std::cout << msg << std::endl;
  };
  print_message();

  //////////////////////////////////////////////////////////////////////////////////////

  int n = 10;
  auto print_double_n = [n]() mutable { // pokušati capture po referenci
    n *= 2;
    std::cout << n << std::endl;
  };
  print_double_n();
  n = 20;
  print_double_n();

  //////////////////////////////////////////////////////////////////////////////////////

  auto concat_string =
    [](const std::string& s1, const std::string& s2) -> std::string { return s1 + s2; };
  concat_string("abc", "def");

  //////////////////////////////////////////////////////////////////////////////////////

  std::function<int(int)> double_f = [](int x) { return 2 * x; };
  std::function<int(int)> triple_f = [](int x) { return 3 * x; };
  std::function<int(int)> square_f = [](int x) { return x * x; };

  int apply_func(int, const std::function<int(int)>&);

  int x = 10;
  std::cout << "double_f: " << apply_func(x, double_f) << std::endl;
  std::cout << "triple_f: " << apply_func(x, triple_f) << std::endl;
  std::cout << "square_f: " << apply_func(x, square_f) << std::endl;
}

int apply_func(int value, const std::function<int(int)>& func)
{
  return func(value);
}
