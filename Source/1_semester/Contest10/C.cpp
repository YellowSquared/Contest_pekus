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
  void PreorderWalk(Node *root);
  Node *GetRoot() {
    return root_;
  }

  Node *Min(Node *node);
  Node *Max(Node *node);
  Node *Search(int key);
  int Max_K(Node *root, int target);

 private:
  Node *root_;
  Node *Merge(Node *l, Node *r);
  Node *Remove(Node *root, int key);
  void Print(Node *root);
  void Delete(Node *root);
  Pair Split(Node *root, int key);
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
  while (runner != nullptr) {
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

void Treap::Print(Node *root) {
  if (root != nullptr) {
    Print(root->left);
    std::cout << root->key << ' ' << root->priority << '\n';
    Print(root->right);
  }
}

void Treap::Delete(Node *root) {
  if (root != nullptr) {
    Delete(root->left);
    Delete(root->right);
    delete root;
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

Pair Treap::Split(Node *root, int key) {
  if (root == nullptr) {
    return {nullptr, nullptr};
  }
  if (key > root->key) {
    Pair splitted = Split(root->right, key);
    root->right = splitted.first;
    return {root, splitted.second};
  }
  Pair splitted = Split(root->left, key);
  root->left = splitted.second;
  return {splitted.first, root};
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

Node *Treap::Remove(Node *root, int key) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->key == key) {
    Node *node = Merge(root->left, root->right);
    delete root;
    return node;
  }
  if (root->key < key) {
    root->right = Remove(root->right, key);
  } else {
    root->left = Remove(root->left, key);
  }
  return root;
}

void Treap::PreorderWalk(Node *root) {
  if (root != nullptr) {
    std::cout << root->key << "\n";
    PreorderWalk(root->left);
    PreorderWalk(root->right);
  }
}

void Treap::Remove(int key) {
  root_ = Remove(root_, key);
}

int Treap::Max_K(Node *root, int target) {
  int next = INT32_MAX;

  while (root != nullptr) {
    if (root->key == target) {
      return root->key;
    }
    if (root->key > target) {
      next = std::min(next, root->key);
      root = root->left;
    } else {
      root = root->right;
    }
  }

  return next != INT32_MAX ? next : -1;
}

int main() {
  std::mt19937 gen;
  Treap treap;
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    char type = '0';
    int arg = 0;

    std::cin >> type >> arg;

    if (type == '+') {
      treap.RandInsert(arg, gen);
    } else if (type == '?') {
      std::cout << treap.Max_K(treap.GetRoot(), arg) << "\n";
    }
  }
}
