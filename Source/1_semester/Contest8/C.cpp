#include <cstring>
#include <iostream>

struct Node {
  char val;
  Node *next = nullptr;
};

struct Stack {
  Node *head = nullptr;
  size_t size = 0;

  bool IsEmpty() {
    return head == nullptr;
  }

  void Push(char value) {
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

  char Back() {
    if (head == nullptr) {
      return ' ';
    }
    return head->val;
  }

  void Clear() {
    while (size != 0) {
      Pop();
    }
  }
};

int main() {
  char *s = new char[100001];
  std::cin.getline(s, 100001, '\n');

  Stack stack;

  char *c = s;
  while (*c != 0) {
    if (*c == '(') {
      stack.Push('(');
    } else if (stack.Back() == '(') {
      stack.Pop();
    } else {
      stack.Push(')');
    }
    c++;
  }

  std::cout << stack.size << '\n';

  stack.Clear();
  delete[] s;

  return 0;
}
