/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:54:04 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/08 20:35:11 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// WARNING: (ctx->is_failed) MUST BE HANDLED BY record() ONLY.

// Basically, if ctx is not NULL and the SA has been performed,
// then record SA. The same applies to others wrappers, as well.
void	sa(t_context *ctx)
{
	if ((ctx) && (swap(&ctx->a)))
		record(ctx, SA);
}

void	sb(t_context *ctx)
{
	if ((ctx) && (swap(&ctx->b)))
		record(ctx, SB);
}

void	ss(t_context *ctx)
{
	bool	is_a_swapped;
	bool	is_b_swapped;

	if (ctx)
	{
		is_a_swapped = swap(&ctx->a);
		is_b_swapped = swap(&ctx->b);
		if ((is_a_swapped) && (is_b_swapped))
			record(ctx, SS);
		else if (is_a_swapped)
			record(ctx, SA);
		else if (is_b_swapped)
			record(ctx, SB);
	}
}
