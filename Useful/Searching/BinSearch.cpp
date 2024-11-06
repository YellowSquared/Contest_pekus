#include <iostream>

int BinarySearch(int* arr, int target, int low, int high) {
  while (low <= high) {
    int mid = (high + low) / 2;

    if (target == arr[mid]) {
      return mid;
    }
    if (target > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int f[] = {1, 2, 3, 4, 5, 6};

  std::cout << BinarySearch(f, 4, 0, 5);
}