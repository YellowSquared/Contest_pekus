#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  std::vector<int> colors(n);
  for (int i = 0; i < n; i++) {
    std::cin >> colors[i];
  }
  int m = 0;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    int color = 0;
    std::cin >> color;
    auto low = std::lower_bound(colors.begin(), colors.end(), color);
    auto up = std::upper_bound(colors.begin(), colors.end(), color);
    std::cout << up - low << '\n';
  }
  return 0;
}
