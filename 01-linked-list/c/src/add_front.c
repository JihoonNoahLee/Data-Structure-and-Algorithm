/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:42:41 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/23 16:45:24 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	add_front(t_node **head, int data)
{
	t_node	*new_node;

	if (head == NULL)
		return;
	new_node = create_node(data);
	if (new_node == NULL)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		new_node->next = *head;
		*head = new_node;
	}
}