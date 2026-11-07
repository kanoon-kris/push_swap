/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:14:55 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/04 19:17:00 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	if (push_top(a, b))
		ft_putendl_fd("pa", 1);
}

void	pb(t_list **b, t_list **a)
{
	if (push_top(b, a))
		ft_putendl_fd("pb", 1);
}
