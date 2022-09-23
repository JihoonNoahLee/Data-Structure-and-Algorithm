/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:13:23 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/23 16:17:26 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*last_node(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}