#include <iostream>

int BinarySearch(int value, int* arr, int length) {
  int left = 0;
  int right = length - 1;
  int middle = left + (right - left) / 2;
    while (left <= right) {
    middle = left + (right - left) / 2;
    if (arr[middle] == value) {
      return middle;
    }
    if (arr[middle] < value) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return -1;
}

int main() {
  int n = 0;
  int k = 0;
  int x = 0;
  std::cin >> n >> k;
  int* arr = new int[n];
  bool* answers = new bool[k];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::cout << BinarySearch(k, arr, n);
  delete[] arr;
  return 0;
}
