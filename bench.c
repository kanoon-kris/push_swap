/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:07:57 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/11 00:42:04 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// This source is for --bench.
// Note that global varibles are strictly forbidden in this project so multiple
// tables are preset.

// Two arguments in case of the adaptive strategy.
static void	print_strategy_complexity(t_strategy requested,
t_strategy resolved_strategy)
{
	const char	*strategy_table[STRATEGY_COUNT] = {"Unset", "Simple", "Medium",
		"Complex", "Adaptive"};
	const char	*complexity_table[STRATEGY_COUNT] = {"Unset", "n^2",
		"n sqrt(n)", "n log n", "UNUSED SLOT"};

	if ((requested >= STRATEGY_COUNT) || (resolved_strategy >= ADAPTIVE))
	{
		ft_putendl_fd("Invalid strategy or complexity", 2);
		return ;
	}
	ft_putstr_fd((char *)strategy_table[requested], 2);
	ft_putstr_fd(" / O(", 2);
	ft_putstr_fd((char *)complexity_table[resolved_strategy], 2);
	ft_putendl_fd(")", 2);
}

// Reset all counters here
bool	op_count(t_context *ctx)
{
	t_list	*log_node;
	int		i;

	if (!ctx)
		return (false);
	i = 0;
	while (i < OP_COUNT)
		ctx->count[i++] = 0;
	log_node = ctx->op_log;
	while (log_node)
	{
		++ctx->count[*(int *)log_node->content];
		log_node = log_node->next;
	}
	ctx->total_ops = 0;
	i = 0;
	while (i < OP_COUNT)
		ctx->total_ops += ctx->count[i++];
	return (true);
}

// Global variables are strictly forbidden for push_swap so multiple local
// tables are a must.
static void	print_ops(t_context *ctx)
{
	const char	*op_names[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	ft_putstr_fd("[bench] ", 2);
	i = 0;
	while (i <= RRR)
	{
		ft_putstr_fd((char *)op_names[i], 2);
		ft_putstr_fd(":  ", 2);
		ft_putnbr_fd(ctx->count[i], 2);
		if (i == PB)
		{
			ft_putstr_fd("\n[bench] ", 2);
		}
		else if (i == RRR)
			break ;
		else
			ft_putstr_fd("  ", 2);
		++i;
	}
	ft_putendl_fd("", 2);
}

bool	print_bench(t_context *ctx)
{
	if (!ctx)
		return (false);
	ft_putstr_fd("[bench] disorder:  ", 2);
	print_disorder(ctx->disorder);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench] strategy:  ", 2);
	print_strategy_complexity(ctx->flags.strategy, ctx->resolved_strategy);
	op_count(ctx);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(ctx->total_ops, 2);
	ft_putendl_fd("", 2);
	print_ops(ctx);
	return (true);
}
