### Primjeri
- [p1_primitives](./p1_primitives.cpp)
- [p2_operators](./p2_operators.cpp)
- [p3_pointers](./p3_pointers.cpp)
- [p4_arrays](./p4_arrays.cpp)
- [p5_initialization](./p5_initialization.cpp)
- [p6_scope](./p6_scope.cpp)
- [p7_if](./p7_if.cpp)
- [p8_switch](./p8_switch.cpp)
- [p9_dowhile](./p9_dowhile.cpp)
- [p10_while](./p10_while.cpp)
- [p11_for](./p11_for.cpp)
- [p12_namespaces](./p12_namespaces.cpp)
- [p13_references](./p13_references.cpp)
- [p14_auto](./p14_auto.cpp)
- [p15_functions](./p15_functions.cpp)
- [p16_static](./p16_static.cpp)
- [p17_multifile](./p17_multifile)
  - [p17_multifile.cpp)](./p17_multifile/p17_multifile.cpp)
  - [mymath.cpp](./p17_multifile/mymath.cpp)
  - [mymath.hpp](./p17_multifile/mymath.hpp)
- [p18_struct](./p18_struct.cpp)

---

### Pitanja
- Koji će biti ispis `std::cout << 010;`?
- Koja je razlika između `const int*` i `int* const`?
- Koja je razlika između deklaracije i definicije varijable? Navesti primjer.
- Da li je moguće izostaviti broj članova pri definicije niza? Ako da, kada i kako? Da li isto moguće i prilikom deklaracije niza?
- Koje vrijednosti imaju neinicijalizirane globalne varijable, a koje neinicijalizirane lokalne varijable?
- Koja je razlika između inicijalizacije primitivnih tipova koristeći operator `=`, `()` i `{}`?
- Koje vrste vrijednosti se mogu koristiti u `switch` izrazu?
- Koja je razlika imeđu `do while` i `while` petlje?
- Da li je moguće izostaviti neki dio `for` petlje unutar `()`? \
  Ako da, šta se podrazumijeva da je uslov (dio petlje) ako se on izostavi? \
  Ako da, navesti primjer `for` petlje bez uslova (dio petlje)?
- Kakva vrsta petlje je `for` petlja koja nema ni jednog dijela unutar `()`? Napisati primjer takve petlje. Kako se ona ponaša?
- Da li je moguće pristupiti globalnim varijablama iz bilo kojeg scope-a? \
  Šta ako se u tom scope-u koristi `using namespace Foo` gdje u namespace `Foo` postoji varijabla sa istim imenom kao globalna varijabla kojoj želimo pristupiti? \
  Navesti primjer ako je odgovor *da*.
- Kako se pristupa varijablama koje su unutar nekog namespace-a?
- Koje (glavne) vrste referenci postoje (4 vrste)?
- Šta je `std::cout` (funkcija, varijabla, itd.)? Koja vrsta? Šta je `std`? \
  *(Nismo govorili o ovome ali probaj skontat na osnovu ovoga što smo prešli)*
- Koja je razlika između lokalne varijable koja jest označena kao `static` i one koja nije?
- Da li su po default-u globalne varijable vidljive u drugim fajlovima pored onog u kojima su definisane?
- Kako se označava globalna vrijabla koja ne želimo da bude dostupna u drugim fajlovima?
- Kako se pristupa globalnih varijablama koje nisu definisane u fajlu u kojem ih želimo koristiti?
- Kako se kompajlira više c++ fajlova? Napisati komandu.
- Da li je potrebno kompajlirati header (*.h* i *.hpp*) fajlove? Zašto?
- Kako se pristupa članovima strukture?

### Zadaci
- Napraviti funkciju koja ispisuje string literal (c-string) koji joj je proslijeđen kao argument. Zatim je pozvati iz `main`.
- Napisati funkciju `is_even` koja provjerava da li je proslijeđeni broj paran. \
  *Hint: funkcija treba da prima int, a vraća bool*
- Napraviti petlju koja će koristiti prethodno napravljenu funkciju `is_even` da ispiše prvih 100 parnih brojeva.
- Napraviti lokalnu varijablu `x` unutar funkcije `main` koja je tipa `int`. \
  Zatim napraviti pointer i referencu na tu varijablu i promijeniti joj vrijednosti direktno, preko pointera i preko reference.
- Napisati funkciju koja vraća broj puta koliko je pozvana bez korištenja globalnih varijabli.
  ``` c++
  std::cout << pametna_funkcija() << std::endl; // treba da ispiše 1
  std::cout << pametna_funkcija() << std::endl; // treba da ispiše 2
  std::cout << pametna_funkcija() << std::endl; // treba da ispiše 3
  ```
- Označiti greške u kodu ispod i obrazložiti ih ako postoje:
  ``` c++
  int a = 10;
  const int b = 20;
  auto c = 30;

  int* p1 = &a;                 *p1 += 1;     p1++;
  int* p2 = &b;                 *p2 += 1;     p2++;
  int* p3 = &c;                 *p3 += 1;     p3++;

  const int* p4 = &a;           *p4 += 1;     p4++;
  const int* p5 = &b;           *p5 += 1;     p5++;
  const int* p6 = &c;           *p6 += 1;     p6++;

  int* const p7 = &a;           *p7 += 1;     p7++;
  int* const p8 = &b;           *p8 += 1;     p8++;
  int* const p9 = &c;           *p9 += 1;     p9++;

  const int* const p10 = &a;    *p10 += 1;    p10++;
  const int* const p11 = &b;    *p11 += 1;    p11++;
  const int* const p12 = &c;    *p12 += 1;    p12++;

  auto* p13 = &a;               *p13 += 1;    p13++;
  auto* p14 = &b;               *p14 += 1;    p14++;
  auto* p15 = &c;               *p15 += 1;    p15++;

  auto p16 = &a;                *p16 += 1;    p16++;
  auto p17 = &b;                *p17 += 1;    p17++;
  auto p18 = &c;                *p18 += 1;    p18++;
  ```
- Označiti greške u kodu ispod i obrazložiti ih ako postoje:
  ``` c++
  int x = 10;
  const int y = 10;

  int& r1 = x;
  const int& r2 = x;
  int&& r3 = x;
  const int&& r4 = x;
  auto& r5 = x; 
  const auto& r6 = x; 

  int& r7 = y;
  const int& r8 = y;
  int&& r9 = y;
  const int&& r10 = y;
  auto& r11 = y;
  const auto& r12 = y;

  int& r13 = 10;
  const int& r14 = 10;
  int&& r15 = 10;
  const int&& r16 = 10;
  auto& r17 = 10;
  const auto& r18 = 10;
  ```
