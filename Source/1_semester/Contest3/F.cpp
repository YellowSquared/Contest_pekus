#include <iostream>

int main() {
  int a = 0;
  int b = 0;

  std::cin >> a >> b;

  bool* prime = new bool[b + 1];

  for (int i = 0; i <= b; i++) {
    prime[i] = true;
  }
  prime[1] = false;

  for (int p = 2; p * p <= b; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= b; i += p) {
        prime[i] = false;
      }
    }
  }

  for (int i = a; i <= b; i++) {
    if (prime[i]) {
      std::cout << i << "\n";
    }
  }

  delete[] prime;
}