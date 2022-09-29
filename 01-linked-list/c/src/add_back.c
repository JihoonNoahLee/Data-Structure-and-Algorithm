/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:43:53 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/29 13:44:07 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	add_back(t_list *list, int data)
{
	t_node	*new_node;
	t_node	*last_node;

	if (list == NULL)
		return ;
	new_node = create_node(data);
	if (new_node == NULL)
		return;
	if (list->len == 0)
		list->head = new_node;
	else
	{
		last_node = get_node_at(*list, list->len - 1);
		if (last_node == NULL)
			return;
		last_node->next = new_node;
	}
	list->len++;
}
