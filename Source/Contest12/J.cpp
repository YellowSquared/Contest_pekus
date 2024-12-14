#include <cmath>
#include <iostream>
#include <stdexcept>

int main() {
  double n = 0;
  std::cin >> n;

  double danger = (1 + (2 * (n - 2))) * pow(2, n - 2);

  std::cout << std::pow(3, n) - danger;
}