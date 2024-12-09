#include <iostream>

void QuickSort(int* arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = arr[(low + high) / 2];
  int i = low;
  int j = high;
  while (true) {
    while (arr[i] < pivot) {
      i += 1;
    }
    while (arr[j] > pivot) {
      j -= 1;
    }
    if (i >= j) {
      break;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i += 1;
    j -= 1;
  }
  QuickSort(arr, low, j);
  QuickSort(arr, j + 1, high);
}

int main() {
  int n = 0;
  std::cin >> n;
  int* starts = new int[n];
  int* ends = new int[n];
  for (int i = 0; i < n; i += 1) {
    std::cin >> starts[i];
    std::cin >> ends[i];
  }
  QuickSort(starts, 0, n - 1);
  QuickSort(ends, 0, n - 1);
  int result = 0;
  int intersections = 0;
  for (int i = 0; i < n - 1; i += 1) {
    if (starts[i + 1] >= ends[i]) {
      result += ends[i] - starts[i - intersections];
      intersections = 0;
    } else {
      intersections += 1;
    }
  }
  result += ends[n - 1] - starts[n - 1 - intersections];
  std::cout << result;
  delete[] starts;
  delete[] ends;
}
