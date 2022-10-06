/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:12:22 by jihoolee          #+#    #+#             */
/*   Updated: 2022/10/07 01:20:50 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "queue.hpp"

void test_queue(void)
{
  ft::queue<int>	q;

  std::cout << "***************************************" << std::endl;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  std::cout << "front: " << q.front() << std::endl;
  std::cout << "back: " << q.back() << std::endl;
  std::cout << "size: " << q.size() << std::endl;
  std::cout << "empty: " << q.empty() << std::endl;
  std::cout << "***************************************" << std::endl;
  q.pop();
  std::cout << "front: " << q.front() << std::endl;
  std::cout << "back: " << q.back() << std::endl;
  std::cout << "size: " << q.size() << std::endl;
  std::cout << "empty: " << q.empty() << std::endl;
  std::cout << "***************************************" << std::endl;
}

void test_queue_relational_operators(void)
{
  ft::queue<int>	q1;
  ft::queue<int>	q2;

  std::cout << "***************************************" << std::endl;
  q1.push(1);
  q1.push(2);
  q1.push(3);
  q2.push(1);
  q2.push(2);
  q2.push(3);
  std::cout << "q1 == q2: " << (q1 == q2) << std::endl;
  std::cout << "q1 < q2: " << (q1 < q2) << std::endl;
  q2.push(4);
  std::cout << "***************************************" << std::endl;
  std::cout << "q1 == q2: " << (q1 == q2) << std::endl;
  std::cout << "q1 < q2: " << (q1 < q2) << std::endl;
  std::cout << "***************************************" << std::endl;
}

int main(void) {
  test_queue();
  test_queue_relational_operators();
  return 0;
}
