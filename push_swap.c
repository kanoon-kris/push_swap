/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:23:10 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/13 21:42:17 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	run_strategy(t_context *ctx)
{
	if (ctx->resolved_strategy == SIMPLE)
		simple_sort(ctx);
	else if (ctx->resolved_strategy == MEDIUM)
		medium_sort(ctx);
	else
		return (true);
	return (true);
}

static bool	select_strategy(t_context *ctx)
{
	long long	mistake;
	long long	total_pair;

	mistake = ctx->mistake;
	total_pair = ctx->total_pair;
	if (ctx->flags.strategy != ADAPTIVE)
		ctx->resolved_strategy = ctx->flags.strategy;
	else if ((total_pair == 0) || ((5 * mistake) < total_pair))
		ctx->resolved_strategy = SIMPLE;
	else if (2 * mistake < total_pair)
		ctx->resolved_strategy = MEDIUM;
	else
		ctx->resolved_strategy = COMPLEX;
	return (true);
}

static bool	process_input(int argc, char **argv, t_context *ctx)
{
	int		*num_buf;
	int		count;
	t_list	*a;

	num_buf = ft_calloc(sizeof(int), (argc - 1));
	if (!num_buf)
		return (ft_putendl_fd("Error", 2), false);
	count = parse_valid_int_string_with_flags(argc, argv, &ctx->flags, num_buf);
	a = NULL;
	if ((count == -1) || (initialize_stack(&a, count, num_buf) == -1))
		return (ft_putendl_fd("Error", 2), free(num_buf), false);
	ctx->a = a;
	return (free(num_buf), true);
}

int	main(int argc, char **argv)
{
	t_context	ctx;

	if (argc == 1)
		return (0);
	ft_bzero(&ctx, sizeof(t_context));
	if (!process_input(argc, argv, &ctx))
		return (1);
	compute_disorder(&ctx);
	if (!select_strategy(&ctx) || (!run_strategy(&ctx)) || ctx.is_failed)
		return (ft_putendl_fd("Error", 2), context_clear(&ctx), 1);
	print_log(ctx.op_log);
	if (ctx.flags.bench)
		print_bench(&ctx);
	return (context_clear(&ctx), 0);
}
