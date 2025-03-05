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
      int v1 = 0;
      int v2 = 0;
      std::cin >> v1 >> v2;
      --v1;
      --v2;
      vertices_[v1].push_back(v2);
      vertices_[v2].push_back(v1);
    }
  }

  void DFS(int index, std::vector<int>& component) {
    colors_[index] = Grey;
    component.push_back(index);

    for (auto& i : vertices_[index]) {
      if (colors_[i] == White) {
        DFS(i, component);
      }
    }
    colors_[index] = Black;
  }

  std::vector<std::vector<int>> ComponentCount() {
    std::vector<std::vector<int>> components;
    int count = 0;
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (colors_[i] == White) {
        std::vector<int> new_component;
        components.emplace_back(new_component);
        DFS(i, components[count]);
        count++;
      }
    }
    return components;
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
  std::vector<std::vector<int>> result = graph.ComponentCount();
  std::cout << result.size() << '\n';
  for (auto& component : result) {
    std::cout << component.size() << '\n';
    for (auto& vertex : component) {
      std::cout << vertex + 1 << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}