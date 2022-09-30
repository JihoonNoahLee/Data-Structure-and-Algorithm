/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:36:02 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/29 19:23:19 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_HPP_
# define LINKED_LIST_HPP_

# include <memory>
# include <stdexcept>

# include "type_traits.hpp"
# include "list_node.hpp"
# include "list_iterator.hpp"

namespace ft {
template <typename T, typename Alloc = std::allocator<T> >
class list {
 public:
  typedef T                                         value_type;
  typedef Alloc                                     allocator_type;
  typedef typename allocator_type::reference        reference;
  typedef typename allocator_type::const_reference  const_reference;
  typedef typename allocator_type::pointer          pointer;
  typedef typename allocator_type::const_pointer    const_pointer;
  typedef typename allocator_type::size_type        size_type;
  typedef typename allocator_type::differende_type  difference_type;
  typedef list_iterator<value_type>                 iterator;
  typedef list_const_iterator<value_type>           const_iterator;
  typedef reverse_iterator<iterator>                reverse_iterator;
  typedef ft::reverse_iterator<const_iterator>      const_reverse_iterator;

  explicit list(const allocator_type& alloc = allocator_type())
    : alloc_(alloc) {
    last_node_ = node_alloc_.allocate(1);
    node_alloc_.construct(last_node_, __node_type());
    last_node_->prev = last_node_;
    last_node_->next = last_node_;
  }

  explicit list(size_type n, const value_type& val = value_type(),
    const allocator_type& alloc = allocator_type())
    : alloc_(alloc) {
    last_node_ = node_alloc_.allocate(1);
    node_alloc_.construct(last_node_, __node_type());
    last_node_->prev = last_node_;
    last_node_->next = last_node_;
    this->insert(this->end(), n, val);
  }

  template <typename InputIterator>
  list (InputIterator first,
        InputIterator last,
        const allocator_type& alloc = allocator_type(),
        typename enable_if<!is_integral<InputIterator>::value>::type* = nullptr)
    : alloc_(alloc) {
    last_node_ = node_alloc_.allocate(1);
    node_alloc_.construct(last_node_, __node_type());
    last_node_->prev = last_node_;
    last_node_->next = last_node_;
    this->insert(this->end(), first, last);
  }

  explicit list(const list& x)
    : alloc_(x.alloc_) {
    last_node_ = node_alloc_.allocate(1);
    node_alloc_.construct(last_node_, __node_type());
    last_node_->prev = last_node_;
    last_node_->next = last_node_;
    this->insert(this->end(), x.begin(), x.end());
  }

  virtual ~list(void) {
    this->clear();
    node_alloc_.destroy(last_node_);
    node_alloc_.deallocate(last_node_, 1);
  }

  list& operator=(const list& x) {
    if (this == &x)
      return (*this);
    this->assign(x.begin(), x.end());
    return (*this);
  }

  iterator begin(void) {
    return (iterator(last_node_->next));
  }

  const_iterator begin(void) const {
    return (const_iterator(last_node_->next));
  }

  iterator end(void) {
    return (iterator(last_node_));
  }

  const_iterator end(void) const {
    return (const_iterator(last_node_));
  }

  reverse_iterator rbegin(void) {
    return (reverse_iterator(this->end()));
  }

  const_reverse_iterator rbegin(void) const {
    return (const_reverse_iterator(this->end()));
  }

  reverse_iterator rend(void) {
    return (reverse_iterator(this->begin()));
  }

  const_reverse_iterator rend(void) const {
    return (const_reverse_iterator(this->begin()));
  }

  bool empty(void) const {
    return (last_node_->next == last_node_);
  }

  size_type size(void) const {
    size_type size = 0;
    for (const_iterator it = this->begin(); it != this->end(); ++it)
      ++size;
    return (size);
  }

  size_type max_size(void) const {
    return (node_alloc_.max_size());
  }

  reference front(void) {
    return (last_node_->next->data);
  }

  const_reference front(void) const {
    return (last_node_->next->data);
  }

  reference back(void) {
    return (last_node_->prev->data);
  }

  const_reference back(void) const {
    return (last_node_->prev->data);
  }

  iterator insert(iterator position, const value_type& val) {
    return insert_before_(position.node_, create_node_(val));
  }

  void insert(iterator position, size_type n, const value_type& val) {
    while (n--)
      insert_before_(position.node_, create_node_(val));
  }

 protected:
  typedef Node<value_type>                          __node_type;
  typedef typename allocator_type::template
            rebind<Node<T> >::other                 __node_allocator;
  typedef typename __node_allocator::pointer        __node_pointer;

 private:
  allocator_type    alloc_;
  __node_allocator  node_alloc_;
  __node_pointer    last_node_;

  __node_pointer create_node_(const value_type& val,
                              __node_pointer prev_p = nullptr,
                              __node_pointer next_p = nullptr) {
    __node_pointer new_node = node_alloc_.allocate(1);

    node_alloc_.construct(new_node, __node_type(val));
    new_node->prev = prev;
    new_node->next = next;
    return (new_node);
  }

  iterator insert_before_(__node_pointer next, __node_pointer new_node) {
    new_node->next = next;
    if (next->prev == last_node_) {
      new_node->prev = lsat_node_;
      last_node_->next = new_node;
    } else {
      new_node->prev = next->prev;
      next->prev->next = new_node;
    }
    next->prev = new_node;
    return iterator(next->prev);
  }

};  //  class list
}  //  namespace ft

#endif
