#include "string_view.h"
#include <iostream>

StringView::StringView() {
  str_ = nullptr;
  size_ = 0;
}

StringView::StringView(const char* str) {
  int iter = 0;

  while (str[iter] != '\0') {
    iter++;
  }

  size_ = iter;
  str_ = str;
}

StringView::StringView(const char* str, size_t size) {
  str_ = str;
  size_ = size;
}

char StringView::operator[](size_t idx) {
  return str_[idx];
}

char StringView::operator[](size_t idx) const {
  return str_[idx];
}

char StringView::At(size_t idx) const {
  if (idx >= size_) {
    throw StringViewOutOfRange{};
  }
  return str_[idx];
}
  
char StringView::Front() const {
  return str_[0];
}
char StringView::Back() const {
  return str_[size_ - 1];
}

size_t StringView::Size() const {
  return size_;
}
size_t StringView::Length() const {
  return size_;
}

bool StringView::Empty() const {
  return size_ == 0;
}
const char* StringView::Data() const {
  return str_;
}

void StringView::Swap(StringView& s) {
  StringView& tmp = s;
  s = *this;
  *this = tmp;
}

void StringView::RemovePrefix(size_t prefix_size) {
  str_ = str_ + prefix_size;
  size_ -= prefix_size;
}
void StringView::RemoveSuffix(size_t suffix_size) {
  size_ -= suffix_size;
}

StringView StringView::Substr(size_t pos, size_t count) {
  if (pos >= size_) {
    throw StringViewOutOfRange{};
  }

  size_t len = std::min(count, size_ - pos);
  const char* s = str_ + pos;
  return {s, len};
}
