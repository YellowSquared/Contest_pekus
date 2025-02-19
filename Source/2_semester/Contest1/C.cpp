// C. Хеш-таблица - открытая адресация

#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

template <int64_t X>
class Hash {
private:
  const int64_t p = 1e9 + 7;
  const int64_t x = X;

public:
  int64_t operator()(std::string key, uint64_t size) {
    size_t s = key.size();
    int64_t powx = 1;
    int64_t hash = 0;
    for (size_t i = 0; i < s; i++) {
      hash += key[i] * powx % p;
      hash %= p;
      powx = powx * x % p;
    }
    return hash % size;
  }
};

struct Node {
  std::string data;
  bool deleted = false;
  Node(std::string data_): data(data_){}
};


class HashTable {
private:
  Node** table;
  Hash<263> hash1;
  Hash<53> hash2;
  int64_t size;
  
  uint64_t GetHashIdx(std::string value, bool check_deleted) {
    size_t index, step;
    index = hash1(value, size);
    step = hash2(value, size);

    if (check_deleted) {
      while(table[index] != nullptr && table[index]->data != value && !table[index]->deleted) {
        index += step % size;
        index %= size;
      }
    } else {
      while(table[index] != nullptr && table[index]->data != value) {
        index += step % size;
        index %= size;
      }
    }
    return index;
  }

public:
  HashTable(int64_t size_) {
    table = new Node*[size_]{nullptr};
    size = size_;
  }

  ~HashTable() {
    for (int64_t i = 0; i < size; i++) {
      delete table[i];
    }
    delete[] table;
  }

  bool Search(const std::string& key) {
    return table[GetHashIdx(key, false)];
  }

  void Push(const std::string& key) {
    if (!Search(key)) {
      uint64_t idx = GetHashIdx(key, true);
      if (!table[idx]) {
        table[idx] = new Node(key);
      }
      if (table[idx]->deleted) {
        table[idx]->data = key;
        table[idx]->deleted = false;
      }
    }
  }

  bool Pop(const std::string& key) {
    int64_t idx = GetHashIdx(key, false);
    if (!table[idx]) {
      return false;
    }
    table[idx]->data = "";
    table[idx]->deleted = true;
    return true;
  }
};

int main() {
  int n = 0;
  std::cin >> n;
  HashTable hash_table(1e6);
  for (int i = 0; i < n; i++) {
    std::string input;
    std::string key;
    std::cin >> input >> key;
    if (input == "push") {
      hash_table.Push(key);
    } else if (input == "search") {
      if (hash_table.Search(key)) {
        std::cout << "TRUE\n";
      } else {
        std::cout << "FALSE\n";
      }
    } else {
      if(hash_table.Pop(key)) {
        std::cout << "TRUE\n";
      } else {
        std::cout << "FALSE\n";
      }
    }
  }
  return 0;
}
