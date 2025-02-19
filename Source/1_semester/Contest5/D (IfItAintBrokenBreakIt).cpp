#include <iostream>
#include <cmath>

void Function(int n) {
  int arr[50][50];
  for (int i = 0; i < n; i += 1) {
    if (i <= n / 2) {
      if (i % 2 == 0) {
        int j = 0;
        for (; j < (i / 2 - 1) * 2; j += 2) {
          arr[i][j] = 1;
          arr[i][j + 1] = 0;
          std::cout << arr[i][j] << arr[i][j + 1];
        }
        for (; j < n - i; j += 1) {
          arr[i][j] = 1;
          std::cout << arr[i][j];
        }
        for (; j < n; j += 2) {
          arr[i][j] = 0;
          arr[i][j + 1] = 1;
          std::cout << arr[i][j] << arr[i][j + 1];
        }
      } else {
        int j = 0;
        for (; j < i - 1; j += 2) {
          arr[i][j] = 1;
          arr[i][j + 1] = 0;
          std::cout << arr[i][j] << arr[i][j + 1];
        }
        for (; j < n - i - 1; j += 1) {
          arr[i][j] = 0;
          std::cout << arr[i][j];
        }
        for (; j < n; j += 2) {
          arr[i][j] = 0;
          arr[i][j + 1] = 1;
          std::cout << arr[i][j] << arr[i][j + 1];
        }
      }
    } else if (i > n / 2) {
      if (i % 2 == 0) {
        int j = 0;
        for (; j < n - i - 1; j += 2) {
          arr[i][j] = 1;
          arr[i][j + 1] = 0;
          std::cout << arr[i][j] << arr[i][j + 1];
        }
        for (; j < i + 1; j += 1) {
          arr[i][j] = 1;
          std::cout << arr[i][j];
        }
        for (; j < n; j += 2) {
          arr[i][j] = 0;
          arr[i][j + 1] = 1;
          std::cout << arr[i][j] << arr[i][j + 1];
        }
      } else {
        int j = 0;
        for (; j < n - i; j += 2) {
          arr[i][j] = 1;
          arr[i][j + 1] = 0;
          std::cout << arr[i][j] << arr[i][j + 1];
        }
        for (; j < i; j += 1) {
          arr[i][j] = 0;
          std::cout << arr[i][j];
        }
        for (; j < n; j += 2) {
          arr[i][j] = 0;
          arr[i][j + 1] = 1;
          std::cout << arr[i][j] << arr[i][j + 1];
        }
      }
    }
    std::cout << "\n";
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  Function(n);
  return 0;
}
