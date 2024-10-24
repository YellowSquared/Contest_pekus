#include <iostream>

int main() {
  int n = 0;
  int i = 1;
  int answ = 0;
  std::cin >> n;
  ++n;
  for (; i * i < n; ++i) {
    if (n % i == 0) {
      answ += 2;
    }
  }
  if (i * i == n) {
    ++answ;
  }
  if (n == 1) {
    std::cout << 1;
  } else {
    std::cout << answ;
  }
  return 0;
}
