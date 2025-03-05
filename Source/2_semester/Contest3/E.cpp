#include <stdexcept>
#include <string>
#include <unordered_map>

inline std::unordered_map<int, std::string> ReverseMap(const std::unordered_map<std::string, int> &map) {
  std::unordered_map<int, std::string> reverse;
  for (auto &kv : map) {
    reverse[kv.second] = kv.first;
  }

  return reverse;
}