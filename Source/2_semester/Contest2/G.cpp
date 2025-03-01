#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <map>

int main() {
  std::map<std::string, int> data = {};
  std::map<int, std::set<std::string>> reversed = {};

  std::string line;

  while (std::getline(std::cin, line) && !line.empty()) {
    std::stringstream input(line);

    std::string word;
    while (input >> word) {
      data[word]++;
    }
  }

  for (auto it = data.begin(); it != data.end(); it++) {
    reversed[it->second].insert(it->first);
  }

  for (auto it = reversed.rbegin(); it != reversed.rend(); it++) {
    for (auto sub : it->second) {
      std::cout << sub << "\n";
    }
  }
}