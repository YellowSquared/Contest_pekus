#include <iostream>
int o = 0;
int Fibo(int n) {
  o++;
  if (n == 2 || n == 1) {
    return 1;
  }
  return Fibo(n - 1) + Fibo(n - 2);
}

int main() {
  int n = 0;
  std::cin >> n;
  Fibo(n);
  std::cout << o;

  // std::cout << Fibo(n);
}