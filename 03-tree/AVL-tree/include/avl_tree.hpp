/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:23:47 by jihoolee          #+#    #+#             */
/*   Updated: 2022/10/31 20:27:51 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP_
# define AVL_TREE_HPP_

# include <functional>
# include <memory>
# include "tree_iterator.hpp"

template <typename T>
struct Node {
  typedef T value_type;

  value_type  value;
  Node*       parent;
  Node*       left;
  Node*       right;

  Node(value_type v = value_type(),
        Node* p = nullptr,
        Node* l = nullptr,
        Node* r = nullptr)
    : value(v), parent(p), left(l), right(r) {}
};  //  Node

template <typename T,
          typename Compare = std::less<T>,
          typename Allocator = std::allocator<T> >
class AVLTree {
 public:
  typedef T                                                     value_type;
  typedef Compare                                               value_compare;
  typedef Allocator                                             allocator_type;
  typedef typename allocator_type::reference                    reference;
  typedef typename allocator_type::const_reference              const_reference;
  typedef typename allocator_type::pointer                      pointer;
  typedef typename allocator_type::const_pointer                const_pointer;
  typedef typename allocator_type::size_type                    size_type;
  typedef typename allocator_type::difference_type              difference_type;
  typedef Node<value_type>                                      node;
  typedef typename allocator_type::template rebind<Node>::other node_allocator;
  typedef node*                                                 node_ptr;
  typedef TreeIterator<node>                                    iterator;

  AVLTree(const value_compare& comp = value_compare(),
          const allocator_type& alloc = allocator_type())
    : root_(nullptr), size_(0), comp_(comp), alloc_(alloc) {}

  template <typename InputIterator>
  AVLTree(InputIterator first, InputIterator last,
          const value_compare& comp = value_compare(),
          const allocator_type& alloc = allocator_type())
    : root_(nullptr), size_(0), comp_(comp), alloc_(alloc) {
      for (InputIterator curr = first; curr != last; ++curr)
        this->insert(curr->value);
    }

  virtual ~AVLTree() {
    this->clear();
  }

  AVLTree& operator=(const AVLTree& avlt) {
    if (this != & avlt) {
      this->clear();
      alloc_ = avlt.alloc_;
      comp_ = avlt.comp_;
      this->insert(avlt.begin(), avlt.end());
    }
  }

  iterator begin(void) {
    return iterator(this->get_left_most_(), root_);
  }

  iterator end(void) {
    return iterator(nullptr, root_);
  }

  bool empty() const {
    return size_ == 0;
  }

  size_type size() const {
    return size_;
  }

  void insert(const reference& value) {
    node_ptr new_node = create_node_(value);

    if (root_ == nullptr) {
      root_ = new_node;
      ++size_;
      return;
    }
    while ()
  }

  void clear(void) {
    this->destroy_tree_(root_);
    root_ = nullptr;
    size_ = 0;
  }

 private:
  node_ptr create_node_(value_type value) {
    node_ptr  new_node = alloc_.allocate(1);

    alloc_.construct(new_node, value);
    return new_node;
  }

  void destroy_node_(node_ptr node) {
    alloc_.destroy(node);
    alloc_.deallocate(node, 1);
  }

  void destroy_tree_(node_ptr node) {
    if (node == nullptr)
      return ;
    destroy_tree_(node->left);
    destroy_tree_(node->right);
    destroy_node_(node);
  }

  void copy_tree_(node_ptr node) {
    if (node == nullptr)
      return ;
    insert_node(node->value);
    copy_tree_(node->left);
    copy_tree_(node->right);
  }

  void rotate_left(node_ptr node) {
    node_ptr  right = node->right;
    node_ptr  parent = node->parent;

    node->right = right->left;
    if (right->left != nullptr)
      right->left->parent = node;
    right->left = node;
    node->parent = right;
    right->parent = parent;
    if (parent == nullptr)
      root_ = right;
    else if (parent->left == node)
      parent->left = right;
    else
      parent->right = right;
  }

  void rotate_right(node_ptr node) {
    node_ptr  left = node->left;
    node_ptr  parent = node->parent;

    node->left = left->right;
    if (left->right != nullptr)
      left->right->parent = node;
    left->right = node;
    node->parent = left;
    left->parent = parent;
    if (parent == nullptr)
      root_ = left;
    else if (parent->left == node)
      parent->left = left;
    else
      parent->right = left;
  }

  node_ptr        root_;
  size_type       size_;
  value_compare   comp_;
  node_allocator  alloc_;
};  //  AVLTree

#endif  //  AVL_TREE_HPP_
