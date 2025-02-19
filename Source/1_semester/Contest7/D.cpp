#include <iostream>

int Sum(int a, int b) {
  if (b > 0) {
    return Sum(a + 1, b - 1);
  }
  return a;
}
int main() {
  int a = 0;
  int b = 0;
  std::cin >> a >> b;

  std::cout << Sum(a, b);
}