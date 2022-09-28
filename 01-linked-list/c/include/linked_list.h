/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:57:41 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/28 19:50:52 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	size_t	len;
}	t_list;

/*
** adding and deleting node
*/
t_node	*create_node(int data);
void	delone_node(t_node *node);
void	clear_list(t_list *list);

/*
** accessing node
*/
t_node	*get_node_at(t_list list, size_t idx);
int		get_data_at(t_list list, size_t idx);
t_node	*find_node(t_list list, int data);
size_t	find_idx(t_list list, int data);

/*
** inserting node into list
*/
void	add_front(t_list *list, int data);
void	add_back(t_list *list, int data);
void	add_at(t_list *list, int data, size_t idx);

/*
** deleting node from list
*/
void	del_front(t_list *list);
void	del_back(t_list *list);
void	del_at(t_list *list, size_t idx);

#endif
