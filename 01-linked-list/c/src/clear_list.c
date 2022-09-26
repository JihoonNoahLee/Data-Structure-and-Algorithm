/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:40:38 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/26 14:41:26 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	clear_list(t_list *list)
{
	t_node	*node;
	t_node	*next;

	node = list->head;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	list->head = NULL;
	list->len = 0;
}
