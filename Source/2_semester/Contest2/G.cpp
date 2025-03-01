#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <map>

int main() {
  std::map<std::string, int> data{};
  std::string line;

  while (std::getline(std::cin, line) && !line.empty()) {
    std::stringstream s(line);

    std::string word;
    while (s >> word) {
      data[word]++;
    }
  }

  std::set<std::pair<int, std::string>> sortedSet;

  for (auto &d : data) {
    sortedSet.emplace(std::pair<int, std::string>(d.second, d.first));
  }

  for (auto &val : sortedSet) {
    std::cout << val.second << "\n";
  }
}