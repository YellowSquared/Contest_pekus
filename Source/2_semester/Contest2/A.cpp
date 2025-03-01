#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct Team {
  int number;
  int solved;
  int penalty;
};

struct TeamComparator {
  bool operator()(const Team& a, const Team& b) {
    if (a.solved != b.solved) {
      return a.solved > b.solved;
    }
    if (a.penalty != b.penalty) {
      return a.penalty < b.penalty;
    }
    return a.number < b.number;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  std::vector<Team> teams(n);
  for (int i = 0; i < n; i++) {
    int s = 0;
    int t = 0;
    std::cin >> s >> t;
    teams[i] = {i + 1, s, t};
  }
  std::sort(teams.begin(), teams.end(), TeamComparator());
  for (const auto& team : teams) {
    std::cout << team.number << '\n';
  }
  return 0;
}
