#include <iostream>
#include <algorithm>
#include <vector>

struct Result {
  unsigned int index;
  int solved_tasks;
  int penalty_time;
};

bool TeamResultComparison(Result& a, Result& b) {
  if (a.solved_tasks != b.solved_tasks) {
    return a.solved_tasks > b.solved_tasks;
  }
  if (a.penalty_time != b.penalty_time) {
    return a.penalty_time < b.penalty_time;
  }
  return a.index < b.index;
}

int main() {
  unsigned int n = 0;
  std::cin >> n;
  std::vector<Result> results(n);
  for (unsigned int i = 0; i < n; ++i) {
    std::cin >> results[i].solved_tasks;
    std::cin >> results[i].penalty_time;
    results[i].index = i;
  }
  std::sort(results.begin(), results.end(), TeamResultComparison);
  for (Result a : results) {
    std::cout << a.index + 1 << '\n';
  }
  return 0;
}
