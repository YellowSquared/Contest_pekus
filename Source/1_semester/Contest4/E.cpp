#include <iostream>

bool BinSearch(int* arr, const int n, const int aim) {
  int start = 0;
  int end = n - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (arr[mid] == aim) {
      return true;
    }

    if (arr[mid] < aim) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return false;
}
int main() {
  int n = 0;
  std::cin >> n;

  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  for (int i = 0; i < arr[n - 1]; i++) {
    if (!BinSearch(arr, n, i)) {
      std::cout << i;
      break;
    }
  }

  delete[] arr;
  return 0;
}