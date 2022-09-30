/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:01:50 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/30 15:57:06 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	add_at(t_list *list, int data, size_t idx)
{
	t_node	*new_node;
	t_node	*prev_node;

	if (list == NULL)
		return ;
	if (idx == 0)
		add_front(list, data);
	else if (idx == list->len)
		add_back(list, data);
	else
	{
		new_node = create_node(data);
		if (new_node == NULL)
			return ;
		prev_node = get_node_at(*list, idx - 1);
		new_node->next = prev_node->next;
		prev_node->next = new_node;
		list->len++;
	}
}
