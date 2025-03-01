#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <list>

int main() {
  std::map<std::string, std::map<std::string, int>> data;
  std::vector<std::string> input;
  std::string line = "temp";

  while (std::getline(std::cin, line) && !line.empty()) {
    std::stringstream s(line);

    std::string name;
    std::string item;
    int amount = 0;

    while (s >> name >> item >> amount) {
      data[name][item] += amount;
    }
  }

  for (auto it = data.begin(); it != data.end(); it++) {
    std::cout << it->first << ":"
              << "\n";
    for (auto sec = it->second.begin(); sec != it->second.end(); sec++) {
      std::cout << sec->first << " " << sec->second << "\n";
    }
  }
}