/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 02:06:56 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/12 00:06:53 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_lowest_to_top(t_context *ctx, int num_traversed_lowest_node,
int size_a)
{
	if ((2 * num_traversed_lowest_node) < size_a)
	{
		while (num_traversed_lowest_node != 0)
		{
			ra(ctx);
			--num_traversed_lowest_node;
		}
	}
	else
	{
		while ((size_a - num_traversed_lowest_node) != 0)
		{
			rra(ctx);
			++num_traversed_lowest_node;
		}
	}
}

static void	locate_lowest_rank(t_context *ctx, int *num_traversed_lowest_node)
{
	int		neighbor_rank;
	int		index;
	int		lowest_rank;
	t_list	*current_node;

	*num_traversed_lowest_node = 0;
	current_node = ctx->a;
	lowest_rank = get_rank(current_node);
	index = 0;
	while (current_node->next)
	{
		++index;
		neighbor_rank = get_rank(current_node->next);
		if (lowest_rank > neighbor_rank)
		{
			lowest_rank = neighbor_rank;
			*num_traversed_lowest_node = index;
		}
		current_node = current_node->next;
	}
}

void	simple_sort(t_context *ctx)
{
	int	size_a;
	int	num_traversed_lowest_node;

	if (ctx->mistake == 0)
		return ;
	size_a = (int) ft_lstsize(ctx->a);
	while (size_a > 3)
	{
		locate_lowest_rank(ctx, &num_traversed_lowest_node);
		rotate_lowest_to_top(ctx, num_traversed_lowest_node, size_a);
		pb(ctx);
		size_a = ft_lstsize(ctx->a);
	}
	sort_three(ctx);
	while (ft_lstsize(ctx->b) > 0)
		pa(ctx);
}
