### Sadržaj
- [p1_lambda](./p1_lambda.cpp)
- [p2_operator_overloading](./p2_operator_overloading.cpp)
- [p3_map_subscript](./p3_map_subscript.cpp)
- [p4_stack_unwinding](./p4_stack_unwinding.cpp)
- [p5_explicit](./p5_explicit.cpp)
- [p6_special_members](./p6_special_members.cpp)
- [p7_move](./p7_move.cpp)
- [Pitanja](#pitanja)
- [Zadaci](#zadaci)

---

### Pitanja

**Lambda**
1. Šta je lambda izraz i koja je njegova sintaksa?
2. Koja je razlika između capture-a po vrijednosti `[=]` i po referenci `[&]`?
3. Kada i kako koristimo `std::for_each`, `std::find_if`, `std::count_if`?

**Operator overloading**
4. Na koja dva načina možemo overload-ati operator u C++?
5. Čemu služi ključna riječ `friend`?
6. Zašto operator `<<` za ispis mora biti globalna funkcija?

**std::map operator[]**
7. Kako se `operator[]` ponaša za `std::map` kada ključ ne postoji?
8. Koja je razlika između `operator[]` i `.at()`?
9. Zašto treba biti oprezan sa `operator[]` prilikom provjere da li ključ postoji?

**Iznimke i stack unwinding**
10. Šta je stack unwinding?
11. Koji objekti se uništavaju prilikom bacanja iznimke? Da li se uništavaju i objekti na heap-u?
12. Šta je problem sa heap objektima kada se baci iznimka?

**explicit konstruktor**
13. Čemu služi `explicit` ispred konstruktora?
14. Navesti primjer gdje implicitna konverzija može biti problematična.

**Special member functions**
15. Koje specijalne metode kompajler automatski generiše?
16. Kada se gubi default konstruktor koji kompajler generiše?
17. Šta radi `= default`, a šta `= delete`?

**Move semantika**
18. Koja je razlika između lvalue i rvalue?
19. Šta radi `std::move`?
20. Zašto je move brži od copy za velike objekte (npr. `std::vector`)?

### Zadaci

1. **Lambda - Filtriraj stringove**: Kreirati `std::vector<std::string>` sa 10 imena. Koristeći lambde, ispisati samo imena koja počinju sa slovom 'A' i duža su od 3 karaktera.

2. **Operator overloading - Vektor2D**: Kreirati strukturu `Vektor2D` sa `x` i `y`. Overload-ovati operatore `+`, `*` (sa skalarom) i `<<`. Omogućiti `5 * v` i `v * 5`.

3. **std::map - Frekvencija riječi**: Napisati program koji broji koliko se puta svaka riječ pojavljuje u rečenici koristeći `std::map<std::string, int>`.

4. **Stack unwinding - Demonstracija**: Napisati program sa tri nivoa funkcija (main -> f1 -> f2) koji demonstrira stack unwinding. U svakoj funkciji kreirati po jedan objekat na stack-u, a u f2 baciti iznimku.

5. **explicit - Valuta**: Kreirati strukturu `Dolar` sa explicit konstruktorom iz `double`. Onemogućiti implicitnu konverziju iz `double` u `Dolar`.

6. **Special members - Osoba**: Kreirati klasu `Osoba` sa dinamički alociranim stringom. Eksplicitno napisati copy konstruktor, move konstruktor, copy operator=, move operator= i destruktor. Demonstrirati da rade ispravno.

7. **Move - Performance**: Napisati program koji poredi brzinu copy i move za `std::vector<double>` sa 50,000,000 elemenata. Ispisati vrijeme izvršavanja.
