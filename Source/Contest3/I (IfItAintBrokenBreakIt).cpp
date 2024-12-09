#include <iostream>
#include <cmath>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int* arr_n = new int[n];
  int* arr_m = new int[m];
  for (int i = 0; i < n; i += 1) {
    std::cin >> arr_n[i];
  }
  for (int i = 0; i < m; i += 1) {
    std::cin >> arr_m[i];
  }
  int min = 0;
  if (arr_n[0] > arr_m[0]) {
    min = arr_n[0] - arr_m[0];
  } else {
    min = arr_m[0] - arr_n[0];
  }
  int left_n = 0;
  int left_m = 0;
  while (left_n < n and left_m < m) {
    if (arr_n[left_n] > arr_m[left_m]) {
      if (arr_n[left_n] - arr_m[left_m] < min) {
        min = arr_n[left_n] - arr_m[left_m];
      }
      if (left_m < m) {
        left_m += 1;
      } else {
        break;
      }
    } else if (arr_n[left_n] < arr_m[left_m]) {
      if (arr_m[left_m] - arr_n[left_n] < min) {
        min = arr_m[left_m] - arr_n[left_n];
      }
      if (left_n < n) {
        left_n += 1;
      } else {
        break;
      }
    } else {
      min = 0;
      break;
    }
  }
  std::cout << min;
  delete[] arr_n;
  delete[] arr_m;
  return 0;
}
