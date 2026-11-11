/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:55:49 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/11 00:08:23 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// h means hundredths
void	print_disorder(long long h)
{
	long long	immediate;

	immediate = h / 100;
	ft_putnbr_fd(immediate, 2);
	ft_putstr_fd(".", 2);
	immediate = h % 100;
	if (immediate < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(immediate, 2);
	ft_putstr_fd("%", 2);
}

void	compute_mistake_and_total_pair(t_list *lst, long long *mistake,
long long *total_pair)
{
	t_list		*anchor;
	t_list		*runner;

	*mistake = 0;
	*total_pair = 0;
	if (!lst)
		return ;
	anchor = lst;
	while (anchor->next)
	{
		runner = anchor->next;
		while (runner)
		{
			++*total_pair;
			if (get_rank(anchor) > get_rank(runner))
				++*mistake;
			runner = runner->next;
		}
		anchor = anchor->next;
	}
}

// Disorder is computed in (`long long`) integers. The intermediate value,
// (10000m) cannot overflow for any input a command line can carry.
// The limit is about 43 million elements.
void	compute_disorder(t_context *ctx)
{
	long long	mistake;
	long long	total_pair;

	if (!ctx)
		return ;
	compute_mistake_and_total_pair(ctx->a, &ctx->mistake, &ctx->total_pair);
	mistake = ctx->mistake;
	total_pair = ctx->total_pair;
	if (ctx->total_pair < 1)
		ctx->disorder = 0;
	else
		ctx->disorder = (10000 * mistake + total_pair / 2) / total_pair;
}
