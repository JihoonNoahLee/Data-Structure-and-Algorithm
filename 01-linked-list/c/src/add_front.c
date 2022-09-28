/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:42:41 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/28 19:54:31 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	add_front(t_list *list, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (new_node == NULL)
		return;
	new_node->next = list->head;
	list->head = new_node;
	list->len++;
}
