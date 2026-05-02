### Sadrzaj
- [p1_static_methods](./p1_static_methods.cpp)
- [p2_constructor](./p2_constructor.cpp)
- [p3_member_initializer_list](./p3_member_initializer_list.cpp)
- [p4_encapsulation](./p4_encapsulation.cpp)
- [p5_class](./p5_class.cpp)
- [p6_destructor](./p6_destructor.cpp)
- [todo](./todo.cpp)
- [Pitanja](#pitanja)
- [Zadaci](#zadaci)

---

### Pitanja
- Šta je to konstruktor i koja su pravila za njegovo imenovanje?
- Da li klasa/struktura ima konstruktore ako ih mi ne definišemo (da li ih kompajler pravi)? Koje? Šta se desi sa njih ako mi definišemo neki svoj konstruktor?
- Da li konstruktor može imati povratnu vrijednost?
- Čemu služi ključna riječ `this`? Kojeg je ona tipa?
- Šta je to lista za inicijalizaciju (*member initializer list*)? Koje su prednosti korištenja liste u odnosu na dodjelu vrijednosti unutar tijela konstruktora?
- Koja je glavna razlika između `struct` i `class` u C++?
- Šta je to enkapsulacija i koji je njen glavni cilj?
- Objasni razliku između `public` i `private` modifikatora pristupa.
- Šta su to *getters* i *setters* metode i zašto ih koristimo?
- Šta je destruktor, kada se on izvršava i koliko destruktora jedna klasa može imati?
- Da li destruktor može primati argumente?
- Šta su statički članovi klase i kako se oni inicijaliziraju?
- Koja je razlika između statičkih metoda i običnih metoda klase u pogledu pristupa članovima i korištenja `this` pointera?

### Zadaci
- Kreirati klasu `Racun` koja ima privatne članove `broj_racuna` i `stanje`. Implementirati konstruktor koji prima dva parametra i inicijalizira članove koristeći listu za inicijalizaciju. Implementirati metode za uplatu i isplatu novca.
- Napisati klasu `Automobil` sa privatnim poljima `marka` i `godiste`. Osigurati da se `godiste` ne može postaviti na vrijednost manju od 1886 (godina prvog auta). Koristiti settere za provjeru.
- Napraviti klasu `Counter` koja ima statički član `brojac`. Svaki put kada se kreira novi objekat, `brojac` se treba uvećati, a kada se objekat uništi, `brojac` se umanjuje. Ispisivati trenutno stanje brojača iz `main` funkcije.
- Napisati klasu `Student` koja sadrži `std::vector` ocjena. Implementirati metodu za dodavanje ocjene i metodu koja vraća prosječnu ocjenu.
- Kreirati klasu koja u konstruktoru dinamički alocira niz cijelih brojeva, a u destruktoru oslobađa tu memoriju. Pripaziti na *memory leak*.
