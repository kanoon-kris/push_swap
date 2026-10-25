/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:57:57 by kboonkos          #+#    #+#             */
/*   Updated: 2026/10/26 01:17:44 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

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
	top->next = NULL;
	*lst = (*lst)->next;
	return (top);
}

int	peek(t_list *lst)
{
	return (lst->content->value);
}

bool	is_empty(t_list *lst)
{
	return ((lst != NULL) && (*lst != NULL));
}
