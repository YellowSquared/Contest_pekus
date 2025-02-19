#include <iostream>

int StrSize(char str[]) {
  int answ = 1;
  while (str[answ] != 0) {
    ++answ;
  }
  return answ;
}

bool IsAnagram(char str_1[], char str_2[]) {
  if (StrSize(str_1) != StrSize(str_2)) {
    return false;
  }
  bool answ = true;
  int symb_count_1[26] = {};
  int symb_count_2[26] = {};
  for (int i = StrSize(str_1) - 1; i >= 0; --i) {
    ++symb_count_1[str_1[i] - 97];
    ++symb_count_2[str_2[i] - 97];
  }
  for (int i = 0; i < 26; ++i) {
    if (symb_count_1[i] != symb_count_2[i]) {
      answ = false;
      break;
    }
  }
  return answ;
}

int main() {
  char a[1000000] = {};
  char b[1000000] = {};
  std::cin >> a >> b;
  if (IsAnagram(a, b)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}
