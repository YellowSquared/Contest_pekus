#include <iostream>
#include <unordered_map>
#include <string>

struct Pair {
  int balance = 0;
  bool registred = false;
};

int main() {
  std::unordered_map<std::string, Pair> data;
  int n = 0;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int input_type = 0;
    std::string input_name;

    std::cin >> input_type >> input_name;

    if (input_type == 1) {
      int input_delta = 0;
      std::cin >> input_delta;

      data[input_name].balance += input_delta;
      data[input_name].registred = true;
    }

    if (input_type == 2) {
      if (data[input_name].registred) {
        std::cout << data[input_name].balance << "\n";
      } else {
        std::cout << "ERROR\n";
      }
    }
  }
}