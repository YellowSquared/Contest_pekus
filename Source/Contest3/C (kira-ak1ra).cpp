#include <iostream>

int main() {
  int arr[10000] = {};
  int x = 0;
  int zero_pointer = 0;
  for (int i = 0; i < 10000; ++i) {
    std::cin >> x;
    if (x != 0) {
      arr[zero_pointer] = x;
      ++zero_pointer;
    }
  }
  for (int i = 0; i < 10000; ++i) {
    std::cout << arr[i] << ' ';
  }
  return 0;
}
