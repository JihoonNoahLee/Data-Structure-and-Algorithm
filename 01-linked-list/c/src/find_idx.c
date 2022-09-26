/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:39:52 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/26 14:55:23 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

size_t	find_idx(t_list list, int data)
{
	t_node	*node;
	size_t	iter;

	node = list.head;
	iter = 0;
	while (iter < list.len)
	{
		if (node->data == data)
			return (iter);
		node = node->next;
		iter++;
	}
	return (list.len);
}
