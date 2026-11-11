/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_wrapper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:23:21 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/08 20:51:50 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// WARNING: NULL IS NEVER ALLOWED, HERE.

void	rra(t_context *ctx)
{
	if ((ctx) && (reverse_rotate(&ctx->a)))
		record(ctx, RRA);
}

void	rrb(t_context *ctx)
{
	if ((ctx) && (reverse_rotate(&ctx->b)))
		record(ctx, RRB);
}

void	rrr(t_context *ctx)
{
	bool	is_a_rev_rotated;
	bool	is_b_rev_rotated;

	if (ctx)
	{
		is_a_rev_rotated = reverse_rotate(&ctx->a);
		is_b_rev_rotated = reverse_rotate(&ctx->b);
		if ((is_a_rev_rotated) && (is_b_rev_rotated))
			record(ctx, RRR);
		else if (is_a_rev_rotated)
			record(ctx, RRA);
		else if (is_b_rev_rotated)
			record(ctx, RRB);
	}
}
