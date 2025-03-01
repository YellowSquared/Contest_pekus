#include <iostream>
#include <unordered_map>

struct Client {
  int cash = 0;
  bool is_exist = false;
};

int main() {
  int requests = 0;
  int command = 0;
  std::string name;
  std::unordered_map<std::string, Client> db;
  std::cin >> requests;
  while (requests) {
    std::cin >> command >> name;
    if (command == 1) {
      std::cin >> command;
      db[name].cash += command;
      db[name].is_exist = true;
    } else {
      if (!db[name].is_exist) {
        std::cout << "ERROR\n";
      } else {
        std::cout << db[name].cash << '\n';
      }
    }
    --requests;
  }
  return 0;
}
