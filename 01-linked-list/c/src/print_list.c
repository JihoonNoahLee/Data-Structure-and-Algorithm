/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:42:15 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/28 19:47:48 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_linked_list.h"

void	print_list(t_list list)
{
	t_node	*node;
	size_t	idx;

	idx = 0;
	node = list.head;
	while (node)
	{
		printf("list[%lu]: %d  ", idx, node->data);
		node = node->next;
		idx++;
	}
	printf("\ntotal length: %lu\n", list.len);
}
