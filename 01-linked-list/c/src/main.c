/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:37:23 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/29 14:18:57 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "test_linked_list.h"

int	main(void)
{
	t_list	list;

	list.head = NULL;
	list.len = 0;
	test_add(&list);
	test_del(&list);
	test_access(&list);
	test_clear(&list);
	return (0);
}
