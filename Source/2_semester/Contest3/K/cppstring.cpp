#include "cppstring.h"

template <class T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

String::String() {
  size_ = 0;
  capacity_ = 0;
  data_ = nullptr;
}

String::String(size_t size, char symbol) {
  size_ = size;
  capacity_ = size;
  if (size == 0) {
    data_ = nullptr;
    return;
  }
  data_ = new char[size];
  for (int i = 0; i < size; i++) {
    data_[i] = symbol;
  }
}

String::String(const char* str) { //NOLINT
  size_t i = 0;
  for (i; str[i]; i++);
  
  size_ = i;
  capacity_ = i;
  data_ = new char[i];

  for (size_t i = 0; str[i]; i++) {
    data_[i] = str[i];
  }
}

String::String(const char* str, size_t size) {
  size_ = size;
  capacity_ = size;
  data_ = new char[size];
  for (size_t i = 0; str[i]; i++) {
    data_[i] = str[i];
  }
}

String::String(const String& other) {
  size_ = other.size_;
  capacity_ = other.capacity_;
  if (size_ == 0) {
    data_ = nullptr;
    return;
  }
  data_ = new char[capacity_];
  for (size_t i = 0; i < size_; i++) {
    data_[i] = other.data_[i];
  }
}

String::String(String&& other) {
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = other.data_;

  other.data_ = nullptr;
}

String::~String() {
  if (data_ != nullptr) {
    delete[] data_;
  }
}

String& String::operator=(const String& other) {
  if (*this != other) {
    size_ = other.size_;
    capacity_ = other.capacity_;

    if (size_ == 0) {
      delete[] data_;
      data_ = nullptr;
      return *this;
    }
    delete[] data_;

    data_ = new char[capacity_];

    for (size_t i = 0; i < size_; i++) {
      data_[i] = other.data_[i];
    }
  }
  return *this;
}

String& String::operator=(String&& other) {
  if (*this != other) {
    delete[] data_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;

    other.data_ = nullptr;
  }
  return *this;
}

const char& String::operator[](size_t index) const {
  return data_[index];
}

char& String::operator[](size_t index) {
  return data_[index];
}

const char& String::At(size_t index) const {
  if (index >= size_) {
    throw StringOutOfRange();
  }
  return data_[index];
}

char& String::At(size_t index) {
  if (index >= size_) {
    throw StringOutOfRange();
  }
  return data_[index];
}

const char& String::Front() const {
  return data_[0];
}

char& String::Front() {
  return data_[0];
}

const char& String::Back() const {
  return data_[size_ - 1];
}

char& String::Back() {
  return data_[size_ - 1];
}

const char* String::CStr() const {
  return data_;
}

const char* String::Data() const {
  return data_;
}

char* String::CStr() {
  return data_;
}

char* String::Data() {
  return data_;
}

bool String::Empty() const {
  return size_ == 0;
}

size_t String::Size() const {
  return size_;
}

size_t String::Length() const {
  return size_;
}

size_t String::Capacity() const {
  return capacity_;
}

void String::Clear() {
  size_ = 0;
}

void String::Swap(String& other) {
  swap(size_, other.size_);
  swap(capacity_, other.capacity_);
  swap(data_, other.data_);
}

void String::PopBack() {
  data_[size_ - 1] = 0;
  data_[size_ - 2] = '\0';
}

void String::PushBack(char symbol) {
  size_t tempSize = size_;
  if (tempSize >= capacity_) {
    Resize((size_ * 2) + 1, 0);
  }
  data_[size_] = symbol;
  size_++;
}

String& operator+=(String& lhs, const String& rhs) {
  size_t needed = lhs.size_ + rhs.size_;
  while (lhs.capacity_ < needed) {
    lhs.Resize((lhs.capacity_ + 1 * 2), 0);
  }
  for (size_t i = 0; i < rhs.size_; i++) {
    lhs.PushBack(rhs.data_[i]);
  }
  return lhs;
}

void String::Resize(size_t new_size, char symbol) {
  size_t old_size = size_;

  Reserve(new_size);

  for (size_t i = old_size; i < size_; i++) {
    data_[i] = symbol;
  }
  size_ = new_size;
}

void String::Reserve(size_t new_capacity) {
  if (new_capacity > capacity_) {
    char* new_data = new char[new_capacity];
    for (size_t i = 0; i < size_; i++) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }
}

void String::ShrinkToFit() {
  char* new_data = new char[size_];
  for (size_t i = 0; data_[i]; i++) {
    new_data[i] = data_[i];
  }
  delete[] data_;
  data_ = new_data;
  capacity_ = size_;
}

String operator+(const String& lhs, const String& rhs) {
  String result(lhs);
  result += rhs;
  return result;
}

bool operator<(const String& lhs, const String& rhs) {
  for (size_t i = 0; i < lhs.size_ && i < rhs.size_; i++) {
    if (lhs.data_[i] < rhs.data_[i]) {
      return true;
    }
    if (lhs.data_[i] > rhs.data_[i]) {
      return false;
    }
  }
  return lhs.size_ < rhs.size_;
}

bool operator>(const String& lhs, const String& rhs) {
  return rhs < lhs;
}

bool operator<=(const String& lhs, const String& rhs) {
  return !(lhs > rhs);
}

bool operator>=(const String& lhs, const String& rhs) {
  return !(lhs < rhs);
}

bool operator==(const String& lhs, const String& rhs) {
  if (lhs.size_ != rhs.size_) {
    return false;
  }
  for (size_t i = 0; i < lhs.size_; i++) {
    if (lhs.data_[i] != rhs.data_[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(const String& lhs, const String& rhs) {
  return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const String& str) {
  for (size_t i = 0; i < str.size_; i++) {
    os << str.data_[i];
  }
  return os;
}

std::istream& operator>>(std::istream& is, String& str) {
  char symbol;
  while (is >> symbol) {
    str.PushBack(symbol);
  }
  return is;
}

