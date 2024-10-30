
#include <iostream>

void PrintArray_1D(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

void Swap(int& lhs, int& rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
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

int main() {
  int n = 0;

  std::cin >> n;

  int* arr = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  int k = 0;
  std::cin >> k;

  QuickSortHoare(arr, 0, n - 1);

  int* result = new int[k];
  int fill = 0;

  for (int i = 0; i < k * 2; i += 2) {
    int interval_l = 0;
    int interval_h = 0;

    std::cin >> interval_l >> interval_h;

    for (int j = 0; j < n; j++) {
      if (arr[j] >= interval_l && arr[j] <= interval_h) {
        result[fill]++;
      }
    }
    fill++;
  }

  PrintArray_1D(result, k);

  delete[] arr;
  delete[] result;
}