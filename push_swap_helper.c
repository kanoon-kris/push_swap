/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 02:03:32 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/08 20:19:11 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// In case of these helpers:
//     - true implies performed operation(s),
//	   - false implies no operations performed.	

bool	push_top(t_list **dst, t_list **src)
{
	if (!dst || !src || is_empty(*src))
		return (false);
	push(dst, pop(src));
	return (true);
}

bool	swap(t_list **lst)
{
	t_list	*first_node;
	t_list	*second_node;

	if (!lst || !*lst || (!(*lst)->next))
		return (false);
	first_node = pop(lst);
	second_node = pop(lst);
	push(lst, first_node);
	push(lst, second_node);
	return (true);
}

bool	rotate(t_list **lst)
{
	t_list	*first_node;

	if (!lst || !*lst || (!(*lst)->next))
		return (false);
	first_node = pop(lst);
	ft_lstadd_back(lst, first_node);
	return (true);
}

bool	reverse_rotate(t_list **lst)
{
	t_list	*second_last_node;

	if (!lst || !*lst || (!(*lst)->next))
		return (false);
	second_last_node = *lst;
	while (second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	ft_lstadd_front(lst, second_last_node->next);
	second_last_node->next = NULL;
	return (true);
}
