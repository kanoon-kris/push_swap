/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_wrapper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:23:21 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/04 19:26:37 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

void	rra(t_list **a)
{
	if (reverse_rotate(a))
		ft_putendl_fd("rra", 1);
}

void	rrb(t_list **b)
{
	if (reverse_rotate(b))
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **a, t_list **b)
{
	bool	is_a_reverse_rotated;
	bool	is_b_reverse_rotated;

	is_a_reverse_rotated = reverse_rotate(a);
	is_b_reverse_rotated = reverse_rotate(b);
	if (is_a_reverse_rotated && is_b_reverse_rotated)
		ft_putendl_fd("rrr", 1);
	else if (is_a_reverse_rotated)
		ft_putendl_fd("rra", 1);
	else if (is_b_reverse_rotated)
		ft_putendl_fd("rrb", 1);
}
