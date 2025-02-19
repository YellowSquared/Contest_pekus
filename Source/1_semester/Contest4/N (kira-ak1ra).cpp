#include <iostream>

void Encode(char* str, char* output_ptr) {
  int count_symb = 0;
  int result_ptr = 0;
  char numb[7] = {};
  int i = 1;
  int j = 0;
  while (str[i - 1]) {
    if (str[i] == str[i - 1]) {
      ++count_symb;
    } else {
      j = 0;
      output_ptr[result_ptr] = str[i - 1];
      if (!count_symb) {
        ++result_ptr;
        output_ptr[result_ptr] = '1';
      } else {
        ++count_symb;
        while (count_symb) {
          numb[j] = static_cast<char>(48 + (count_symb % 10));
          count_symb /= 10;
          ++j;
        }
        numb[j] = '\0';
        --j;
        for (; j >= 0; --j) {
          output_ptr[result_ptr + 1] = numb[j];
          ++result_ptr;
        }
      }
      result_ptr += 1;
      count_symb = 0;
    }
    ++i;
  }
  output_ptr[result_ptr] = '\0';
}

void Decode(char* str, char* output_str) {
  int i = 0;
  int j = 0;
  int numb = 0;
  char symb = ' ';
  while (str[i]) {
    if (static_cast<int>(str[i]) < 48 || static_cast<int>(str[i]) > 57) {
      if (numb) {
        for (; numb > 0; --numb) {
          output_str[j] = symb;
          ++j;
        }
      }
      symb = str[i];
    } else {
      numb *= 10;
      numb += static_cast<int>(str[i]) - 48;
    }
    ++i;
  }
  for (; numb > 0; --numb) {
    output_str[j] = symb;
    ++j;
  }
  output_str[j] = '\0';
}

int main() {
  char str[1000000 + 1] = {};
  char encoded_str[2000000 + 1] = {};
  std::cin >> str;
  Encode(str, encoded_str);
  std::cout << encoded_str << '\n';
  Decode(encoded_str, str);
  std::cout << str;
  return 0;
}
