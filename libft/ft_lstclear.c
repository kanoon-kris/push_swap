/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 05:18:21 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/15 04:28:34 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	while (*lst)
	{
		next_node = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = next_node;
	}
	*lst = NULL;
}
