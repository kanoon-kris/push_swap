/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_wrapper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:19:06 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/04 19:22:09 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

void	ra(t_list **a)
{
	if (rotate(a))
		ft_putendl_fd("ra", 1);
}

void	rb(t_list **b)
{
	if (rotate(b))
		ft_putendl_fd("rb", 1);
}

void	rr(t_list **a, t_list **b)
{
	bool	is_a_rotated;
	bool	is_b_rotated;

	is_a_rotated = rotate(a);
	is_b_rotated = rotate(b);
	if (is_a_rotated && is_b_rotated)
		ft_putendl_fd("rr", 1);
	else if (is_a_rotated)
		ft_putendl_fd("ra", 1);
	else if (is_b_rotated)
		ft_putendl_fd("rb", 1);
}
