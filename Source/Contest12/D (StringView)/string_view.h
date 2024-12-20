/*    ____        __      __   ____________  __       __    __      __    ________     __
     /    \       \  \   /  /  |____  ____|  \  \    /  /  |  |    |  |  |   ____ |   |  |
    /  /\  \       \   \/  /       |  |       \  \  /  /   |  |____|  |  |  |         |  |
   /  /__\  \       \     /        |  |        \  \/  /    |   ____   |  |  |         |  |
  /  _____   \      /  /\  \       |  |         \    /     |  |    |  |  |  |         |__|
 /  /      \  \    /  /   \  \     |  |          |  /      |  |    |  |  |  |          __
/__/        \__\  /__/     \__\    |__|         /__/       |__|    |__|  |__|         |__|

ЗА РЕШЕНИЕ НЕ ВЫСТАВЛЕН ОКОНЧАТЕЛЬНЫЙ БАЛЛ!!!
Т.е., его приняла система, но не проверил ассистент
*/

//
// Created by altea-pc on 12/14/24.
//

#ifndef STRING_VIEW_H
#define STRING_VIEW_H

#include <cstring>
#include <stdexcept>

class StringViewOutOfRange : public std::out_of_range {
public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};

class StringView {
private:
  const char* str_;
  size_t length_ = 0;
public:
  StringView() {
    str_ = nullptr;
    length_ = 0;
  }
  StringView(const char* str) {  // NOLINT
    size_t len = 0;
    while (str[len] != '\0') {
      len++;
    }
    str_ = str;
    length_ = len;
  }
  StringView(const char* str, size_t len) {
    length_ = len;
    str_ = str;
  }

  char operator[](size_t i) const {
    return str_[i];
  }

  char At(size_t idx) const;
  char Front() const;
  char Back() const;
  const char* Data() const;

  StringView Swap(StringView& smth_str);
  size_t Length() const;
  size_t Size() const;
  bool Empty() const;

  void RemovePrefix(size_t prefix_size);
  void RemoveSuffix(size_t suffix_size);
  StringView Substr(size_t pos, int count = -1) const;
};

#endif //STRING_VIEW_H
