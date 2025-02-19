#include <iostream>
#include <random>

struct Node {
  int key;
  int priority;
  Node *left;
  Node *right;

  Node(int a_key, int a_priority) : key(a_key), priority(a_priority), left(nullptr), right(nullptr) {
  }

  Node(int a_key, std::mt19937 &gen) : key(a_key), left(nullptr), right(nullptr) {
    priority = static_cast<int>(gen());
  }
};

struct Pair {
  Node *first;
  Node *second;
};

class Treap {
 public:
  Treap() : root_(nullptr) {
  }

  ~Treap() {
    Delete(root_);
  }

  void Print() {
    Print(root_);
  };

  void RandInsert(int key, std::mt19937 &gen);
  void Insert(int key, int priority);
  void Remove(int key);
  void PreorderWalk(Node *root_);
  Node *GetRoot() {
    return root_;
  }

  Node *Min(Node *node);
  Node *Max(Node *node);

 private:
  Node *root_;
  Node *Merge(Node *l, Node *r);
  Node *Search(int key);
  Node *Remove(Node *root_, int key);
  void Print(Node *root_);
  void Delete(Node *root_);
  Pair Split(Node *root_, int key);
};

Node *Treap::Min(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }

  while (node->left != nullptr) {
    node = node->left;
  }

  return node;
}

Node *Treap::Max(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }

  while (node->right != nullptr) {
    node = node->right;
  }

  return node;
}

Node *Treap::Search(int key) {
  Node *runner = root_;
  while (runner) {
    if (runner->key > key) {
      runner = runner->left;
      continue;
    }
    if (runner->key < key) {
      runner = runner->right;
      continue;
    }
    if (runner->key == key) {
      return runner;
    }
  }
  return nullptr;
}

void Treap::Print(Node *root_) {
  if (root_ != nullptr) {
    Print(root_->left);
    std::cout << root_->key << ' ' << root_->priority << '\n';
    Print(root_->right);
  }
}

void Treap::Delete(Node *root_) {
  if (root_ != nullptr) {
    Delete(root_->left);
    Delete(root_->right);
    delete root_;
  }
}

Node *Treap::Merge(Node *l, Node *r) {
  if (l == nullptr) {
    return r;
  }
  if (r == nullptr) {
    return l;
  }

  if (l->priority < r->priority) {
    l->right = Merge(l->right, r);
    return l;
  }

  r->left = Merge(l, r->left);
  return r;
}

Pair Treap::Split(Node *root_, int key) {
  if (root_ == nullptr) {
    return {nullptr, nullptr};
  }
  if (key > root_->key) {
    Pair splitted = Split(root_->right, key);
    root_->right = splitted.first;
    return {root_, splitted.second};
  }
  Pair splitted = Split(root_->left, key);
  root_->left = splitted.second;
  return {splitted.first, root_};
}

void Treap::RandInsert(int key, std::mt19937 &gen) {
  Pair s = Split(root_, key);
  Node *temp = new Node(key, gen);
  Node *merged = Merge(s.first, temp);

  root_ = Merge(merged, s.second);
}

void Treap::Insert(int key, int priority) {
  Pair s = Split(root_, key);
  Node *temp = new Node(key, priority);
  Node *merged = Merge(s.first, temp);

  root_ = Merge(merged, s.second);
}

Node *Treap::Remove(Node *root_, int key) {
  if (root_ == nullptr) {
    return nullptr;
  }
  if (root_->key == key) {
    Node *node = Merge(root_->left, root_->right);
    delete root_;
    return node;
  }
  if (root_->key < key) {
    root_->right = Remove(root_->right, key);
  } else {
    root_->left = Remove(root_->left, key);
  }
  return root_;
}

void Treap::PreorderWalk(Node *root_) {
  if (root_ != nullptr) {
    std::cout << root_->key << "\n";
    PreorderWalk(root_->left);
    PreorderWalk(root_->right);
  }
}

void Treap::Remove(int key) {
  root_ = Remove(root_, key);
}

int main() {
  Treap treap;
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int key = 0;
    int priority = 0;
    std::cin >> key >> priority;
    treap.Insert(key, priority);
  }
  treap.PreorderWalk(treap.GetRoot());
}
