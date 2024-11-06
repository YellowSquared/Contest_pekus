#include <iostream>

double Exponent(double a, int n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return Exponent(a * a, n / 2);
  }
  return a * Exponent(a * a, (n - 1) / 2);
}

int main() {
  double a = 0;
  int n = 0;
  std::cin >> a >> n;

  std::cout << Exponent(a, n);
}