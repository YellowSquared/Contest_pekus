#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<Colors> color_;
  std::vector<int> parents_;

 public:
  Graph(int n, int m) {
    vertices_.resize(n);
    color_.resize(n, White);
    parents_.resize(n, -1);
    for (int i = 0; i < m; i++) {
      int v1 = 0;
      int v2 = 0;
      std::cin >> v1 >> v2;
      vertices_[--v1].push_back(--v2);
    }
  }

  bool DFS(int index, int &start, int &end) {
    color_[index] = Grey;
    for (auto &i : vertices_[index]) {
      if (color_[i] == Grey) {
        start = i;
        end = index;
        return true;
      }

      if (color_[i] == White) {
        parents_[i] = index;
        if (DFS(i, start, end)) {
          return true;
        }
      }
    }
    color_[index] = Black;
    return false;
  }

  void DFSAll() {
    int start = -1;
    int end = 0;
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (color_[i] == White && DFS(i, start, end)) {
        break;
      }
    }

    std::vector<int> cycle;

    if (start == -1) {
      std::cout << "NO";
    } else {
      for (int v = end; v != start; v = parents_[v]) {
        cycle.push_back(v);
      }
      cycle.push_back(start);
      std::cout << "YES\n";
      for (int i = static_cast<int>(cycle.size() - 1); i >= 0; i--) {
        std::cout << cycle[i] + 1 << ' ';
      }
    }
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
  graph.DFSAll();
  return 0;
}