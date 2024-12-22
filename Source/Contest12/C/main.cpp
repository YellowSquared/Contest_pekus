#include <array>
#include <iostream>
#include "array.h"
#include <assert.h>

int main() {
  static_assert(sizeof(Array<int, 1>) == sizeof(int));
  static_assert(sizeof(Array<int, 17>) == sizeof(int) * 17);
  static_assert(sizeof(Array<double, 13>) == sizeof(double) * 13);

  const Array<int, 7> array{};
  size_t sev = 7;
  std::cout << (array.Size() == sev) << "\n";
  std::cout << (!array.Empty()) << "\n";

  // Array<int, 4> a{};
  // a.Fill(-11);
  // std::cout << a[0] << a[1] << a[3];
  
  // Array<int, 3> a{1, 2, 3};
  // Array<int, 3> b{-1, -2, -3};
  // a.Swap(b);

  // std::cout << b[0];

  struct S {
    int i;
    char c;
  };

  Array<S, 3> arr{{{1, 'a'}, {2, 'b'}}};
  std::cout << (arr[0].i == 1) << "\n";
  std::cout << (arr[0].c == 'a') << "\n";
  std::cout << (arr[1].i == 2) << "\n";
  std::cout << (arr[1].c == 'b') << "\n";
  std::cout << (arr[2].i == 0) << "\n";
  std::cout << (arr[2].c == '\0') << "\n";


}