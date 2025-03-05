#include <iostream>
#include <vector>

enum Color { White, Grey, Black };

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<Color> colors_;

 public:
  Graph(int n, int m) {
    vertices_.resize(n);
    colors_.resize(n, White);
    for (int i = 0; i < m; i++) {
      int from = 0;
      int to = 0;
      std::cin >> from >> to;
      vertices_[--from].push_back(--to);
    }
  }

  bool TopSortDFS(int vertex, std::vector<int> &result) {
    colors_[vertex] = Grey;
    for (int i : vertices_[vertex]) {
      if (colors_[i] == Grey) {
        return false;
      }
      if (colors_[i] == White) {
        if (!TopSortDFS(i, result)) {
          return false;
        }
      }
    }
    result.push_back(vertex);
    colors_[vertex] = Black;
    return true;
  }

  void TopSort() {
    std::vector<int> result;
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (colors_[i] == White && !TopSortDFS(i, result)) {
        std::cout << -1;
        return;
      }
    }

    result = {result.rbegin(), result.rend()};
    for (int i : result) {
      std::cout << i + 1 << ' ';
    }
  }
};

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  Graph graph(n, m);
  graph.TopSort();
}
