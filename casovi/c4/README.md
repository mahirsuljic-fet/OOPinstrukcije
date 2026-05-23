### Sadrzaj
- [p1_iterators](./p1_iterators.cpp)
- [p2_list](./p2_list.cpp)
- [p3_back_inserter](./p3_back_inserter.cpp)
- [p4_front_inserter](./p4_front_inserter.cpp)
- [p5_inserter](./p5_inserter.cpp)
- [p6_algorithms](./p6_algorithms.cpp)
- [p7_lambda_basics](./p7_lambda_basics.cpp)
- [p8_lambda](./p8_lambda.cpp)
- [p9_operator_overloading](./p9_operator_overloading.cpp)
- [banka](./banka.cpp)
- [calculator](./calculator.cpp)
- [coordinates](./coordinates.cpp)
- [shop](./shop.cpp)
- [songs](./songs.cpp)
- [Pitanja](#pitanja)
- [Zadaci](#zadaci)

---

### Pitanja

**Iteratori i Inserteri**
1. Koja je razlika između `begin()`/`end()` i `cbegin()`/`cend()` iteratora?
2. Šta su `reverse_iterator`-i i koje metode koristiti za dobijanje početka i kraja unazad?
3. Čemu služe `std::back_inserter`, `std::front_inserter` i `std::inserter`?
4. Objasniti razlike između kategorija iteratora: **forward**, **bidirectional** i **random access** iteratora.
5. Šta je **for-range** loop i koje uslove (metode) klasa mora ispuniti da bi se mogla koristiti u ovakvoj petlji?

**Algoritmi**
6. Koja je uloga `std::find_if` algoritma i šta on prima kao treći argument?
7. Kako funkcioniše `std::sort` algoritam i na koji način mu možemo proslijediti custom kriterij sortiranja?

**Lambda expressions i std::function**
8. Šta je **lambda** expression (anonimna funkcija) i iz kojih dijelova se sastoji njena sintaksa?
9. Objasniti razliku između capture-anja varijabli po vrijednosti (`[=]`) i po referenci (`[&]`) u **lambda** funkcijama.
10. Kada je potrebno koristiti ključnu riječ `mutable` kod **lambda** funkcija?
11. Šta je `std::function` i kako definisati njen tip (npr. za funkciju koja prima `int` i vraća `bool`)?
12. Koja je prednost korištenja `std::function` u odnosu na obične funkcija **pointere**?

**Operator Overloading**
13. Na koja dva načina je moguće uraditi **operator overloading** u C++-u?
14. Zašto neki operator (npr. `operator*`) definisati kao globalnu funkciju, a ne kao metod klase/strukture?
15. Šta su **binary** a šta **unary** operatori, i kako se razlikuje njihovo overload-anje?

### Zadaci

1. **Iteratori i Algoritmi**: Kreirati `std::vector<int>` sa nasumičnim brojevima. Koristeći iteratore i `std::sort` sa custom **lambda** funkcijom, sortirati vektor u opadajućem redoslijedu. Zatim koristiti `std::find_if` za pronalaženje prvog broja većeg od 50.
2. **Banka - Sortiranje**: Proširiti primjer `banka.cpp` tako da se računi mogu sortirati ne samo po imenu, već i po stanju na računu (balance) koristeći **lambda** funkcije.
3. **Shop Inventory**: Implementirati jednostavnu prodavnicu koristeći `std::map<std::string, int>` gdje je ključ naziv proizvoda, a vrijednost količina. Koristiti iteratore za prolazak kroz inventar i ispis svih proizvoda čija je količina manja od 5.
4. **Lambda i std::function - Calculator**: Napraviti klasu `Calculator` koja ima metod `calculate(double a, double b, std::function<double(double, double)> op)`. Pozvati ovaj metod prosljeđujući mu različite **lambda** funkcije za sabiranje, množenje i stepenovanje.
5. **Operator Overloading - Coordinates**: Implementirati klasu `Coordinate` koja ima `x` i `y`. Overload-ovati operatore `+` i `-` kao metode klase, te operator `<<` za ispis na `std::ostream` kao globalnu funkciju.
