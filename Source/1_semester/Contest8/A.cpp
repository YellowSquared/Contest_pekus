#include <cstring>
#include <iostream>

struct Node {
  int val;
  Node *next = nullptr;
};

struct Stack {
  Node *head = nullptr;
  size_t size = 0;

  bool IsEmpty() {
    return head == nullptr;
  }

  void Push(int value) {
    Node *new_node = new Node;
    new_node->val = value;
    new_node->next = head;
    head = new_node;
    size += 1;
  }

  void Pop() {
    if (size == 0) {
      return;
    }
    Node *new_node = head->next;
    delete head;
    head = new_node;
    size -= 1;
  }

  void Back() {
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
  Stack stack;
  while (true) {
    std::cin >> str;
    if (!strcmp(str, "pop")) {
      stack.Back();
      stack.Pop();
    } else if (!strcmp(str, "push")) {
      int key = 0;
      std::cin >> key;
      stack.Push(key);
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "back")) {
      stack.Back();
    } else if (!strcmp(str, "clear")) {
      stack.Clear();
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "size")) {
      std::cout << stack.size << '\n';
    } else if (!strcmp(str, "exit")) {
      std::cout << "bye" << '\n';
      stack.Clear();
      break;
    }
  }
  stack.Clear();
  return 0;
}