#include <iostream>

// А-а-а, крокодил в ванной!

bool IsRealTransformation(char a[], char b[]) {
  int i = 0;
  int j = 0;
  while (a[i] != '\0' && b[j] != '\0') {
    if (a[i] == b[j]) {
      ++j;
    }
    ++i;
  }
  return (a[i] != '\0' || b[j] == '\0');
}

int main() {
  int position = 0;
  int answ = 0;
  char data[200000 + 1];
  char result[200000 + 1];
  std::cin >> data;
  std::cin >> result;
  std::cin >> position;
  data[position - 1] = ' ';
  while (IsRealTransformation(data, result)) {
    ++answ;
    std::cin >> position;
    data[position - 1] = ' ';
  }
  std::cout << answ;
  return 0;
}
