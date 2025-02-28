#include <iostream>
#include <unordered_map>

int main() {
  int n = 0;
  int numb = 0;
  std::unordered_map<int, int> creatures;
  std::cin >> n;
  while (n) {
    std::cin >> numb;
    ++creatures[numb];
    --n;
  }
  std::cin >> n;
  while (n) {
    std::cin >> numb;
    std::cout << creatures[numb] << '\n';
    --n;
  }
  return 0;
}
