#include <iostream>

void Diagonal(int k) {
  int* arr = new int[k * k];
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      if (k - i - 1 == j) {
        arr[i * k + j] = 1;
      } else if (k - i - 1 < j) {
        arr[i * k + j] = 2;
      } else {
        arr[i * k + j] = 0;
      }
      std::cout << arr[i * k + j] << ' ';
    }
    std::cout << '\n';
  }
  delete[] arr;
}

int main() {
  int n = 0;
  std::cin >> n;
  Diagonal(n);
  return 0;
}
