/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:33:07 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/13 23:56:17 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// Chunk sort as medium strategy!

// k is the number of numbers per chunk.
static void	push_chunk_to_b(t_context *ctx, int upper_bound, int k)
{
	int	count;

	count = 0;
	while (!is_empty(ctx->a) && (count < k))
	{
		if (get_rank(ctx->a) <= upper_bound)
		{
			pb(ctx);
			++count;
		}
		else
		{
			ra(ctx);
		}
	}
}

// resulting_idx is the proximity of a node with the highest rank to top of 'b'.
static int	locate_highest_rank_in_b(t_context *ctx)
{
	t_list	*curr_node;
	int		idx;
	int		highest_rank;
	int		neighbor_rank;
	int		resulting_idx;

	curr_node = ctx->b;
	idx = 0;
	resulting_idx = 0;
	highest_rank = get_rank(curr_node);
	while (curr_node->next)
	{
		neighbor_rank = get_rank(curr_node->next);
		if (highest_rank < neighbor_rank)
		{
			highest_rank = neighbor_rank;
			resulting_idx = idx + 1;
		}
		++idx;
		curr_node = curr_node->next;
	}
	return (resulting_idx);
}

// Knowing size of 'b' can determine if ra or rra is the shortest.
static void	bring_rank_top_b(t_context *ctx, int position, int size_b)
{
	if ((2 * position) > size_b)
	{
		while (position != size_b)
		{
			rrb(ctx);
			++position;
		}
	}
	else
	{
		while (position != 0)
		{
			rb(ctx);
			--position;
		}
	}
}

// To push everthing to b based on chunk sort algorithm.
static void	push_all_b(t_context *ctx, int k, int size_a)
{
	int	curr_chunk;
	int	rank_bound;

	curr_chunk = 0;
	while (curr_chunk < k)
	{
		rank_bound = (curr_chunk + 1) * k - 1;
		if ((curr_chunk + 1 == k) && (k * k > size_a))
			rank_bound -= (k * k) - size_a;
		push_chunk_to_b(ctx, rank_bound, k);
		++curr_chunk;
	}
}

// Actually, the edge case computation is unneccessary since there is a guard
// in push_chunk_to_b(), (!is_empty(ctx->a).
bool	medium_sort(t_context *ctx)
{
	int	size_a;
	int	k;
	int	size_b;

	if (!ctx)
		return (false);
	if (ctx->mistake == 0)
		return (true);
	size_a = ft_lstsize(ctx->a);
	k = 1;
	while ((k * k) < size_a)
		++k;
	push_all_b(ctx, k, size_a);
	size_b = ft_lstsize(ctx->b);
	while (!is_empty(ctx->b))
	{
		bring_rank_top_b(ctx, locate_highest_rank_in_b(ctx), size_b);
		pa(ctx);
		--size_b;
	}
	return (true);
}
