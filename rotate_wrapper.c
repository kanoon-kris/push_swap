/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_wrapper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:19:06 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/08 20:51:22 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// WARNING: NULL IS NEVER ALLOWED, HERE.

void	ra(t_context *ctx)
{
	if ((ctx) && (rotate(&ctx->a)))
		record(ctx, RA);
}

void	rb(t_context *ctx)
{
	if ((ctx) && (rotate(&ctx->b)))
		record(ctx, RB);
}

void	rr(t_context *ctx)
{
	bool	is_a_rotated;
	bool	is_b_rotated;

	if (ctx)
	{
		is_a_rotated = rotate(&ctx->a);
		is_b_rotated = rotate(&ctx->b);
		if ((is_a_rotated) && (is_b_rotated))
			record(ctx, RR);
		else if (is_a_rotated)
			record(ctx, RA);
		else if (is_b_rotated)
			record(ctx, RB);
	}
}
