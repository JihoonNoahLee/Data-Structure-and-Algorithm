/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:08:13 by jihoolee          #+#    #+#             */
/*   Updated: 2022/10/07 01:20:04 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP_
# define QUEUE_HPP_

#include <deque>

namespace ft {
template <typename T, typename Container = std::deque<T> >
class queue {
 public:
  typedef Container                                 container_type;
  typedef typename container_type::value_type       value_type;
  typedef typename container_type::reference        reference;
  typedef typename container_type::const_reference  const_reference;
  typedef typename container_type::size_type        size_type;

  explicit queue(const container_type& ctnr = container_type()): c(ctnr) {}

  virtual ~queue(void) {}

  bool empty(void) const { return c.empty(); }

  size_type size(void) const { return c.size(); }

  reference front(void) { return c.front(); }

  const_reference front(void) const { return c.front(); }

  reference back(void) { return c.back(); }

  const_reference back(void) const { return c.back(); }

  void push(const value_type& val) { c.push_back(val); }

  void push(value_type&& val) { c.push_back(val); }

  void pop(void) { c.pop_front(); }

  void swap(queue& other) { c.swap(other.c); }

  template <typename T_, typename Container_>
  friend bool operator==(const queue<T_, Container_>& lhs,
                         const queue<T_, Container_>& rhs);

  template <typename T_, typename Container_>
  friend bool operator<(const queue<T_, Container_>& lhs,
                         const queue<T_, Container_>& rhs);

 protected:
  container_type  c;
};  //  class queue

template <typename T, typename Container>
bool operator==(const ft::queue<T, Container>& lhs,
                const ft::queue<T, Container>& rhs) {
  return lhs.c == rhs.c;
}

template <typename T, typename Container>
bool operator!=(const ft::queue<T, Container>& lhs,
                const ft::queue<T, Container>& rhs) {
  return !(lhs == rhs);
}

template <typename T, typename Container>
bool operator<(const ft::queue<T, Container>& lhs,
               const ft::queue<T, Container>& rhs) {
  return lhs.c < rhs.c;
}

template <typename T, typename Container>
bool operator<=(const ft::queue<T, Container>& lhs,
                const ft::queue<T, Container>& rhs) {
  return !(rhs < lhs);
}

template <typename T, typename Container>
bool operator>(const ft::queue<T, Container>& lhs,
               const ft::queue<T, Container>& rhs) {
  return rhs < lhs;
}

template <typename T, typename Container>
bool operator>=(const ft::queue<T, Container>& lhs,
                const ft::queue<T, Container>& rhs) {
  return !(lhs < rhs);
}
}  //  namespace ft

#endif  //  QUEUE_HPP_
