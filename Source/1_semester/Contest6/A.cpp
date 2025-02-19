#include <iostream>

void Swap(int& lhs, int& rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

int PartitionLomuto(int* arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high; j++) {
    if (arr[j] < pivot) {
      i++;
      Swap(arr[i], arr[j]);
    }
  }

  Swap(arr[i + 1], arr[high]);
  return i + 1;
}

int PartitionHoare(int* arr, int low, int high) {
  int pivot = arr[low];

  int i = low;
  int j = high;

  for (;;) {
    for (; arr[i] < pivot;) {
      i++;
    }

    for (; arr[j] > pivot;) {
      j--;
    }

    if (i >= j) {
      return j;
    }
    Swap(arr[i], arr[j]);
    i++;
    j--;
  }
}

void QuickSortLomuto(int* arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int piv = PartitionLomuto(arr, low, high);

  QuickSortLomuto(arr, low, piv - 1);
  QuickSortLomuto(arr, piv + 1, high);
}

void QuickSortHoare(int* arr, int low, int high) {
  if (low < high) {
    int piv = PartitionHoare(arr, low, high);

    QuickSortHoare(arr, low, piv);
    QuickSortHoare(arr, piv + 1, high);
  }
}

int main() {
  int n = 0;
  std::cin >> n;

  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  QuickSortHoare(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
}