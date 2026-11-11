/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:14:55 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/08 20:38:28 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_context *ctx)
{
	if ((ctx) && (push_top(&ctx->a, &ctx->b)))
		record(ctx, PA);
}

void	pb(t_context *ctx)
{
	if ((ctx) && (push_top(&ctx->b, &ctx->a)))
		record(ctx, PB);
}
