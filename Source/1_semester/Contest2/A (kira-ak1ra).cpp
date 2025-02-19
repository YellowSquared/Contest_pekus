#include <iostream>
#include <cstdint>

int main() {
  uint64_t n = 0;
  uint64_t i = 1;
  int answ = 0;
  std::cin >> n;
  for (; i * i < n; ++i) {
    if (n % i == 0) {
      answ += 2;
    }
  }
  if (i * i == n) {
    answ++;
  }
  if (n == 1) {
    std::cout << 1;
  } else {
    std::cout << answ;
  }
  return 0;
}
