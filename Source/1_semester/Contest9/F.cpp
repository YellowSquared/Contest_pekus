#include <iostream>

struct Node {
  int value;
  Node *left = nullptr;
  Node *right = nullptr;
  Node *parent = nullptr;
};

class BST {
 public:
  void InorderWalk(Node *root);
  void PreorderWalk(Node *root);
  void PostorderWalk(Node *root);
  void Insert(int value);
  void Clear(Node *root);
  Node *Min(Node *node);
  Node *Max(Node *node);
  void Erase(int key);
  int Height(Node *node);
  void Balance(Node *root, int &result);

  Node *GetRoot() { return root_; }
  Node *MaxWalk(Node *root);
  int SearchSecondMax(Node* root, int max);

 private:
  Node *Next(Node *node);
  Node *Prev(Node *node);
  Node *root_ = nullptr;
  Node *Search(Node *root, int key);
  void Insert(Node *&root, Node *node);
  void Erase(Node *target);
};

Node *BST::Search(Node *root, int key) {
  if (root == nullptr) {
    return nullptr;
  }

  if (key == root->value) {
    return root;
  }

  if (key > root->value) {
    return Search(root->right, key);
  }

  return Search(root->left, key);
}

void BST::Insert(Node *&root, Node *node) {
  if (root == nullptr) {
    root = node;
    return;
  }

  if (root->value > node->value) {
    if (root->left == nullptr) {
      node->parent = root;
      root->left = node;
    } else {
      Insert(root->left, node);
    }
  } else {
    if (root->right == nullptr) {
      node->parent = root;
      root->right = node;
    } else {
      Insert(root->right, node);
    }
  }
}

void BST::Insert(int value) {
  if (Search(root_, value) != nullptr) {
    return;
  }

  Node *new_node = new Node{value};
  Insert(root_, new_node);
}

void BST::InorderWalk(Node *root) {
  if (root != nullptr) {
    InorderWalk(root->left);
    std::cout << root->value << " ";
    InorderWalk(root->right);
  }
}

void BST::Clear(Node *root) {
  if (root != nullptr) {
    Clear(root->left);
    Clear(root->right);
    delete root;
  }
}

void BST::PreorderWalk(Node *root) {
  if (root != nullptr) {
    std::cout << root->value << " ";
    PreorderWalk(root->left);
    PreorderWalk(root->right);
  }
}

void BST::PostorderWalk(Node *root) {
  if (root != nullptr) {
    PostorderWalk(root->left);
    PostorderWalk(root->right);
    std::cout << root->value << " ";
  }
}

Node *BST::Min(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }

  while (node->left != nullptr) {
    node = node->left;
  }

  return node;
}

Node *BST::Max(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }

  while (node->right != nullptr) {
    node = node->right;
  }

  return node;
}

Node *BST::Next(Node *node) { return Min(node->right); }

Node *BST::Prev(Node *node) { return Max(node->left); }

void BST::Erase(Node *target) {
  if (target == nullptr) {
    return;
  }
  Node *parent = target->parent;

  if (parent == nullptr) {
    if (target->left == nullptr && target->right == nullptr) {
      root_ = nullptr;
      delete target;
      return;
    }

    if (target->left == nullptr || target->right == nullptr) {
      if (target->left == nullptr) {
        root_ = target->right;
      } else {
        root_ = target->left;
      }
      delete target;
      return;
    }

    Node *successor = Next(target);
    target->value = successor->value;

    if (successor->parent->left == successor) {
      successor->parent->left = successor->right;
      if (successor->right != nullptr) {
        successor->right->parent = successor->parent;
      }
    } else {
      successor->parent->right = successor->right;

      if (successor->right != nullptr) {
        successor->right->parent = successor->parent;
      }
    }
    delete successor;
    return;
  }

  if (target->left == nullptr && target->right == nullptr) {
    if (parent->left == target) {
      parent->left = nullptr;
    } else {
      parent->right = nullptr;
    }
    delete target;
    return;
  }

  if (target->left == nullptr || target->right == nullptr) {
    if (target->left == nullptr) {
      if (parent->left == target) {
        parent->left = target->right;
      } else {
        parent->right = target->right;
      }
      target->right->parent = parent;
    } else {
      if (parent->left == target) {
        parent->left = target->left;
      } else {
        parent->right = target->left;
      }
      target->left->parent = parent;
    }
    delete target;
    return;
  }

  Node *successor = Next(target);
  target->value = successor->value;

  if (successor->parent->left == successor) {
    successor->parent->left = successor->right;
    if (successor->right != nullptr) {
      successor->right->parent = successor->parent;
    }
  } else {
    successor->parent->right = successor->right;

    if (successor->right != nullptr) {
      successor->right->parent = successor->parent;
    }
  }
  delete successor;
}

void BST::Erase(int key) { Erase(Search(root_, key)); }

int BST::Height(Node *node) {
  if (node == nullptr) {
    return 0;
  }
  return std::max(Height(node->left), Height(node->right)) + 1;
}

void BST::Balance(Node *root, int &result) {
  if (root != nullptr) {
    Balance(root->left, result);
    if (abs(Height(root->right) - Height(root->left)) > 1) {
      result = -1;
    }
    Balance(root->right, result);
  }
}

Node *BST::MaxWalk(Node *root) {
  while (root->right != nullptr) {
    root = root->right;
  }
  return root;
}

int SearchSecondMax(Node* root, int max) {
  int cur = 0;
  while (root != nullptr) {
    if (root->value < max) {
      cur = root->value;
      root = root->right;
    } else {
      root = root->left;
    }
  }
  return cur;
}

int main() {
  BST bst;
  int n = 0;
  int size = 1;
  std::cin >> n;
  while (n != 0) {
    size++;
    bst.Insert(n);
    std::cin >> n;
  }

  std::cout << SearchSecondMax(bst.GetRoot(), bst.MaxWalk(bst.GetRoot())->value);

  bst.Clear(bst.GetRoot());
}