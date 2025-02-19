#include <iostream>

int main() {
  int n = 0;
  int x = 0;
  int answ = 0;
  std::cin >> n;
  while (n) {
    std::cin >> x;
    answ = answ ^ x;
    --n;
  }
  std::cout << answ;
  return 0;
}