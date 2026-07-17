### Sadržaj
- [p1_review](./p1_review.cpp)
- [p2_templates](./p2_templates.cpp)
- [Pitanja](#pitanja)
- [Zadaci](#zadaci)

---

### Pitanja

**Pregled (lambda, iznimke, operator<<)**
1. Kako radi `std::function` i zašto je koristan?
2. Kako se koristi `std::vector::at()` i šta se desi kada indeks nije validan?
3. Kako se piše `operator<<` za ispis strukture/klase na `std::cout`?

**Templates**
4. Šta su template funkcije i čemu služe?
5. Kako kompajler generiše kod za template funkcije?
6. Koji je redoslijed kojim kompajler traži odgovarajuću funkciju?
7. Šta je specijalizacija template-a i zašto je koristimo?
8. Kako template-i omogućavaju da lambde proslijedimo kao parametre funkcije?
9. Kako se eksplicitno navode template parametri?
10. Koja je razlika između template funkcije i obične (non-template) funkcije?

### Zadaci

1. **Lambda + template**: Napisati template funkciju `pronadi(const std::vector<T>& vec, Lambda predikat)` koja vraća prvi element koji zadovoljava uslov. Testirati sa `int` i `std::string`.

2. **Template - max u nizu**: Napisati template funkciju `max_u_nizu(const std::vector<T>& vec)` koja vraća najveći element. Testirati sa `int`, `double`, `std::string`.

3. **Specijalizacija - bool ispis**: Napisati template funkciju `ispisi(T vrijednost)` i specijalizaciju za `bool` koja ispisuje "da" ili "ne".

4. **Template klasa - Stek**: Napisati template klasu `Stek<T>` sa metodama `push(T)`, `pop()` i `top()`. Testirati sa `int` i `std::string`.
