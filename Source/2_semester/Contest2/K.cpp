#include <iostream>
#include <cstdint>

int main() {
  size_t requests = 0;
  size_t size = 0;
  std::cin >> size >> requests;

  size_t from = 0;
  size_t to = 0;
  size_t* answ = new size_t[size];
  while (requests) {
    std::cin >> from >> to;
    ++answ[from - 1];
    ++answ[to - 1];
    --requests;
  }
  for (size_t idx = 0; idx < size; ++idx) {
    std::cout << answ[idx] << ' ';
  }
  delete[] answ;
  return 0;
}
