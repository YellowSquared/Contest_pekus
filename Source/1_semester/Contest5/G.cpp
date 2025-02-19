#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  int m = 0;
  std::cin >> m;

  int* arr1 = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr1[i];
  }

  int* arr2 = new int[m];
  for (int i = 0; i < m; i++) {
    std::cin >> arr2[i];
  }

  int pt1 = 0;
  int pt2 = 0;
  for (int i = 0; i < n + m && pt1 < n && pt2 < m; i++) {
    if (arr1[pt1] <= arr2[pt2]) {
      std::cout << arr1[pt1] << " ";
      pt1++;
    } else {
      std::cout << arr2[pt2] << " ";
      pt2++;
    }
  }

  if (pt1 < n) {
    for (int i = pt1; i < n; i++) {
      std::cout << arr1[i] << " ";
    }
  }

  if (pt2 < m) {
    for (int i = pt2; i < m; i++) {
      std::cout << arr2[i] << " ";
    }
  }

  delete[] arr1;
  delete[] arr2;
}