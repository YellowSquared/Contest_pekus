#include <cmath>
#include <cstring>
#include <iostream>

void Swap(int& lhs, int& rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

void InsertionSort(int* arr, const int size) {
  for (int i = 1; i < size; i++) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      Swap(arr[j], arr[j - 1]);
    }
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  InsertionSort(arr, n);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}
