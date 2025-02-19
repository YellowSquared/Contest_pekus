#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};

template<typename T, std::size_t N>

class Array {
  public:
    T arr[N];

    Array() = default;

    Array(std::initializer_list<T> args) {
      size_t i = 0;
      for (auto element: args) {
        arr[i] = element;
        i++;
      }
      while (i < N) {
        arr[i] = T();
        i++;
      }
    }

    T& operator[] (size_t idx) {
      return arr[idx];
    }

    const T& operator[] (size_t idx) const {
      return arr[idx];
    }

    T& At(size_t idx) const {
      if (idx >= N) {
        throw ArrayOutOfRange{};
      }
      return arr[idx];
    }

    T& Front() {
      return arr[0];
    }

    const T& Front() const {
      return arr[0];
    }

    T& Back() {
      if (N == 0) {
        return arr[0];
      }
      return arr[N - 1];
    }

    const T& Back() const {
      if (N == 0) {
        return arr[0];
      }
      return arr[N - 1];
    }

    T* Data() {
      return arr;
    }

    const T* Data() const {
      return arr;
    }

    size_t Size() const {
      return N;
    }

    bool Empty() const {
      return N == 0;
    }

    void Fill(const T& value) {
      for (size_t i = 0; i < N; i++) {
        arr[i] = value;
      }
    }

    void Swap(Array<T, N>& other) {
      if (other.Size() != N) {
        throw ArrayOutOfRange();
      }

      T temp;
      for (size_t i = 0; i < N; i++) {
        temp = arr[i];
        arr[i] = other[i];
        other[i] = temp;
      }
    }
    

};



#endif  // ARRAY_H