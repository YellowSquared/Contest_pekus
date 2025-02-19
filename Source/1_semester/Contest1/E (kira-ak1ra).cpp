#include <iostream>

int main() {
  int x = 0;
  std::cin >> x;
  std::cout << (x % 10) + (x / 100) + ((x % 100) / 10);
  return 0;
}
