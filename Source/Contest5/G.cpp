#include <iostream>

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
  int m = 0;
  std::cin >> m;

  n = n + m;

  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  QuickSortHoare(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
}