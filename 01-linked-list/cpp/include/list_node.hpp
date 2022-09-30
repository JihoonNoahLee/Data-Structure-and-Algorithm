/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:10:21 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/29 17:12:35 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NODE_HPP_
# define LIST_NODE_HPP_

namespace ft {
template <typename T>
struct Node {
  T         data;
  Node<T>*  prev;
  Node<T>*  next;

  Node(void): data(), prev(nullptr), next(nullptr) {}
  Node(const T& val): data(val), prev(nullptr), next(nullptr) {}
  Node(const T& val, Bode* prev_p, Node* next_p)
    : data(val), prev(prev_p), next(next_p) {}
};
}

#endif
