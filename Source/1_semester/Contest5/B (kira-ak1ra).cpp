#include <iostream>

void PascalTriangle(int a, int b) {
  int* pascal_triangle = new int[a * b];
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      if (i == 0 || j == 0) {
        pascal_triangle[i * b + j] = 1;
      } else {
        pascal_triangle[i * b + j] = pascal_triangle[(i - 1) * b + j] + pascal_triangle[i * b + j - 1];
      }
      std::cout << pascal_triangle[i * b + j] << ' ';
    }
    std::cout << std::endl;
  }
  delete[] pascal_triangle;
}

int main() {
  int a = 3;
  int b = 3;
  std::cin >> a >> b;
  PascalTriangle(a, b);
  return 0;
}
