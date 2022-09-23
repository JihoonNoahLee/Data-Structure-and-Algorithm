/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:57:41 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/23 16:48:08 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>

typedef struct	s_node
{
  int			data;
  struct s_node	*next;
}	t_node;

//❎
/*
** to_implement: 
– Adding an element at the kth position
- Adding an element at the beginning ✅
- Adding an element at the end       ✅
- Accessing an element
- Deleting an element at the kth position
*/

/*
** Adding and deleting node
*/
t_node	*create_node(int data);
void    delone_node(t_node *node);

/*
** iterating thorugh the list
*/
t_node	*last_node(t_node *node);
t_node  *kth_node(t_node *node, int k);

/*
** inserting node into list
*/
void  add_front(t_node **head, int data);
void	add_back(t_node **head, int data);
void  add_kth(t_node **head, int data, int k);

#endif