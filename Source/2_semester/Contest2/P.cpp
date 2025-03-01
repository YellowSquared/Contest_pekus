#include <iostream>
#include <vector>

int main() {
  size_t n = 0;
  size_t m = 0;
  size_t a = 0;
  size_t b = 0;
  std::cin >> n >> m;
  std::vector<int> vertex(n);

  for (size_t i = 0; i < n; ++i) {
    vertex[i] = 0;
  }
  while (m) {
    std::cin >> a >> b;
    ++vertex[a - 1];
    ++vertex[b - 1];
    --m;
  }
  for (int value : vertex) {
    std::cout << value << ' ';
  }
  return 0;
}
