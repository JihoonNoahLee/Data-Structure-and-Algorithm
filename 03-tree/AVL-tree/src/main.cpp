/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:25:25 by jihoolee          #+#    #+#             */
/*   Updated: 2022/11/03 00:20:23 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "avl_tree.hpp"

template <typename T>
void visualize_AVLTree(const std::string& prefix, const T* node, bool isLeft)
{
  if (node == nullptr)
  {
    std::cout << prefix << (isLeft ? "├──" : "└──" ) << "nullptr" << std::endl;
    return ;
  }
  std::cout << prefix << (isLeft ? "├──" : "└──" ) << node->value << std::endl;
  visualize_AVLTree(prefix + (isLeft ? "│   " : "    "), node->left, true);
  visualize_AVLTree(prefix + (isLeft ? "│   " : "    "), node->right, false);
}

template <typename T>
void visualize_AVLTree(const AVLTree<T>& tree) {
  Node<T>* root = tree.begin().base();

  if (root == nullptr)
    return;
  while (root->parent != nullptr)
    root = root->parent;
  visualize_AVLTree("", root, false);
}

template <typename T>
void print_AVLTree(const AVLTree<T>& tree)
{
  std::cout << "empty: " << std::boolalpha << tree.empty() << std::endl;
  std::cout << "size: " << tree.size() << std::endl;
  std::cout << "AVLTree in order: " << std::endl;
  for (typename AVLTree<T>::iterator it = tree.begin(); it != tree.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl << std::endl;
}

int main(void) {
  AVLTree<int> tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  print_AVLTree(tree);
  visualize_AVLTree(tree);
  std::cout << std::endl;

  tree.erase(tree.begin());
  tree.erase(30);
  print_AVLTree(tree);
  visualize_AVLTree(tree);
  std::cout << std::endl;

  tree.clear();
  print_AVLTree(tree);
  visualize_AVLTree(tree);

  std::vector<int> vec = {3, 2, 1, 4, 5, 6, 7, 16, 15, 14};

  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    tree.insert(*it);
  print_AVLTree(tree);
  visualize_AVLTree(tree);
  std::cout << std::endl;

  tree.erase(4);
  tree.erase(14);
  print_AVLTree(tree);
  visualize_AVLTree(tree);
  return 0;
}
