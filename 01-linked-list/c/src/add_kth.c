/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_kth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:47:16 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/23 17:01:51 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	add_kth(t_node **head, int data, int k)
{
	t_node	*new_node;
	t_node	*prev_node;
	t_node	*next_node;
	int		i;

	if (head == NULL)
		return ;
	new_node = create_node(data);
	if (new_node == NULL)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		prev_node = *head;
		next_node = prev_node->next;
		i = 0;
		while (i < k - 1 && next_node != NULL)
		{
			prev_node = next_node;
			next_node = prev_node->next;
			i++;
		}
		prev_node->next = new_node;
		new_node->next = next_node;
	}
}