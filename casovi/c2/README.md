### Sadrzaj
- [p01_stack_heap](./p01_stack_heap.cpp)
- [p02_string](./p02_string.cpp)
- [p03_vector](./p03_vector.cpp)
- [p04_typedef](./p04_typedef.cpp)
- [p05_using](./p05_using.cpp)
- [p06_function_overloading](./p06_function_overloading.cpp)
- [p07_reference_parameters](./p07_reference_parameters.cpp)
- [p08_default_arguments](./p08_default_arguments.cpp)
- [p09_struct](./p09_struct.cpp)
- [p10_method](./p10_method.cpp)
- [p11_const_methods](./p11_const_methods.cpp)
- [Pitanja](#pitanja)
- [Zadaci](#zadaci)

---

### Pitanja
- Gdje se u memoriji (stack ili heap) nalaze varijable kreirane koristeći operator `new`?
- Koja je razlika u životnom vijeku (lifetime) varijabli na stack-u u odnosu na one na heap-u? Kada se vrši brisanje varijable sa stack-a, a kada sa heap-a?
- Šta se dešava ako se ne pozove operator `delete` za memoriju koja je alocirana sa `new`? Kako se naziva taj problem?
- Šta je to preopterećenje funkcija (*function overloading*)? Na osnovu čega kompajler razlikuje preopterećene funkcije?
- Da li je moguće overload-ati funkciju isključivo na osnovu različitog povratnog tipa?
- Šta su default argumenti?
- Ako se koristi default argument za jedan parametar, da li još neki parametri moraju imati default argument? Koji?
- Šta su to `const` metodi? Šta se postiže njihovim korištenjem?
- Da li je moguće pozvati ne-konstantni metod nad konstantnim objektom? Zašto?
- Šta je to overloading po konstantnosti? Navesti primjer kada bi to bilo korisno.

### Zadaci
- Napisati program koji od korisnika traži broj elemenata niza, a zatim na heap-u alocira niz tog kapaciteta. Korisnik treba unijeti elemente, a program ispisati njihovu sumu i osloboditi memoriju.
- Napisati funkciju `pomnozi` koja prima dva argumenta. Ako se proslijedi jedan argument, funkcija ga množi sa 2. Ako se proslijede dva argumenta, funkcija ih množi međusobno. Koristiti default argumente.
- Napisati tri funkcije `max` koje vraćaju veći od dva proslijeđena broja za tipove `int`, `double` i `char`.
- Kreirati strukturu `Knjiga` sa poljima `naslov` i `cijena`. Dodati metodu `povecaj_cijenu(double procenat)` i `const` metodu `print()`. Demonstrirati pozive nad običnim i `const` objektom.
- Napraviti funkciju koja prima `std::vector<std::string>` po referenci i ispisuje sve stringove koji su duži od 5 karaktera.
