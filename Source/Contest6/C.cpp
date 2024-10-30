#include <iostream>
void Swap(int64_t& lhs, int64_t& rhs) {
  int64_t tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

int64_t PartitionHoare(int64_t* arr, int64_t low, int64_t high) {
  int64_t pivot = arr[low];

  int64_t i = low;
  int64_t j = high;

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

void QuickSortHoare(int64_t* arr, int64_t low, int64_t high) {
  if (low < high) {
    int64_t piv = PartitionHoare(arr, low, high);

    QuickSortHoare(arr, low, piv);
    QuickSortHoare(arr, piv + 1, high);
  }
}

int main() {
  int n = 0;
  std::cin >> n;

  n *= 2;

  auto* arr = new int64_t[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  QuickSortHoare(arr, 0, n - 1);

  // for (int i = 0; i < n; i++) {
  //   std::cout << arr[i] << " ";
  // }

  // std::cout << "\n";

  u_int64_t result = 0;

  for (int i = 0; i < n - 1; i++) {
    result += arr[i + 1] - arr[i];
  }

  std::cout << result;

  delete[] arr;
}