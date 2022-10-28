/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:43:59 by jihoolee          #+#    #+#             */
/*   Updated: 2022/10/29 00:37:29 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP_
# define TREE_ITERATOR_HPP_

# include <cstddef>
# include <iterator>

template <typename Category, typename T, typename Distance = ptrdiff_t,
          typename Pointer = T*, typename Reference = T&>
class iterator {
 public:
  typedef T         value_type;
  typedef Distance  difference_type;
  typedef Pointer   pointer;
  typedef Reference reference;
  typedef Category  iterator_category;
};

template <typename T>
class TreeIterator : public iterator<std::bidirectional_iterator_tag, T> {
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

  explicit TreeIterator(node_pointer ptr = nullptr) : ptr_(ptr) {}

  TreeIterator(const TreeIterator& other) : ptr_(other.ptr_) {}

  TreeIterator& operator=(const TreeIterator& other) {
    if (this != &other)
      ptr_ = other.ptr_;
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

 protected:
  node_pointer ptr_;

 private:
  void increment_(void) {
    if (ptr_ == nullptr)
      return;
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
    if (ptr == nullptr) {

    }
  }
};  //  TreeIterator

#endif  //  TREE_ITERATOR_HPP_
