/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:36:02 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/22 14:32:35 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_HPP_
# define LINKED_LIST_HPP_

# include <memory>
# include <stdexcept>

template <typename T>
struct Node {
  T         data;
  Node<T>*  next;
  Node<T>*  prev;

  Node(void): data(), next(nullptr) {}
  Node(const T& val): data(val), next(nullptr) {}
  Node(const T& val, Node* next_p): data(val), next(next_p) {}
};

template <typename T, typename Alloc = std::allocator<T> >
class LinkedList {
 public:
  typedef T                                         value_type;
  typedef Alloc                                     allocator_type;
  typedef typename allocator_type::reference        reference;
  typedef typename allocator_type::const_reference  const_reference;
  typedef typename allocator_type::pointer          pointer;
  typedef typename allocator_type::const_pointer    const_pointer;
  typedef typename allocator_type::size_type        size_type;
  typedef typename allocator_type::differende_type  difference_type;

  explicit LinkedList(const allocator_type& alloc = allocator_type())
    : alloc_(alloc), node_alloc_(), head_(nullptr), len_(0), tail_(nullptr) {}

  explicit LinkedList(size_type n, const value_type& val = value_type(),
                      const allocator_type& alloc = allocator_type*())
    : alloc_(alloc), node_alloc_(), head_(nullptr), len_(0), tail_(nullptr) {
  tail_ = head_ = node_alloc_.allocate(1);
  node_alloc_.construct(head_, value_type);
  // this->insert();
  }

/*   LinkedList(const LinkedList& l) : alloc_(l.alloc_) {
    head_ = node_alloc_.allocate(1);
    node_alloc_.construct(head_, *l.head_);
  } */

/*   virtual ~LinkedList(void) {
    this->clear();
  } */

/*   LinkedList& operator=(const LinkedList& l) {
    if (&l == this)
      return *this;
    this->clear();

  } */

  bool empty(void) const {
    return len_ == 0;
  }

  size_type size(void) const {
    return len_;
  }

/*   size_type max_size(void) const {}*/

  reference front(void) {
    return head_->data;
  }

  const_reference front(void) const {
    return head_->data;
  }

  reference back(void) {
    return tail_->data;
  }

  const_reference back(void) const {
    return tail_->data;
  }
/*template <typename InputIterator>
  void assign(InputIterator first, InputIterator last) {} */

  void push_back(const value_type& val) {
    __node_pointer  new_node = node_alloc_.allocate(1);

    node_alloc_.construct(new_node, val);
    if (len_ == 0) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      tail_->next = new_node;
      new_node->prev = tail_;
      tail_ = new_node;
    }
    ++len_;
  }

  void pop_back(void) {
    if (len_ == 0)
      throw std::out_of_range("pop_back on empty list");
    __node_pointer  new_tail = tail_->prev;

    node_alloc_.destroy(tail_);
    node_alloc_.deallocate(tail_, 1);
    if (len_ == 1) {
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      new_tail->next = nullptr;
      tail_ = new_tail;
    }
    --len_;
  }

  size_type insert(size_type idx, const value_type& val) {
    if (idx > len_)
      throw std::out_of_range("Index out of range");
    if (idx == 0) {
      __node_pointer new_node = node_alloc_.allocate(1);

      node_alloc_.construct(new_node, val);
      head_->prev = new_node;
      new_node->next = head_;
      new_node->prev = nullptr;
      head_ = new_node;
    } else {
      __node_pointer new_node = node_alloc_.allocate(1);
      __node_pointer prev_node = head_;

      node_alloc_.construct(new_node, val);
      for (size_type i = 0; i < idx - 1; i++)
        prev_node = prev_node->next;
      prev_node->next->prev = new_node;
      new_node->next = prev_node->next;
      new_node->prev = prev_node;
      prev_node->next = new_node;
    }
    ++len_;
    return idx;
  }

  void insert(size_type idx, size_type n, const value_type& val) {
    for (size_type i = 0; i < n; i++)
      this->insert(idx + i, val);
  }

  size_type erase(size_type idx) {
    __node_pointer curr = head_;

    if (idx >= len_)
      throw std::out_of_range("Index out of range");
    for (size_type i = 0; i < idx; ++i)
      curr = curr->next;
    delete_(curr)
    --len_;
    return idx;
  }

  void erase(size_type first, size_type last) {
    for (size_type i = first; i < last; ++i)
      this->erase(i);
  }

  void clear(void) {
    __node_pointer temp = head_;
    __node_pointer next_temp;

    while (temp != tail_) {
      next_temp = temp->next;
      delete_(temp);
      temp = next_temp;
    }
  }

 protected:
  typedef Node<value_type>                          __node_type;
  typedef typename allocator_type::template
            rebind<Node<T> >::other                 __node_allocator;
  typedef typename __node_allocator::pointer        __node_pointer;

 private:
  allocator_type    alloc_;
  __node_allocator  node_alloc_;
  size_type         len_;
  __node_pointer    head_;
  __node_pointer    tail_;

  void delete_(__node_pointer node) {
    disoconnect_(node);
    node_alloc_.destroy(node);
    node_alloc_.deallocate(node, 1);
  }

  void disoconnect_(__node_pointer node) {
    if (node == head_)
      head_ = node->next;
    else
      node->prev->next = node->next;
    if (node == tail_)
      tail_ = node->prev;
    else
      node->next->prev = node->prev;
  }
};

#endif
