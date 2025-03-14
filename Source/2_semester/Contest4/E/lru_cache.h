#ifndef LRU_CACHE_H
#define LRU_CACHE_H


#include <list>
#include <string>
#include <unordered_map>

class LruCache {
 private:
 std::unordered_map<std::string, std::string> data;
 std::list<std::string> accessed;
 size_t size;

 public:
  explicit LruCache(size_t max_size) {
    size = max_size;
  }
  LruCache(const LruCache&) = delete;
  LruCache& operator=(const LruCache&) = delete;

  void Set(const std::string& key, const std::string& value) {
    data[key] = value;
    
    if (data.size() > size) {
      data.erase(accessed.front());
      accessed.pop_front();
    }
    accessed.push_front(key);
  }

  bool Get(const std::string& key, std::string* value) {
    if (!data[key].empty()) {
      *value = data[key];
      accessed.push_front(key);
      return true;
    }
    return false;
  }
};

#endif