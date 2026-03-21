#include <iostream>

double PI = 3.14159;
static int secret = 10;

int sum(int a, int b) { return a + b; }
int mult(int a, int b) { return a * b; }

void print_secret() { std::cout << "secret is: " << secret << std::endl; }
