/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:25:25 by jihoolee          #+#    #+#             */
/*   Updated: 2022/11/02 00:40:53 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "avl_tree.hpp"

int main(void) {
  AVLTree<int> tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  for (auto iter = tree.begin(); iter != tree.end(); ++iter)
    std::cout << *iter << std::endl;
  std::cout << std::endl;
  tree.erase(tree.begin());
  tree.erase(30);
  for (auto iter = tree.begin(); iter != tree.end(); ++iter)
    std::cout << *iter << std::endl;
  return 0;
}
