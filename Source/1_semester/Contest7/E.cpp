#include <iostream>

void Reverse(int n) {
  int val = 0;
  std::cin >> val;

  if (n == 1) {
    std::cout << val << " ";
    return;
  }
  Reverse(n - 1);
  std::cout << val << " ";
}

int main() {
  int n = 0;
  std::cin >> n;

  Reverse(n);
}