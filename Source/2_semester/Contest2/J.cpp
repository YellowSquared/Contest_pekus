#include <iostream>

int main() {
  size_t n = 0;
  size_t answ = 0;
  std::cin >> n;
  int* matrix = new int[n * n];

  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      std::cin >> matrix[i * n + j];
    }
  }

  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
      if (matrix[i * n + j]) {
        ++answ;
      }
    }
  }

  std::cout << answ;

  delete[] matrix;
  return 0;
}
