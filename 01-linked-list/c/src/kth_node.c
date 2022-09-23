/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kth_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:48:30 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/23 16:53:50 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*kth_node(t_node *lst, int k)
{
	int		iter;

	if (lst == NULL)
		return (NULL);
	iter = 0;
	while (iter < k && lst != NULL)
	{
		lst = lst->next;
		iter++;
	}
	return (lst);
}