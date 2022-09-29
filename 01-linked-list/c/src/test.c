/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:49:06 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/29 14:17:48 by jihoolee         ###   ########.fr       */
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


void	test_add(t_list *list)
{
	printf("====================\n");
	printf("add_front test\n");
	add_front(list, 1);
	add_front(list, 2);
	print_list(*list);
	printf("\nadd_back test\n");
	add_back(list, 3);
	add_back(list, 4);
	add_back(list, 5);
	print_list(*list);
	printf("\nadd_at test\n");
	add_at(list, 0, 0);
	add_at(list, 7, 2);
	add_at(list, 8, list->len);
	print_list(*list);
	printf("====================\n");
}

void	test_del(t_list *list)
{
	printf("====================\n");
	printf("del_front test\n");
	del_front(list);
	print_list(*list);
	printf("\ndel_back test\n");
	del_back(list);
	print_list(*list);
	printf("\ndel_at test\n");
	del_at(list, 0);
	del_at(list, 2);
	del_at(list, list->len - 1);
	print_list(*list);
	printf("====================\n");
}

void	test_access(t_list *list)
{
	printf("====================\n");
	printf("get_node_at test\n");
	print_list(*list);
	printf("NULL returend if index out of range\n");
	printf("list[0]: %d\n", get_node_at(*list, 0)->data);
	printf("list[2]: %d\n", get_node_at(*list, 2)->data);
	printf("list[4]: %p\n", get_node_at(*list, 4));
	printf("\nget_data_at test\n");
	print_list(*list);
	printf("0 returned if index out of range\n");
	printf("list[0]: %d\n", get_data_at(*list, 0));
	printf("list[2]: %d\n", get_data_at(*list, 2));
	printf("list[4]: %d\n", get_data_at(*list, 4));
	printf("\nfind_node test\n");
	print_list(*list);
	printf("NULL returned if data not found\n");
	printf("find_node(*list, 0): %p\n", find_node(*list, 0));
	printf("find_node(*list, 1): %p\n", find_node(*list, 1));
	printf("find_node(*list, 2): %p\n", find_node(*list, 2));
	printf("\nfind_idx test\n");
	print_list(*list);
	printf("list.len returned if data not found\n");
	printf("find_idx(*list, 0): %lu\n", find_idx(*list, 0));
	printf("find_idx(*list, 1): %lu\n", find_idx(*list, 1));
	printf("find_idx(*list, 2): %lu\n", find_idx(*list, 2));
	printf("find_idx(*list, 4): %lu\n", find_idx(*list, 4));
	printf("====================\n");
}

void	test_clear(t_list *list)
{
	printf("====================\n");
	printf("clear_list test\n");
	printf("before clear_list\n");
	print_list(*list);
	clear_list(list);
	printf("\nafter clear_list\n");
	print_list(*list);
	printf("====================\n");
}
