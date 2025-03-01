#include <iostream>

int main() {
  size_t n = 0;
  size_t m = 0;
  std::cin >> n >> m;
  int* matrix = new int[n * n];

	size_t a = 0;
  size_t b = 0;
    
  while (m) {
    std::cin >> a >> b;
    matrix[(a - 1) * n + b - 1] = 1;
    --m;
  }
    
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      std::cout << matrix[i * n + j] << ' ';
    }
    std::cout << '\n';
  }
  delete[] matrix;
  return 0;
}
