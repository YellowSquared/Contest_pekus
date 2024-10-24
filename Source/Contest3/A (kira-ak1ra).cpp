#include <iostream>

int main() {
  unsigned int mask = 1;
  unsigned int num = 0;
  std::cin >> num;
  while (mask < num) {
    mask = (mask << 1) + 1;
  }
  std::cout << (~num) - (~mask);
  return 0;
}
