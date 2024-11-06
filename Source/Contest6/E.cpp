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

  int* heights = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> heights[i];
  }

  int k = 0;
  std::cin >> k;

  int old_value = heights[k - 1];
  heights[k - 1] = -1;

  QuickSortHoare(heights, 0, n - 1);

  int* result = new int[n];

  for (int i = 1; i < k; i++) {
    result[i - 1] = heights[i];
  }

  result[k - 1] = old_value;

  for (int i = k; i < n; i++) {
    result[i] = heights[i];
  }

  for (int i = 0; i < n; i++) {
    std::cout << result[i] << " ";
  }

  delete[] heights;
  delete[] result;
}