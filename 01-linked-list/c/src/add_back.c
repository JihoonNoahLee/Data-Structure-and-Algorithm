/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:43:53 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/26 15:00:35 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	add_back(t_list *list, int data)
{
	t_node  *new_node;
	t_node  *last_node;

	new_node = create_node(data);
	if (list->len == 0)
		list->head = new_node;
	else
	{
		last_node = get_node(list, list->len - 1);
		last_node->next = new_node;
	}
	list->len++;
}
