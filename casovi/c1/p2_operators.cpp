// Operatori:
// https://cppreference.com/w/cpp/language/expressions.html#Operators
// https://en.cppreference.com/w/cpp/language/operator_precedence.html (prioritet operatora)

int main()
{
  int a = 10;
  int b = 20;

  a + b;
  a - b;
  a * b;
  a / b;
  a % b;

  +a;
  -a;

  a++;
  a--;
  ++a;
  --a;

  a << b;
  a >> b;

  a == b;
  a != b;
  a > b;
  a < b;
  a >= b;
  a <= b;

  a && b;
  a || b;
  !a;

  a & b;
  a | b;
  a ^ b;
  ~a;

  a ? 10 : 20;

  a = b;
  a += b;
  a -= b;
  // ...

  10 + 20 * 30;
  true && true || false;
  a = b = 20;
}
