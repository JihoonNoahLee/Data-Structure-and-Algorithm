/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:05:51 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/29 17:54:41 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP_
# define LIST_ITERATOR_HPP_

# include "iterator.hpp"
# include "list_node.hpp"

namespace ft {
template <typename T>
class list_iterator: public iterator<bidirectional_iterator_tag, T> {
 public:
  typedef typename iterator<random_access_iterator_tag, T>::value_type
    value_type;
  typedef typename iterator<random_access_iterator_tag, T>::difference_type
    difference_type;
  typedef typename iterator<random_access_iterator_tag, T>::pointer
    pointer;
  typedef typename iterator<random_access_iterator_tag, T>::reference
    reference;
  typedef typename iterator<random_access_iterator_tag, T>::iterator_category
    iterator_category;

  explicit list_iterator(Node<T>* node = nullptr) : node_(node) {}

  explicit list_iterator(const list_iterator& iter) : node_(iter.node_) {}

  list_iterator& operator=(const list_iterator& iter) {
    if (this == &iter)
      return *this;
    node_ = iter.node_;
    return *this;
  }

  virtual ~list_iterator(void) {}

  reference operator*(void) const {
    return node_->data;
  }

  pointer operator->(void) const {
    return &(this->operator*());
  }

  list_iterator& operator++(void) {
    node_ = node_->next;
    return *this;
  }

  list_iterator operator++(int) {
    list_iterator tmp(*this);
    this->operator++();
    return tmp;
  }

  list_iterator& operator--(void) {
    node_ = node_->prev;
    return *this;
  }

  list_iterator operator--(int) {
    list_iterator tmp(*this);
    this->operator--();
    return tmp;
  }

  bool operator==(const list_iterator& iter) const {
    return node_ == iter.node_;
  }

  bool operator!=(const list_iterator& iter) const {
    return !(*this == iter);
  }

 private:
  Node<T>* node_;
};

template <typename T>
class list_const_iterator : iterator<bidirectional_iterator_tag, T> {
 public:
  typedef typename iterator<random_access_iterator_tag, T>::value_type
    value_type;
  typedef typename iterator<random_access_iterator_tag, T>::difference_type
    difference_type;
  typedef typename iterator<random_access_iterator_tag, T>::pointer
    pointer;
  typedef typename iterator<random_access_iterator_tag, T>::reference
    reference;
  typedef typename iterator<random_access_iterator_tag, T>::iterator_category
    iterator_category;

    explicit list_const_iterator(Node<T>* node = nullptr) : node_(node) {}

    explicit list_const_iterator(const list_const_iterator& iter)
      : node_(iter.node_) {}

    list_const_iterator& operator=(const list_const_iterator& iter) {
      if (this == &iter)
        return *this;
      node_ = iter.node_;
      return *this;
    }

    virtual ~list_const_iterator(void) {}

    reference operator*(void) const {
      return node_->data;
    }

    pointer operator->(void) const {
      return &(this->operator*());
    }

    list_const_iterator& operator++(void) {
      node_ = node_->next;
      return *this;
    }

    list_const_iterator operator++(int) {
      list_const_iterator tmp(*this);
      this->operator++();
      return tmp;
    }

    list_const_iterator& operator--(void) {
      node_ = node_->prev;
      return *this;
    }

    list_const_iterator operator--(int) {
      list_const_iterator tmp(*this);
      this->operator--();
      return tmp;
    }

    bool operator==(const list_const_iterator& iter) const {
      return node_ == iter.node_;
    }

    bool operator!=(const list_const_iterator& iter) const {
      return !(*this == iter);
    }

 private:
  Node<T>* node_;
};
}  //  namespace ft
#endif  //  LIST_ITERATOR_HPP_
