#include <iostream>
#include <cmath>

int main() {
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i += 1) {
    std::cin >> arr[i];
  }
  int amount_of_numbers[1000001] = {};
  for (int i = 0; i < n; i += 1) {
    amount_of_numbers[arr[i]] += 1;
  }
  for (int i = 0; i < 1000001; i += 1) {
    if (amount_of_numbers[i] != 4 and amount_of_numbers[i] != 0) {
      std::cout << i;
      break;
    }
  }
  delete[] arr;
  return 0;
}
