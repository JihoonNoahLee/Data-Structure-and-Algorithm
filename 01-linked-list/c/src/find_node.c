/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:37:38 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/29 13:48:20 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

/*
** find_node returns the first node that has the same value
** returns NULL if not found
*/

t_node	*find_node(t_list list, int data)
{
	t_node	*node;
	size_t	iter;

	node = list.head;
	iter = 0;
	while (iter < list.len)
	{
		if (node->data == data)
			return (node);
		node = node->next;
		iter++;
	}
	return (NULL);
}
