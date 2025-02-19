#include <cstring>
#include <iostream>

struct Node {
  int val;
  Node *next = nullptr;
};

struct Queue {
  Node *head = nullptr;
  Node *tail = nullptr;
  size_t size = 0;

  void Push(int value) {
    Node *new_node = new Node{value, nullptr};
    if (size == 0) {
      head = new_node;
      tail = new_node;
      size++;
      return;
    }
    tail->next = new_node;
    tail = new_node;
    size++;
  }

  void Pop() {
    if (size == 0) {
      return;
    }
    Node *new_node = head;
    head = new_node->next;
    delete new_node;
    if (head == nullptr) {
      tail = nullptr;
    }
    size -= 1;
  }

  void Front() {
    std::cout << head->val << '\n';
  }

  void Clear() {
    while (size != 0) {
      Pop();
    }
  }
};

int main() {
  char str[6];
  Queue queue;
  while (true) {
    std::cin >> str;
    if (!strcmp(str, "pop")) {
      queue.Front();
      queue.Pop();
    } else if (!strcmp(str, "push")) {
      int key = 0;
      std::cin >> key;
      queue.Push(key);
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "front")) {
      queue.Front();
    } else if (!strcmp(str, "clear")) {
      queue.Clear();
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "size")) {
      std::cout << queue.size << '\n';
    } else if (!strcmp(str, "exit")) {
      std::cout << "bye" << '\n';
      break;
    }
  }
  queue.Clear();
  return 0;
}