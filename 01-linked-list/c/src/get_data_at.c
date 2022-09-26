/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:34:31 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/26 14:46:55 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	get_data_at(t_list list, size_t idx)
{
	t_node	*node;

	node = get_node_at(list, idx);
	if (node == NULL)
		return (0);
	return (node->data);
}
