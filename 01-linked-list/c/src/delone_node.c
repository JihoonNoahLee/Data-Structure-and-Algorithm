/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delone_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:06:05 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/26 22:10:26 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	delone_node(t_node *node)
{
	if (node == NULL)
		return ;
	free(node);
}
