#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;

  if (n == 0) {
    std::cout << 0;
    return 0;
  }

  int a = 0;
  int b = 1;
  int c = 0;

  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  std::cout << b;
}