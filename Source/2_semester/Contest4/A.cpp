#include <iostream>
#include <vector>

enum Color { White, Grey, Black };

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<Color> colors_;
  std::vector<int> top_sorted_;
  std::vector<int> component_;

 public:
  Graph(int n, int m) {
    vertices_.resize(n);
    colors_.resize(n, White);
    component_.resize(n);
    for (int i = 0; i < m; i++) {
      int v1 = 0;
      int v2 = 0;
      std::cin >> v1 >> v2;
      vertices_[--v1].push_back(--v2);
    }
  }

  void Reverse() {
    std::vector<std::vector<int>> copy;
    copy.resize(vertices_.size());
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      for (int j : vertices_[i]) {
        copy[j].push_back(i);
      }
    }
    vertices_ = std::move(copy);
  }

  void TopSortDFS(int vertex) {
    colors_[vertex] = Grey;
    for (int i : vertices_[vertex]) {
      if (colors_[i] == White) {
        TopSortDFS(i);
      }
    }
    top_sorted_.push_back(vertex);
    colors_[vertex] = Black;
  }

  void TopSort() {
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (colors_[i] == White) {
        TopSortDFS(i);
      }
    }
    std::vector<Color> clean_colors(vertices_.size(), White);
    colors_ = std::move(clean_colors);
  }

  void DFS(int vertex, int k) {
    colors_[vertex] = Grey;
    component_[vertex] = k;
    for (int i : vertices_[vertex]) {
      if (colors_[i] == White) {
        DFS(i, k);
      }
    }
    colors_[vertex] = Black;
  }

  void FindComponents() {
    TopSort();
    Reverse();
    int k = 1;
    for (int i = static_cast<int>(top_sorted_.size() - 1); i >= 0; i--) {
      if (colors_[top_sorted_[i]] == White) {
        DFS(top_sorted_[i], k++);
      }
    }
    std::cout << k - 1 << '\n';
    for (int i : component_) {
      std::cout << i << ' ';
    }
  }
};

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  Graph graph(n, m);
  graph.FindComponents();
}
