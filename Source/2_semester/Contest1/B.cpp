#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

class Hash {
private:
  const int64_t p = 1e9 + 7;
  const int64_t x = 263;

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
  Node *next;
  Node *prev;
  Node(std::string data_, Node *next_ = nullptr, Node *prev_ = nullptr)
      : data(data_), next(next_), prev(prev_) {}
};

class List {
private:
  uint64_t size = 0;
  Node *head = nullptr;
  Node *tail = nullptr;

public:
  ~List() {
    for (Node *node = head; node != nullptr;) {
      Node *prev_node = node;
      node = node->next;
      delete prev_node;
    }
  }

  void Add(const std::string &key) {
    if (!head) {
      head = new Node(key);
      tail = head;
    } else {
      head->prev = new Node(key);
      head->prev->next = head;
      head = head->prev;
    }
    size++;
  }

  Node *Find(const std::string &key) {
    for (Node *node = head; node != nullptr; node = node->next) {
      if (node->data == key) {
        return node;
      }
    }
    return nullptr;
  }

  void Remove(const std::string &key) {
    Node *node = Find(key);
    if (!node) {
      return;
    }

    if (node->next && node->prev) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    } else if (node->prev) {
      tail->prev->next = nullptr;
      tail = tail->prev;
    } else if (node->next) {
      head->next->prev = nullptr;
      head = head->next;
    } else {
      head = nullptr;
      tail = nullptr;
    }
    delete node;
    size--;
  }

  void Print() {
    for (Node *node = head; node != nullptr; node = node->next) {
      std::cout << node->data << (node != tail ? " " : "");
    }
    std::cout << '\n';
  }
};

class HashTable {
private:
  List *table;
  Hash hash;
  uint64_t size;

public:
  HashTable(size_t size_) {
    table = new List[size_];
    size = size_;
  }
  ~HashTable() { delete[] table; }

  bool Find(const std::string &key) { return table[hash(key, size)].Find(key); }

  void Add(const std::string &key) {
    bool result = table[hash(key, size)].Find(key);
    if (!result) {
      table[hash(key, size)].Add(key);
    }
  }

  void Del(const std::string &key) { table[hash(key, size)].Remove(key); }

  void Check(size_t n) { table[n].Print(); }
};

int main() {
  int m = 0;
  int n = 0;
  std::cin >> m >> n;
  HashTable hash_table(m);
  for (int i = 0; i < n; i++) {
    std::string input;
    std::cin >> input;
    if (input == "check") {
      int idx = 0;
      std::cin >> idx;
      hash_table.Check(idx);
    } else {
      std::string key;
      std::cin >> key;
      if (input == "find") {
        if (hash_table.Find(key)) {
          std::cout << "yes\n";
        } else {
          std::cout << "no\n";
        }
      } else if (input == "add") {
        hash_table.Add(key);
      } else {
        hash_table.Del(key);
      }
    }
  }
  return 0;
}
