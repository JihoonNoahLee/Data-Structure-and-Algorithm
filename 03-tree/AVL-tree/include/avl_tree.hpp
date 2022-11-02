/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:23:47 by jihoolee          #+#    #+#             */
/*   Updated: 2022/11/02 23:23:26 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP_
# define AVL_TREE_HPP_

# include <algorithm>
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
  typedef typename allocator_type::template rebind<node>::other node_allocator;
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

  iterator begin(void) const {
    return iterator(this->get_left_most_(), root_);
  }

  iterator end(void) {
    return iterator(nullptr, root_);
  }

  iterator end(void) const {
    return iterator(nullptr, root_);
  }

  bool empty() const {
    return (size_ == 0);
  }

  size_type size() const {
    return size_;
  }

  void insert(const_reference value) {
    node_ptr new_node = create_node_(value);

    if (root_ == nullptr) {
      root_ = new_node;
      ++size_;
      return;
    }
    insert_node_(root_, new_node);
  }

  void erase(iterator position) {
    node_ptr node_to_erase = position.base();

    if (node_to_erase == nullptr)
      return;
    if (node_to_erase->left == nullptr && node_to_erase->right == nullptr) {
      erase_leaf_node_(node_to_erase);
    } else if (node_to_erase->left == nullptr) {
      erase_node_with_one_child_(node_to_erase, node_to_erase->right);
    } else if (node_to_erase->right == nullptr) {
      erase_node_with_one_child_(node_to_erase, node_to_erase->left);
    } else {
      erase_node_with_two_children_(node_to_erase);
    }
    erase_rebalance_(node_to_erase);
  }

  void erase(const_reference value) {
    iterator position = find(value);

    erase(position);
  }

  void erase(iterator first, iterator last) {
    iterator curr = first;

    while (curr != last) {
      iterator next = curr;
      ++next;
      erase(curr);
      curr = next;
    }
  }

  iterator find(const_reference value) {
    node_ptr curr = root_;

    while (curr != nullptr) {
      if (comp_(value, curr->value)) {
        curr = curr->left;
      } else if (comp_(curr->value, value)) {
        curr = curr->right;
      } else {
        return iterator(curr, root_);
      }
    }
    return iterator(nullptr, root_);
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
      return;
    destroy_tree_(node->left);
    destroy_tree_(node->right);
    destroy_node_(node);
  }

  node_ptr get_left_most_(void) const {
    node_ptr curr = root_;

    if (curr == nullptr)
      return nullptr;
    while (curr->left != nullptr)
      curr = curr->left;
    return curr;
  }

  void insert_node_(node_ptr curr, node_ptr new_node) {
    if (comp_(new_node->value, curr->value)) {
      if (curr->left == nullptr) {
        curr->left = new_node;
        new_node->parent = curr;
        ++size_;
        return;
      }
      insert_node_(curr->left, new_node);
      if (get_balance_factor_(curr) == 2) {
        if (comp_(new_node->value, curr->left->value))
          rotate_right_(curr);
        else
          rotate_left_right_(curr);
      }
    } else {
      if (curr->right == nullptr) {
        curr->right = new_node;
        new_node->parent = curr;
        ++size_;
        return;
      }
      insert_node_(curr->right, new_node);
      if (get_balance_factor_(curr) == -2) {
        if (comp_(curr->right->value, new_node->value))
          rotate_left_(curr);
        else
          rotate_right_left_(curr);
      }
    }
  }

  void erase_leaf_node_(node_ptr node) {
    node_ptr  parent = node->parent;

    if (parent == nullptr)
      root_ = nullptr;
    else if (parent->left == node)
      parent->left = nullptr;
    else
      parent->right = nullptr;
    delete_node_(node);
  }

  void erase_node_with_one_child_(node_ptr node, node_ptr child) {
    node_ptr  parent = node->parent;

    child->parent = parent;
    if (parent == nullptr)
      root_ = child;
    else if (parent->left == node)
      parent->left = child;
    else
      parent->right = child;
    delete_node_(node);
  }

  void erase_node_with_two_children_(node_ptr node) {
    node_ptr  successor = get_successor_(node);
    node_ptr  successor_parent = successor->parent;

    node->value = successor->value;
    successor_parent->left = successor->right;
    if (successor->right != nullptr)
      successor->right->parent = successor_parent;
    delete_node_(successor);
  }

  void erase_rebalance_(node_ptr curr) {
    if (curr == nullptr)
      return;
    if (get_balance_factor_(curr) == 2) {
      if (get_balance_factor_(curr->left) >= 0)
        rotate_right_(curr);
      else
        rotate_left_right_(curr);
    } else if (get_balance_factor_(curr) == -2) {
      if (get_balance_factor_(curr->right) <= 0)
        rotate_left_(curr);
      else
        rotate_right_left_(curr);
    }
    erase_rebalance_(curr->parent);
  }

  node_ptr get_successor_(node_ptr node) {
    node_ptr  curr = node->right;

    while (curr->left != nullptr)
      curr = curr->left;
    return curr;
  }

  int get_balance_factor_(node_ptr subtree) {
    return get_height_(subtree->left) - get_height_(subtree->right);
  }

  int get_height_(node_ptr subtree) {
    if (subtree == nullptr)
      return -1;
    return 1 + std::max(get_height_(subtree->left),
                        get_height_(subtree->right));
  }

  void rotate_right_(node_ptr node) {
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

  void rotate_left_(node_ptr node) {
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

  void rotate_left_right_(node_ptr node) {
    rotate_left_(node->left);
    rotate_right_(node);
  }

  void rotate_right_left_(node_ptr node) {
    rotate_right_(node->right);
    rotate_left_(node);
  }

  void delete_node_(node_ptr node) {
    destroy_node_(node);
    --size_;
  }

  node_ptr        root_;
  size_type       size_;
  value_compare   comp_;
  node_allocator  alloc_;
};  //  AVLTree

#endif  //  AVL_TREE_HPP_
