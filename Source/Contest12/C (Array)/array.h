/*    ____        __      __   ____________  __       __    __      __    ________     __
     /    \       \  \   /  /  |____  ____|  \  \    /  /  |  |    |  |  |   ____ |   |  |
    /  /\  \       \   \/  /       |  |       \  \  /  /   |  |____|  |  |  |         |  |
   /  /__\  \       \     /        |  |        \  \/  /    |   ____   |  |  |         |  |
  /  _____   \      /  /\  \       |  |         \    /     |  |    |  |  |  |         |__|
 /  /      \  \    /  /   \  \     |  |          |  /      |  |    |  |  |  |          __
/__/        \__\  /__/     \__\    |__|         /__/       |__|    |__|  |__|         |__|

Тут нет доп. части
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
#include <cstdarg>
#include <cassert>

class ArrayOutOfRange : public std::out_of_range {
public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};

template <typename T, size_t Length>
class Array {
private:
  T arr_[Length];
public:
  Array() = default;
  Array (std::initializer_list<T> list) {
    size_t j = 0;
    for (auto i = list.begin(); i != list.end() && j < Length; ++i) {
      arr_[j] = *i;
      ++j;
    }
    while (j < Length) {
      arr_[j] = static_cast<T>(0);
      ++j;
    }
  }

  const T* Data() const  {
    return arr_;
  }
  T* Data() {
    return arr_;
  }
  const T& At(size_t idx) const {
    if (idx >= Length) {
      throw ArrayOutOfRange();
    }
    return arr_[idx];
  }
  T& At(size_t idx) {
    if (idx >= Length) {
      throw ArrayOutOfRange();
    }
    return arr_[idx];
  }
  const T& Front() const {
    return arr_[0];
  }
  T& Front() {
    return arr_[0];
  }
  const T& Back() const {
    if (Length != 0) {
      return arr_[Length - 1];
    }
    return arr_[0];
  }
  T& Back() {
    if (Length != 0) {
      return arr_[Length - 1];
    }
    return arr_[0];
  }

  static size_t Size() {
    return Length;
  }
  void Fill(const T& value) {
    for (size_t i = 0; i < Length; i++) {
      arr_[i] = value;
    }
  }
  T Change(T value, size_t position) {
    if (position >= Length) {
      throw ArrayOutOfRange();
    }
    T for_return = arr_[position];
    arr_[position] = value;
    return for_return;
  }
  void Swap(Array<T, Length>& other_arr) {
    for (size_t i = 0; i < Length; i++) {
      arr_[i] = other_arr.Change(arr_[i], i);
    }
  }
  static bool Empty() {
    return Length == 0;
  }

  T& operator[] (size_t i) {
    return arr_[i];
  }
  const T& operator[](size_t i) const {
    return arr_[i];
  }

  friend std::ostream& operator<<(std::ostream& os, Array<T, Length> smth_arr) {
    if (Length) {
      for (size_t i = 0; i < Length - 1; ++i) {
        os << smth_arr[i] << ' ';
      }
      os << smth_arr[Length - 1];
    }
    return os;
  }
};

#endif //ARRAY_H
