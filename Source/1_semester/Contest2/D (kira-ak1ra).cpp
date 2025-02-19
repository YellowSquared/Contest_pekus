#include <iostream>

int main() {
  unsigned int n = 0;
  std::cin >> n;
  if (n == 0) {
    std::cout << 0;
  } else {
    bool is_run = false;
    for (unsigned int mask = 1 << 31; mask; mask = mask >> 1) {
      is_run = (is_run) | (!(n % mask == n));
      if (is_run) {
        std::cout << ((n & mask) ? 1 : 0);
      }
    }
  }
  return 0;
}
