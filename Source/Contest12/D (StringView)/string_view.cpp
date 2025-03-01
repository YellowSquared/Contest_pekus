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

#include <iostream>
#include "string_view.h"

#include <algorithm>
#include <bits/ranges_algo.h>

template <typename T>
void SwapValues(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

char StringView::At(size_t idx) const {
  if (idx < length_) {
    return str_[idx];
  }
  throw StringViewOutOfRange();
}
char StringView::Front() const {
  return str_[0];
}
char StringView::Back() const {
  if (length_) {
    return str_[length_ - 1];
  }
  return str_[0];
}
const char* StringView::Data() const {
  return str_;
}

StringView StringView::Swap(StringView& smth_str) {
  SwapValues(smth_str, *this);
  return *this;
}
size_t StringView::Length() const {
  return length_;
}
size_t StringView::Size() const {
  return length_;
}
bool StringView::Empty() const {
  return length_ == 0;
}

void StringView::RemovePrefix(size_t prefix_size) {
  if (length_ >= prefix_size) {
    length_ -= prefix_size;
    str_ = str_ + prefix_size;
  } else {
    throw StringViewOutOfRange();
  }
}
void StringView::RemoveSuffix(size_t suffix_size) {
  if (length_ >= suffix_size) {
    length_ -= suffix_size;
  } else {
    throw StringViewOutOfRange();
  }
}
StringView StringView::Substr(size_t pos, int count) const {
  if (pos == 0 && (count == -1 || static_cast<size_t>(count) == length_)) {
    return *this;
  }
  if (pos < length_ && pos + count <= length_) {
    if (count != -1) {
      StringView answ{this->str_ + pos, static_cast<size_t>(count)};
      return answ;
    }
    StringView answ{this->str_ + pos, this->Size() - pos};
    return answ;
  }
  throw StringViewOutOfRange();
}
