#include "lru_cache.h"
#include <iostream>
#include <string>

int main() {
  LruCache lru_cache(3);
  lru_cache.Set("Test1", "1");
  lru_cache.Set("Test2", "2");
  lru_cache.Set("Test3", "3");

  std::string res;

  res = "NOT FOUND";
  lru_cache.Set("Test4", "4");
  lru_cache.Get("Test3", &res);
  std::cout << res << "\n";
}