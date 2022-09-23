/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:43:53 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/23 16:44:13 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	add_back(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*last;

	new_node = create_node(data);
	if (new_node == NULL)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last = last_node(*head);
		last->next = new_node;
	}
}