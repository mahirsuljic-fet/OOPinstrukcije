// Reference:
// https://en.cppreference.com/w/cpp/language/reference.html

int a;

int& lra = a;
const int& clra = a;
int&& rra = 10;
const int&& crra = 10;

int& lra2 = lra;
