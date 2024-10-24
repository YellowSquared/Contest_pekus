#include <iostream>

int main() {
  int n = 0;
  int x = 0;
  std::cin >> n;
  int arr_numbers[10] = {};
  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    ++arr_numbers[x];
  }
  for (int i = 9; i >= 0; --i) {
    for (int j = 0; j < arr_numbers[i]; j++) {
      std::cout << i;
    }
  }
  return 0;
}
