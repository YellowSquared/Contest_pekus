#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;

  int ten_power = 1000000;

  int* arr = new int[ten_power];

  for (int i = 0; i < ten_power; i++) {
    arr[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    int tmp = 0;
    std::cin >> tmp;

    arr[tmp]++;
  }

  for (int i = 0; i < ten_power; i++) {
    if (arr[i] != -1) {
      for (int j = 0; j < arr[i] + 1; j++) {
        std::cout << i << "\n";
      }
    }
  }

  delete[] arr;
}