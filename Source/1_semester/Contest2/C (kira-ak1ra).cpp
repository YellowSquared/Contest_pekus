#include <iostream>
#include <cstdint>

int main() {
  uint64_t n = 0;
  std::cin >> n;
  // Отдельно просчитываем 2, т.к. единственное чётное простое число
  while (n % 2 == 0) {
    std::cout << 2 << ' ';
    n = n / 2;
  }
  for (uint64_t x = 3; x * x <= n; x += 2) {
    while (n % x == 0) {
      std::cout << x << ' ';
      n = n / x;
    }
  }
  if (n != 1) {
    std::cout << n;
  }
  return 0;
}
