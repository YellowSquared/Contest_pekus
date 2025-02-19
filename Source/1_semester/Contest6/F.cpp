#include <iostream>

void Swap(int& lhs, int& rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

int BinarySearchH(int* arr, int target, int low, int high) {
  int mid = 0;
  while (low <= high) {
    mid = (high + low) / 2;
    if (target == arr[mid]) {
      while (mid < high && arr[mid] == arr[mid + 1]) {
        mid++;
      }
      return mid + 1;
    }
    if (target > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return mid;
}

int BinarySearch(int* arr, int target, int low, int high) {
  int mid = 0;
  while (low <= high) {
    mid = (high + low) / 2;
    if (target == arr[mid]) {
      return mid;
    }
    if (target > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return mid;
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

void QuickSortHoare(int* arr, int low, int high) {
  if (low < high) {
    int piv = PartitionHoare(arr, low, high);

    QuickSortHoare(arr, low, piv);
    QuickSortHoare(arr, piv + 1, high);
  }
}

void PrintArray1D(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int main() {
  int n = 0;
  std::cin >> n;

  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  QuickSortHoare(arr, 0, n - 1);
  // PrintArray_1D(arr, n);

  int k = 0;
  std::cin >> k;
  for (int i = 0; i < k; i++) {
    int left = 0;
    int right = 0;
    std::cin >> left >> right;
    // std::cout << BinarySearch(arr, left, 0, n - 1) << " "
    //           << BinarySearchH(arr, right, 0, n - 1) << "\n";
    std::cout << BinarySearchH(arr, right, 0, n - 1) - BinarySearch(arr, left, 0, n - 1) << " ";
  }

  delete[] arr;
}