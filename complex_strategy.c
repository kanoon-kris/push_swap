/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:04:08 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/17 01:04:28 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// The mistake pair check at the runner guarantees size at least 2.
static int	calculate_max_bit(int size)
{
	unsigned int	max_bit;
	unsigned int	unsigned_size;

	max_bit = 0;
	unsigned_size = (unsigned int) size;
	while (((unsigned_size - 1) >> max_bit) != 0)
		++max_bit;
	return ((int) max_bit);
}

static void	one_pass(t_context *ctx, int bit, int size)
{
	unsigned int	mask;
	int				num_looked_at;
	int				count_stack_b;

	mask = 1u << ((unsigned int) bit);
	count_stack_b = 0;
	num_looked_at = 0;
	while (num_looked_at < (size))
	{
		if (((unsigned int) get_rank(ctx->a) & mask) == 0)
		{
			pb(ctx);
			++count_stack_b;
		}
		else
			ra(ctx);
		++num_looked_at;
	}
	while (count_stack_b != 0)
	{
		pa(ctx);
		--count_stack_b;
	}
}

bool	complex_sort(t_context *ctx)
{
	int	size;
	int	max_bit;
	int	bit_position;

	if (!ctx)
		return (false);
	if (ctx->mistake == 0)
		return (true);
	size = ft_lstsize(ctx->a);
	max_bit = calculate_max_bit(size);
	bit_position = 0;
	while (bit_position < max_bit)
	{
		one_pass(ctx, bit_position, size);
		++bit_position;
	}
	return (true);
}
