/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_linked_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:37:01 by jihoolee          #+#    #+#             */
/*   Updated: 2022/09/29 14:13:27 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LINKED_LIST_H_
# define TEST_LINKED_LIST_H_

# include <stdio.h>
# include "linked_list.h"

void	print_list(t_list list);
void	test_add(t_list *list);
void	test_del(t_list *list);
void	test_access(t_list *list);
void	test_clear(t_list *list);

#endif
