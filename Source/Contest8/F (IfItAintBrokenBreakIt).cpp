#include <cstring>
#include <iostream>

struct Node {
  int val;
  Node* next = nullptr;
};

struct Queue {
  Node* head = nullptr;
  Node* tail = nullptr;
  Node* middle = nullptr;
  int size = 0;

  void Push(int value) {
    Node* new_node = new Node;
    new_node->val = value;
    size += 1;
    if (size == 1) {
      head = new_node;
      tail = new_node;
      middle = new_node;
      return;
    }
    if (size % 2) {
      middle = middle->next;
    }
    tail->next = new_node;
    tail = new_node;
  }

  void PushToTheMiddle(int value) {
    Node* new_node = new Node;
    new_node->val = value;
    if (size == 0) {
      head = new_node;
      tail = new_node;
      middle = new_node;
      size += 1;
      return;
    }
    if (size == 1) {
      head->next = new_node;
      tail = new_node;
      size += 1;
      return;
    }
    new_node->next = middle->next;
    middle->next = new_node;
    size += 1;
    if (size % 2) {
      middle = middle->next;
    }
  }

  void Pop() {
    if (size % 2 == 0) {
      middle = middle->next;
    }
    Node* temp = head;
    head = temp->next;
    delete temp;
    if (head == nullptr) {
      tail = nullptr;
      middle = nullptr;
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
  int n = 0;
  std::cin >> n;
  Queue queue;
  for (int i = 0; i < n; i += 1) {
    char c = 0;
    std::cin >> c;
    if (c == '-') {
      queue.Front();
      queue.Pop();
    } else if (c == '+') {
      int number = 0;
      std::cin >> number;
      queue.Push(number);
    } else {
      int number = 0;
      std::cin >> number;
      queue.PushToTheMiddle(number);
    }
  }
  queue.Clear();
  return 0;
}
