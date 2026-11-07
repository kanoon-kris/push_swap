/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:54:04 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/04 19:13:59 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

void	sa(t_list **a)
{
	if (swap(a))
		ft_putendl_fd("sa", 1);
}

void	sb(t_list **b)
{
	if (swap(b))
		ft_putendl_fd("sb", 1);
}

void	ss(t_list **a, t_list **b)
{
	bool	is_a_swapped;
	bool	is_b_swapped;

	is_a_swapped = swap(a);
	is_b_swapped = swap(b);
	if (is_a_swapped && is_b_swapped)
		ft_putendl_fd("ss", 1);
	else if (is_a_swapped)
		ft_putendl_fd("sa", 1);
	else if (is_b_swapped)
		ft_putendl_fd("sb", 1);
}
