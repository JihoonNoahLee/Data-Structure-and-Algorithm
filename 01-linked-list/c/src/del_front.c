/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:14:33 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/26 15:14:55 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	del_front(t_list *list)
{
	t_node	*del_node;

	if (list->len == 0)
		return ;
	del_node = list->head;
	list->head = del_node->next;
	delone_node(del_node);
	list->len--;
}
