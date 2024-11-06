#include <iostream>

void PrintArray1D(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

void ViusalArray_1D(int* arr, int n) {
  std::cout << "{ ";
  for (int i = 0; i < n ; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[n - 1] << " }\n";
}