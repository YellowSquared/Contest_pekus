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

  Node *GetRoot() { return root; }
  void SetRoot(Node *node) { root = node; }

private:
  Node *root = nullptr;
  Node *Search(Node *root, int key);
  void Insert(Node* &root, Node *node);
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

void BST::Insert(Node* &root, Node *node) {
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
  if (Search(root, value) != nullptr) {
    return;
  }

  Node *new_node = new Node{value};
  Insert(root, new_node);
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

int main() {
  BST bst;
  int n = 0;
  std::cin >> n;
  while (n != 0) {
    bst.Insert(n);
    std::cin >> n;
  }
  bst.InorderWalk(bst.GetRoot());
}
