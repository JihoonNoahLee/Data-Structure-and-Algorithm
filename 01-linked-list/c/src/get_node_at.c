/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:31:52 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/26 14:46:04 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*get_node_at(t_list list, size_t idx)
{
	t_node	*node;
	size_t	i;

	if (idx >= list.len)
		return (NULL);
	node = list.head;
	i = 0;
	while (i < idx)
	{
		node = node->next;
		i++;
	}
	return (node);
}
