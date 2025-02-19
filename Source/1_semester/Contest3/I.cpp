#include <iostream>

int main() {
  int n = 0;
  int m = 0;

  std::cin >> n >> m;

  int* dowels = new int[n];
  int* drills = new int[m];

  for (int i = 0; i < n; i++) {
    std::cin >> dowels[i];
  }

  for (int i = 0; i < m; i++) {
    std::cin >> drills[i];
  }

  int result = 1000000001;

  for (int i = 0; i < n; i++) {
    int to_find = dowels[i];

    int start = 0;
    int end = m - 1;

    while (start <= end) {
      int mid = (start + end) / 2;

      if (to_find == drills[mid]) {
        break;
      }

      if (to_find > drills[mid]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
      int distance = std::abs(to_find - drills[(start + end) / 2]);
      result = std::min(result, distance);
    }

    if (result == 0) {
      break;
    }
  }

  std::cout << result;

  delete[] dowels;
  delete[] drills;

  return 0;
}