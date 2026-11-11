/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:39:58 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/11 02:01:29 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small(t_context *ctx, int size)
{
	if (size < 2)
		return ;
	if (get_rank(ctx->a) > get_rank(ctx->a->next))
		sa(ctx);
}

static void	swap_top_if_unordered(t_context *ctx)
{
	sort_small(ctx, 2);
}

void	sort_three(t_context *ctx)
{
	int	top;
	int	mid;
	int	bot;
	int	size;

	if (!ctx)
		return ;
	size = (int) ft_lstsize(ctx->a);
	if (size <= 2)
	{
		sort_small(ctx, size);
		return ;
	}
	top = get_rank(ctx->a);
	mid = get_rank(ctx->a->next);
	bot = get_rank(ctx->a->next->next);
	if ((top > mid) && (top > bot))
		ra(ctx);
	else if (mid > bot)
		rra(ctx);
	swap_top_if_unordered(ctx);
}
