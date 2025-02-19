#include <iostream>

int main() {
  int64_t v = 0;
  int64_t t = 0;
  std::cin >> v;
  std::cin >> t;
  std::cout << ((v * t % 109) + 109) % 109 << std::endl;
  return 0;
}
