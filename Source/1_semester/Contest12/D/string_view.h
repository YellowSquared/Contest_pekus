#ifndef STRING_VIEW_H
#define STRING_VIEW_H

#include <stdexcept>
#include <cstddef>

class StringViewOutOfRange : public std::out_of_range {
 public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};

class StringView {
public:
  StringView();
  StringView(const char* str); // NOLINT
  StringView(const char* str, size_t size);

  char operator[](size_t idx);
  char operator[](size_t idx) const;

  char At(size_t idx) const;
  
  char Front() const;
  char Back() const;

  size_t Size() const;
  size_t Length() const;

  bool Empty() const;
  const char* Data() const;

  void Swap(StringView& s);

  void RemovePrefix(size_t prefix_size);
  void RemoveSuffix(size_t suffix_size);

  StringView Substr(size_t pos, size_t count);

private:
  size_t size_ = 0;
  const char* str_ = nullptr;
};

#endif