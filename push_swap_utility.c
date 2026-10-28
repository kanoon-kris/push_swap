/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 02:03:32 by kboonkos          #+#    #+#             */
/*   Updated: 2026/10/26 02:54:07 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_list **dst, t_list **src)
{
	push(dst, pop(src));
}

void	s(t_list **lst)
{
	t_list	*temp;
	t_list	*temp02;

	temp = pop(lst);
	temp02 = pop(lst);
	push(lst, temp);
	push(lst, temp02);
}

void	r(t_list **lst)
{
	t_list	*temp;

	temp = pop(lst);
	ft_lstadd_last(lst, temp);
}

void	rr(t_list **dst, t_list **src)
{
}
