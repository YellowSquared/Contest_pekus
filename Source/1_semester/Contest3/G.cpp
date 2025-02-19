#include <iostream>

int main() {
  int n = 0;
  int k = 0;

  std::cin >> n >> k;

  int* array = new int[n];
  int* to_find = new int[k];

  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  for (int i = 0; i < k; i++) {
    std::cin >> to_find[i];
  }

  for (int i = 0; i < k; i++) {

    int start = 0;
    int end = n - 1;
    bool found = false;

    while (start <= end) {

      int mid = (start + end) / 2;

      if (array[mid] == to_find[i]) {
        std::cout << "YES"
          << "\n";
        found = true;
        break;
      }
      if (array[mid] < to_find[i]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    if (!found) {
      std::cout << "NO"
        << "\n";
    }
  }
  delete[] array;
  delete[] to_find;
}
