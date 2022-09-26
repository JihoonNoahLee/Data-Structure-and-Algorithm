/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:16:01 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/26 15:20:34 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	del_back(t_list *list)
{
	t_node	*del_node;

	if (list->len == 0)
		return ;
	del_node = get_node_at(*list, list->len - 2);
	delone_node(del_node->next);
	del_node->next = NULL;
	list->len--;
}
