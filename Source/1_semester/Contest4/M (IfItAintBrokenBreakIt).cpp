#include <iostream>
#include <cmath>

int main() {
  u_int64_t k = 0;
  std::cin >> k;
  k -= 1;
  u_int64_t result = 0;
  while (k > 0) {
    u_int64_t power_of_2 = 1;
    while (power_of_2 <= k) {
      power_of_2 *= 2;
    }
    power_of_2 /= 2;
    result += 1;
    k -= power_of_2;
  }
  std::cout << result % 3;
  return 0;
}
