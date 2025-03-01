#include <iostream>
#include <unordered_map>

int main() {
  int n = 0;
  int numb = 0;
  std::unordered_map<int, int> dict;
  std::cin >> n;
  while (n) {
    std::cin >> numb;
    ++dict[numb];
    --n;
  }
  std::cin >> numb;
  std::cout << dict[numb];
  return 0;
}
