// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

template<typename T>
class BST {
 private:
  struct Node {
    T data;
    int count;
    Node* left;
    Node* right;
    Node(const T& value) : data(value), count(1), left(nullptr), right(nullptr) {}
  };

  Node* root_;
  int size_;

  void add(Node*& node, const T& value) {
    if (node == nullptr) {
      node = new Node(value);
      size_++;
      return;
    }
    if (value < node->data) {
      add(node->left, value);
    } else if (value > node->data) {
      add(node->right, value);
    } else {
      node->count++;
    }
  }

  int find(Node* node, const T& value) const {
    if (node == nullptr) return 0;
    if (value == node->data) return node->count;
    if (value < node->data) return find(node->left, value);
    return find(node->right, value);
  }

  int height(Node* node) const {
    if (node == nullptr) return -1;
    int leftH = height(node->left);
    int rightH = height(node->right);
    return std::max(leftH, rightH) + 1;
  }

  void getAllNodes(Node* node, std::vector<std::pair<T, int>>& vec) const {
    if (node == nullptr) return;
    getAllNodes(node->left, vec);
    vec.push_back(std::make_pair(node->data, node->count));
    getAllNodes(node->right, vec);
  }

  void remove(Node* node) {
    if (node == nullptr) return;
    remove(node->left);
    remove(node->right);
    delete node;
  }

 public:
  BST() : root_(nullptr), size_(0) {}

  ~BST() { remove(root_); }

  void insert(const T& value) {
    add(root_, value);
  }

  int depth() const {
    return height(root_);
  }

  int search(const T& value) const {
    return find(root_, value);
  }

  int size() const {
    return size_;
  }

  bool empty() const {
    return root_ == nullptr;
  }

  std::vector<std::pair<T, int>> getAll() const {
    std::vector<std::pair<T, int>> result;
    getAllNodes(root_, result);
    return result;
  }
};

#endif  // INCLUDE_BST_H_
