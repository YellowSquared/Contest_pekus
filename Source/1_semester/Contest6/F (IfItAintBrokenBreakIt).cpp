#include <iostream>

void QuickSort(int* arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = arr[high];
  int i = low;
  for (int j = low; j < high; j += 1) {
    if (arr[j] < pivot) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i += 1;
    }
  }
  arr[high] = arr[i];
  arr[i] = pivot;
  QuickSort(arr, low, i - 1);
  QuickSort(arr, i + 1, high);
}

int main() {
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i += 1) {
    std::cin >> arr[i];
  }
  QuickSort(arr, 0, n - 1);
  int k = 0;
  std::cin >> k;
  int l = 0;
  int r = 0;
  for (int i = 0; i < k; i += 1) {
    std::cin >> l;
    std::cin >> r;
    int left = 0;
    int right = n - 1;
    while (left < right - 1) {
      int mid = (left + right) / 2;
      if (arr[mid] < l) {
        left = mid;
      } else {
        right = mid;
      }
    }
    int start = right;
    if (l <= arr[0]) {
      start = 0;
    }
    left = 0;
    right = n - 1;
    while (left < right - 1) {
      int mid = (left + right) / 2;
      if (arr[mid] <= r) {
        left = mid;
      } else {
        right = mid;
      }
    }
    int end = left;
    if (r >= arr[n - 1]) {
      end = n - 1;
    }
    std::cout << end - start + 1 << " ";
  }
  delete[] arr;
}
