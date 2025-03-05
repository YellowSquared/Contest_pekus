#include <iostream>
#include <vector>

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<int> color_;

 public:
  Graph(int n, int m) {
    vertices_.resize(n);
    color_.resize(n, 0);
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

  bool BipartiteDFS(int index, int color) {
    color_[index] = color;
    for (auto &i : vertices_[index]) {
      if (color_[i] == 0 && !BipartiteDFS(i, -color)) {
        return false;
      }
      if (color_[i] == color) {
        return false;
      }
    }
    return true;
  }

  bool Bipartite() {
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (color_[i] == 0 && !BipartiteDFS(i, 1)) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  Graph graph(n, m);
  std::cout << (graph.Bipartite() ? "YES" : "NO");
  return 0;
}