#include <array>
#include <iostream>

int main() {
  std::array<int, 1000000> data{};

  int n = 0;
  std::cin >> n;

  int key = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> key;
    data[key]++;
  }

  int target = 0;
  std::cin >> target;

  std::cout << data[target];
}