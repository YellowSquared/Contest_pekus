#include <iostream>
#include <vector>

enum Color { White, Grey, Black };

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<Color> colors_;

 public:
  explicit Graph(int n) {
    vertices_.resize(n);
    colors_.resize(n, White);
    for (int i = 0; i < n; i++) {
      int v1 = 0;
      std::cin >> v1;
      --v1;
      vertices_[v1].push_back(i);
    }
  }

  void DFS(int index, int& count) {
    colors_[index] = Grey;

    for (auto& i : vertices_[index]) {
      if (colors_[i] == White) {
        DFS(i, count);
      } else if (colors_[i] == Black) {
        count--;
      }
    }
    colors_[index] = Black;
  }

  int ComponentCount() {
    int count = 0;
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (colors_[i] == White) {
        DFS(i, count);
        count++;
      }
    }
    return count;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  Graph graph(n);
  std::cout << graph.ComponentCount();
  return 0;
}