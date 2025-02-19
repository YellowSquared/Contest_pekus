#include <iostream>

void Swap(int64_t &lhs, int64_t &rhs) {
  int64_t tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

int64_t PartitionLomuto(int64_t *arr, int64_t low, int64_t high) {
  int64_t pivot = arr[high];
  int64_t i = low;
  for (int64_t j = low; j < high; j++) {
    if (arr[j] < pivot) {
      Swap(arr[i], arr[j]);
      i++;
    }
  }
  Swap(arr[i], arr[high]);
  return i;
}

// int PartitionHoar(int *arr, int low, int high) {
//   int pivot = arr[(low + high) / 2];
//   int i = low;
//   int j = high;
//   while (true) {
//     while (arr[i] < pivot) {
//       i++;
//     }
//     while (arr[j] > pivot) {
//       j--;
//     }
//     if (i >= j) {
//       return j;
//     }
//     Swap(arr[i], arr[j]);
//     i++;
//     j--;
//   }
// }

// void QuickSortHoar(int *arr, int low, int high) {
//   if (low >= high) {
//     return;
//   }

//   int pivot_idx = PartitionHoar(arr, low, high);
//   QuickSortHoar(arr, low, pivot_idx);
//   QuickSortHoar(arr, pivot_idx + 1, high);
// }

void QuickSortLomuto(int64_t *arr, int64_t low, int64_t high) {
  if (low >= high) {
    return;
  }

  int64_t pivot_idx = PartitionLomuto(arr, low, high);
  QuickSortLomuto(arr, low, pivot_idx - 1);
  QuickSortLomuto(arr, pivot_idx + 1, high);
}

int main() {
  int64_t n = 0;
  int64_t m = 0;
  int64_t k = 0;
  std::cin >> n >> m >> k;
  auto *arr = new int64_t[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSortLomuto(arr, 0, n - 1);
  int64_t low = 0;
  int64_t high = arr[n - 1] - arr[0];
  int64_t res = high;
  while (low <= high) {
    int64_t mid = (low + high) / 2;
    int64_t count = 0;
    int64_t i = 0;
    while (i + k <= n) {
      if (arr[i + k - 1] - arr[i] <= mid) {
        count++;
        i += k;
        if (count >= m) {
          break;
        }
      } else {
        i++;
      }
    }

    if (count >= m) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  std::cout << res;
  delete[] arr;
}
