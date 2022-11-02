/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:43:59 by jihoolee          #+#    #+#             */
/*   Updated: 2022/11/02 23:25:01 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP_
# define TREE_ITERATOR_HPP_

# include <cstddef>
# include <iterator>
# include <exception>

template <typename T>
class TreeIterator
  : public std::iterator<std::bidirectional_iterator_tag,
                          typename T::value_type> {
 public:
  typedef T
      node_type;
  typedef T*
      node_pointer;
  typedef typename
    std::iterator<std::bidirectional_iterator_tag,
                  typename T::value_type>::value_type
      value_type;
  typedef typename
    std::iterator<std::bidirectional_iterator_tag,
                  value_type>::difference_type
      difference_type;
  typedef typename
    std::iterator<std::bidirectional_iterator_tag,
                  value_type>::pointer
      pointer;
  typedef typename
    std::iterator<std::bidirectional_iterator_tag,
                  value_type>::reference
      reference;
  typedef typename
    std::iterator<std::bidirectional_iterator_tag,
                  value_type>::iterator_category
      iterator_category;

  explicit TreeIterator(node_pointer p = nullptr, node_pointer r = nullptr)
    : ptr_(p), root_(r) {}

  TreeIterator(const TreeIterator& other)
    : ptr_(other.ptr_), root_(other.root_) {}

  TreeIterator& operator=(const TreeIterator& other) {
    if (this != &other) {
      ptr_ = other.ptr_;
      root_ = other.root_;
    }
    return *this;
  }

  bool operator==(const TreeIterator& rhs) const {
    return ptr_ == rhs.ptr_;
  }

  bool operator!=(const TreeIterator& rhs) const {
    return !(*this == rhs);
  }

  reference operator*() const {
    return ptr_->value;
  }

  pointer operator->() const {
    return &(ptr_->value);
  }

  TreeIterator& operator++() {
    increment_();
    return *this;
  }

  TreeIterator operator++(int) {
    TreeIterator temp(*this);

    increment_();
    return temp;
  }

  TreeIterator& operator--() {
    decrement_();
    return *this;
  }

  TreeIterator operator--(int) {
    TreeIterator temp(*this);

    decrement_();
    return temp;
  }

  node_pointer base(void) const {
    return ptr_;
  }

 protected:
  node_pointer  ptr_;
  node_pointer  root_;

 private:
  void increment_(void) {
    if (ptr_->right != nullptr) {
      ptr_ = ptr_->right;
      while (ptr_->left != nullptr)
        ptr_ = ptr_->left;
    } else {
      node_pointer parent = ptr_->parent;

      while (parent != nullptr && ptr_ == parent->right) {
        ptr_ = parent;
        parent = parent->parent;
      }
      ptr_ = parent;
    }
  }

  void decrement_(void) {
    if (ptr_ == nullptr) {
      ptr_ = root_;
      while (ptr_->right != nullptr)
        ptr_ = ptr_->right;
    } else if (ptr_->left != nullptr) {
      ptr_ = ptr_->left;
      while (ptr_->right != nullptr)
        ptr_ = ptr_->right;
    } else {
      node_pointer parent = ptr_->parent;

      while (parent != nullptr && ptr_ == parent->left) {
        ptr_ = parent;
        parent = parent->parent;
      }
      ptr_ = parent;
    }
  }
};  //  TreeIterator

#endif  //  TREE_ITERATOR_HPP_
