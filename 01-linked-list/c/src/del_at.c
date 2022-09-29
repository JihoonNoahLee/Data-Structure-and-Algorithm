/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:21:52 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/29 13:45:07 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	del_at(t_list *list, size_t idx)
{
	t_node	*del_node;
	t_node	*prev_node;

	if (list == NULL)
		return ;
	if (idx == 0)
		del_front(list);
	else if (idx == list->len - 1)
		del_back(list);
	else
	{
		prev_node = get_node_at(*list, idx - 1);
		del_node = prev_node->next;
		prev_node->next = del_node->next;
		delone_node(del_node);
		list->len--;
	}
}
