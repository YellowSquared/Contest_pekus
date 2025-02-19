#include <cmath>
#include <cstdint>
#include <iostream>
#include <cstring>

class Hash {
  private:
    const int64_t p = 1e9 + 7;
    const int64_t x = 263;
  
  public:
    int64_t operator()(int key) {
      return key;
  };

};

struct Node {
  int data;
  std::string name;
  Node *next;
  Node *prev;
  Node(int data_, std::string name_ = nullptr, Node *next_ = nullptr, Node *prev_ = nullptr)
      : data(data_), next(next_), prev(prev_), name(name_) {}
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
  
    void Add(const int &key, const std::string &name) {
      if (!head) {
        head = new Node(key, name);
        tail = head;
      } else {
        head->prev = new Node(key, name);
        head->prev->next = head;
        head = head->prev;
      }
      size++;
    }
  
    Node *Find(const int &key) {
      for (Node *node = head; node != nullptr; node = node->next) {
        if (node->data == key) {
          return node;
        }
      }
      return nullptr;
    }
  
    void Remove(const int &key) {
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

    std::string getName(const int &key) {
      return Find(key)->name;
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
    
      bool Find(const int &key) { return table[hash(key)].Find(key); }
    
      void Add(const int &key, const std::string &str) {
        bool result = table[hash(key)].Find(key);
        if (!result) {
          table[hash(key)].Add(key, str);
        } else {
          table[hash(key)].Find(key)->name = str;
        }
      }

      std::string getName(const int &key) {
        return table[hash(key)].getName(key);
      }
    
      void Del(const int &key) { table[hash(key)].Remove(key); }
    
      void Check(size_t n) { table[n].Print(); }
    };
    
int main() {
  HashTable hashtable(10000000);
  int n = 0;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::string input = "";
    int key = 0;
    std::cin >> input;
    std::cin >> key;
    if (input ==  "add") {
      std::string name;
      std::cin >> name;
      hashtable.Add(key, name);
    } else if (input ==  "find") {
      if (hashtable.Find(key)) {
        std::cout << hashtable.getName(key) << "\n";
      } else {
        std::cout << "not found" << "\n";
      }
    } else if (input ==  "del") {
      hashtable.Del(key);
    }
  }
}