/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:37:23 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/28 19:55:22 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "test_linked_list.h"

int	main(void)
{
	t_list	list;

	list.head = NULL;
	list.len = 0;
	add_front(&list, 1);
	add_front(&list, 2);
	add_front(&list, 3);
	add_front(&list, 4);
	add_front(&list, 5);
	print_list(list);
	return (0);
}
