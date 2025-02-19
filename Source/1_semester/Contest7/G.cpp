#include <iostream>
int Fibo(int n, int& count) {
  count++;
  if (n == 2 || n == 1) {
    return n;
  }
  return Fibo(n - 1, count) + Fibo(n - 2, count);
}

int main() {
  int n = 0;
  std::cin >> n;

  int result = 0;

  Fibo(n, result);
  std::cout << result;
}