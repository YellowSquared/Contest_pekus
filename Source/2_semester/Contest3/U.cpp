#include <iostream>
#include <vector>

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  int size_;

 public:
  explicit Graph(int n, int m) {
    size_ = n;
    vertices_.resize(n);
    for (int i = 0; i < m; i++) {
      int v1 = 0;
      int v2 = 0;
      std::cin >> v1 >> v2;
      --v1;
      --v2;
      vertices_[v1].push_back(v2);
      vertices_[v2].push_back(v1);
    }
  }

  std::vector<int> Chrom(int k) {
    std::vector<int> colors(size_, -1);
    for (int i = 0; i < size_; i++) {
      std::vector<int> used_colors(k + 1, 0);
      for (auto neighbour : vertices_[i]) {
        if (colors[neighbour] != -1) {
          used_colors[colors[neighbour]] = 1;
        }
      }

      for (int j = 0; j < k + 1; j++) {
        if (used_colors[j] == 0) {
          colors[i] = j;
          break;
        }
      }
    }

    return colors;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int k = 0;
  int m = 0;
  std::cin >> n >> k >> m;
  Graph graph(n, m);
  auto result = graph.Chrom(k);
  for (auto &i : result) {
    std::cout << i + 1 << ' ';
  }
  return 0;
}
