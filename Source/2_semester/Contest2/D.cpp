#include <iostream>
#include <vector>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int>> data(n);

  int k = 0;
  std::cin >> k;

  for (int i = 0; i < k; i++) {
    int operation = 0;
    int arg1 = 0;
    int arg2 = 0;
    std::cin >> operation;

    if (operation == 1) {
      std::cin >> arg1 >> arg2;

      data[arg1 - 1].push_back(arg2);
      data[arg2 - 1].push_back(arg1);
    }
    if (operation == 2) {
      std::cin >> arg1;

      for (auto e : data[arg1 - 1]) {
        std::cout << e << " ";
      }
      std::cout << "\n";
    }
  }
}