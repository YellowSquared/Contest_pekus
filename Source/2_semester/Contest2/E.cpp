#include <unordered_map>
#include <iostream>
#include <string>

int main() {
  std::unordered_map<std::string, std::string> data;
  int n = 0;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::string word;
    std::string synonym;
    std::cin >> word >> synonym;

    data[word] = synonym;
    data[synonym] = word;
  }

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::string word;
    std::cin >> word;

    std::cout << data[word] << "\n";
  }
}