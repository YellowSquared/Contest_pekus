#include <stdexcept>
#include <vector>

inline std::vector<int> Range(int from, int to, int step = 1) {
  std::vector<int> v;
  for (int i = from; (i < to && step > 0) || (i > to && step < 0); i += step) {
    v.push_back(i);
  }
  return v;
}
