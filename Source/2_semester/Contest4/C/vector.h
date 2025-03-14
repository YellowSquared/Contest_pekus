#ifndef VECTOR_H
#define VECTOR_H

#include <type_traits>
#include <iterator>
#include <algorithm>

template <typename T>

class Vector {
private:
  T* arr;
  size_t capacity_;
  size_t size_;
  
public:
  template <class Iterator, class = std::enable_if_t<std::is_base_of_v<std::forward_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>>>
  Vector(Iterator first, Iterator last);
  Vector(std::initializer_list init);

  Vector(Vector& other);
  Vector(Vector&& other);

  ~Vector();

  Vector& operator=(const Vector other);
  Vector& operator=(Vector&& other);

  size_t Size();
  size_t Capacity();
  size_t Empty();

  T& operator[] (size_t idx) {
    return arr[idx];
  }

  const T& operator[] (size_t idx) const {
    return arr[idx];
  }

  T& At(size_t idx) const {
    if (idx >= N) {
      throw std::out_of_range;
    }
    return arr[idx];
  }

  T& Front();
  T& Front() const;
  
  T& Back();
  T& Back() const;

  T* Data();

  void Swap(Vector other);

  void Resize(size_t new_size);
  void Reserve(size_t new_cap);
  void ShrinkToFit(size_t new_size);

  void Clear();

  void PushBack(const T&);
  void PushBack(T&&);

  void PopBack();


  
};


#endif  // VECTOR_H