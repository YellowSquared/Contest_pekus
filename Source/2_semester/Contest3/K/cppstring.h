#ifndef CPPSTRING_H
#define CPPSTRING_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

class StringOutOfRange : public std::out_of_range {
  public:
   StringOutOfRange() : std::out_of_range("StringOutOfRange") {
   }
};

class String {
  private:
  size_t size_;
  size_t capacity_;
  char* data_;

  public:
  String();

  String(size_t size, char symbol);

  String(const char* str); //NOLINT

  explicit String(const char* str, size_t size);

  String(const String& other);

  String(String&& other);

  ~String();

  String& operator=(const String& other);

  String& operator=(String&& other);

  const char& operator[](size_t index) const;
  char& operator[](size_t index);

  const char& At(size_t index) const;
  char& At(size_t index);

  const char& Front() const;
  char& Front();

  const char& Back() const;
  char& Back();

  const char* CStr() const;
  const char* Data() const;

  char* CStr();
  char* Data();

  bool Empty() const;

  size_t Size() const;
  size_t Length() const;

  size_t Capacity() const;

  void Clear();

  void Swap(String& other);
  
  void PopBack();
  void PushBack(char symbol);

  friend String& operator+=(String& lhs, const String& rhs);

  void Resize(size_t new_size, char symbol);

  void Reserve(size_t new_capacity);

  void ShrinkToFit();

  friend String operator+(const String& lhs, const String& rhs);

  friend bool operator<(const String& lhs, const String& rhs);
  friend bool operator>(const String& lhs, const String& rhs);
  friend bool operator<=(const String& lhs, const String& rhs);
  friend bool operator>=(const String& lhs, const String& rhs);
  friend bool operator==(const String& lhs, const String& rhs);
  friend bool operator!=(const String& lhs, const String& rhs);

  friend std::ostream& operator<<(std::ostream& os, const String& str);
  friend std::istream& operator>>(std::istream& is, String& str);

};

#endif