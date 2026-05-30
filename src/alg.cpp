// Copyright 2021 NNTU-CS
#include "bst.h"
#include <iostream>
#include <fstream>
#include <cctype>

// чтение слов из файла и заполнение дерева
void makeTree(BST<std::string>& tree, const char* filename) {
  std::ifstream file(filename);
  
  if (!file.is_open()) {
    std::cout << "File not found!" << std::endl;
    return;
  }

  std::string word;
  char ch;
  
  // читаем посимвольно
  while (file.get(ch)) {
    if (std::isalpha(static_cast<unsigned char>(ch))) {
      word += std::tolower(static_cast<unsigned char>(ch));
    } else {
      if (!word.empty()) {
        tree.insert(word);
        word.clear();
      }
    }
  }

  if (!word.empty()) {
    tree.insert(word);
  }

  file.close();
}
// вывод частот слов
void printFreq(BST<std::string>& tree) {
  std::vector<std::pair<std::string, int>> words = tree.getAll();

  // сортировка по убыванию частоты
  std::sort(words.begin(), words.end(),
    [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
      if (a.second != b.second) return a.second > b.second;
      return a.first < b.first;
    });

  std::ofstream out("result/freq.txt");
  
  for (const auto& p : words) {
    std::cout << p.first << " -> " << p.second << std::endl;
    out << p.first << " -> " << p.second << std::endl;
  }

  out.close();
}
