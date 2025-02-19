#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  int k = 0;

  std::cin >> n >> k;

  int* array = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  int left = 0;
  int right = array[n - 1] - array[0] + 1;

  while (left < right) {
    int mid = (left + right) / 2;

    int last_cow = array[0];
    int cows_placed = 1;

    for (int i = 1; i < n; i++) {
      if (array[i] - last_cow > mid) {
        last_cow = array[i];
        cows_placed++;
      }
    }

    if (cows_placed >= k) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  std::cout << left;

  delete[] array;

  return 0;
}