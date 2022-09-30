/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:23:24 by jihoolee          #+#    #+#             */
/*   Updated: 2022/03/24 02:21:56 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP_
# define ITERATOR_HPP_

# include <cstddef>

namespace ft {
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <typename Iterator>
class iterator_traits {
 public:
  typedef typename Iterator::difference_type    difference_type;
  typedef typename Iterator::value_type         value_type;
  typedef typename Iterator::pointer            pointer;
  typedef typename Iterator::reference          reference;
  typedef typename Iterator::iterator_category  iterator_category;
};

template <typename T>
class iterator_traits<T*> {
 public:
  typedef ptrdiff_t                       difference_type;
  typedef T                               value_type;
  typedef T*                              pointer;
  typedef T&                              reference;
  typedef ft::random_access_iterator_tag  iterator_category;
};

template <typename T>
class iterator_traits<const T*> {
 public:
  typedef ptrdiff_t                       difference_type;
  typedef T                               value_type;
  typedef const T*                        pointer;
  typedef const T&                        reference;
  typedef ft::random_access_iterator_tag  iterator_category;
};

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

template <typename Iterator>
class reverse_iterator
    : public iterator<typename iterator_traits<Iterator>::iterator_category,
                      typename iterator_traits<Iterator>::value_type,
                      typename iterator_traits<Iterator>::difference_type,
                      typename iterator_traits<Iterator>::pointer,
                      typename iterator_traits<Iterator>::reference> {
 public:
  typedef Iterator
    iterator_type;
  typedef typename ft::iterator_traits<Iterator>::iterator_category
    iterator_category;
  typedef typename ft::iterator_traits<Iterator>::value_type
    value_type;
  typedef typename ft::iterator_traits<Iterator>::difference_type
    difference_type;
  typedef typename ft::iterator_traits<Iterator>::pointer
    pointer;
  typedef typename ft::iterator_traits<Iterator>::reference
    reference;

  reverse_iterator(void) : current_() {}

  explicit reverse_iterator(iterator_type it) : current_(it) {}

  template <typename Iter>
  reverse_iterator(const reverse_iterator<Iter>& rev_it)
    : current_(rev_it.base())  {}

  iterator_type base(void) const { return current_; }

  reverse_iterator& operator=(const reverse_iterator& operand) {
    if (this != &operand)
      this->current_ = operand.current_;
    return *this;
  }

  reference operator*(void) const {
    iterator_type temp(current_);

    return *(--temp);
  }

  reverse_iterator operator+(difference_type n) const {
    return reverse_iterator(current_ - n);
  }

  reverse_iterator& operator++(void) {
    --current_;
    return *this;
  }

  const reverse_iterator operator++(int) {
    const reverse_iterator temp = *this;

    ++(*this);
    return temp;
  }

  reverse_iterator& operator+=(difference_type n) {
    current_ -= n;
    return *this;
  }

  reverse_iterator operator-(difference_type n) const {
    return reverse_iterator(current_ + n);
  }

  reverse_iterator& operator--(void) {
    ++current_;
    return *this;
  }

  const reverse_iterator operator--(int) {
    const reverse_iterator temp = *this;
    --(*this);
    return temp;
  }

  reverse_iterator& operator-=(difference_type n) {
    current_ += n;
    return *this;
  }

  pointer operator->(void) const { return &(this->operator*()); }

  reference operator[](difference_type n) const { return current_[-n - 1]; }

 protected:
  iterator_type current_;
};

template <typename Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return (lhs.base() == rhs.base());
}

template <typename Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return (lhs.base() != rhs.base());
}

template <typename Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return (lhs.base() > rhs.base());
}

template <typename Iterator>
bool operator<=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return (lhs.base() >= rhs.base());
}

template <typename Iterator>
bool operator>(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return (lhs.base() < rhs.base());
}

template <typename Iterator>
bool operator>=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return (lhs.base() <= rhs.base());
}

template <typename Iterator>
reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& rev_it) {
  return rev_it + n;
}

template <typename Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs) {
  return rhs.base() - lhs.base();
}

template <typename InputIterator>
typename iterator_traits<InputIterator>::difference_type __distance(
    InputIterator first,
    InputIterator last,
    ft::input_iterator_tag) {
  typename ft::iterator_traits<InputIterator>::difference_type len(0);

  for (; first != last; ++first)
    ++len;
  return len;
}

template <typename InputIterator>
typename iterator_traits<InputIterator>::difference_type __distance(
    InputIterator first,
    InputIterator last,
    ft::random_access_iterator_tag) {
  return last - first;
}

template <typename InputIterator>
typename iterator_traits<InputIterator>::difference_type distance(
    InputIterator first, InputIterator last) {
  return ft::__distance(
    first,
    last,
    typename ft::iterator_traits<InputIterator>::iterator_category());
}
}  //  namespace ft
#endif  //  ITERATOR_HPP_
