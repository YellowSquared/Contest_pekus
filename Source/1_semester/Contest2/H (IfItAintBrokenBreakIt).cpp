#include <iostream>
#include <cmath>

int main() {
  u_int64_t x = 0;
  std::cin >> x;
  bool flag = false;
  for (u_int64_t y2 = x; y2 <= x + x / 100; y2 += 1) {
    u_int64_t y = y2;
    u_int64_t prime_devisor1 = 0;
    u_int64_t amount_of_prime_devisors1 = 0;
    u_int64_t prime_devisor2 = 0;
    u_int64_t amount_of_prime_devisors2 = 0;
    u_int64_t prime_devisor3 = 0;
    u_int64_t amount_of_prime_devisors3 = 0;
    u_int64_t prime_devisor4 = 0;
    u_int64_t amount_of_prime_devisors4 = 0;
    u_int64_t prime_devisor5 = 0;
    u_int64_t amount_of_prime_devisors5 = 0;
    u_int64_t prime_devisor6 = 0;
    u_int64_t amount_of_prime_devisors6 = 0;
    u_int64_t prime_devisor7 = 0;
    u_int64_t amount_of_prime_devisors7 = 0;
    u_int64_t i = 2;
    u_int64_t q = 2;
    for (int k = 7; k > 1; k -= 1) {
      u_int64_t m = 0;
      for (; m < y; i += 1) {
        m = i;
        for (int n = 0; n < k - 1; n += 1) {
          m *= i;
        }
      }
      for (u_int64_t j = q; j <= i and j <= y; j += 1) {
        while (y % j == 0) {
          y /= j;
          if (prime_devisor1 == 0 or prime_devisor1 == j) {
            prime_devisor1 = j;
            amount_of_prime_devisors1 += 1;
          } else if (prime_devisor2 == 0 or prime_devisor2 == j) {
            prime_devisor2 = j;
            amount_of_prime_devisors2 += 1;
          } else if (prime_devisor3 == 0 or prime_devisor3 == j) {
            prime_devisor3 = j;
            amount_of_prime_devisors3 += 1;
          } else if (prime_devisor4 == 0 or prime_devisor4 == j) {
            prime_devisor4 = j;
            amount_of_prime_devisors4 += 1;
          } else if (prime_devisor5 == 0 or prime_devisor5 == j) {
            prime_devisor5 = j;
            amount_of_prime_devisors5 += 1;
          } else if (prime_devisor6 == 0 or prime_devisor6 == j) {
            prime_devisor6 = j;
            amount_of_prime_devisors6 += 1;
          } else if (prime_devisor7 == 0 or prime_devisor7 == j) {
            prime_devisor1 = j;
            amount_of_prime_devisors1 += 1;
          }
        }
      }
      if (amount_of_prime_devisors1 + amount_of_prime_devisors2 + amount_of_prime_devisors3 +
              amount_of_prime_devisors4 + amount_of_prime_devisors5 + amount_of_prime_devisors6 +
              amount_of_prime_devisors7 <
          (8 - static_cast<u_int64_t>(k))) {
        break;
      }
      q = i + 1;
    }
    if (prime_devisor7 == 0 and y != 1) {
      prime_devisor7 = y;
      amount_of_prime_devisors7 = 1;
    }
    if ((amount_of_prime_devisors1 + 1) * (amount_of_prime_devisors2 + 1) * (amount_of_prime_devisors3 + 1) *
            (amount_of_prime_devisors4 + 1) * (amount_of_prime_devisors5 + 1) * (amount_of_prime_devisors6 + 1) *
            (amount_of_prime_devisors7 + 1) >=
        100) {
      std::cout << y2;
      flag = true;
      break;
    }
  }
  if (not flag) {
    std::cout << -1;
  }
  return 0;
}
