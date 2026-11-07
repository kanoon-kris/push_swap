/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:57:57 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/04 18:39:40 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

// Alike ft_lstadd_front, this is to preseve a perspective of stack structure.
// `*lst` can be NULL when the stack is empty.
void	push(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*pop(t_list **lst)
{
	t_list	*top;

	if (!lst || !*lst)
		return (NULL);
	top = *lst;
	*lst = (*lst)->next;
	top->next = NULL;
	return (top);
}

// The parameter is unguarded.
int	peek(t_list *lst)
{
	return (lst->content->value);
}

// To check if a given lst is empty.
bool	is_empty(t_list *lst)
{
	return (lst == NULL);
}
