// Copyright 2021 NNTU-CS
#include "bst.h"
#include <iostream>

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> tree;

  makeTree(tree, "src/war_peace.txt");

  std::cout << "Size: " << tree.size() << std::endl;
  std::cout << "Depth: " << tree.depth() << std::endl;

  printFreq(tree);

  return 0;
}
