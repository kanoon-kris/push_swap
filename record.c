/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:59:25 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/08 20:52:20 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Assume (int op) is a valid op-code.
// By the way, if (!ctx), then DO NOT dereference (ctx) in any possible way,
// please.
bool	record(t_context *ctx, int op)
{
	int		*log_code;
	t_list	*new_log;

	if (!ctx)
		return (false);
	log_code = malloc(sizeof(int));
	if ((ctx->is_failed) || (!log_code))
		return (free(log_code), (ctx->is_failed = true), false);
	*log_code = op;
	new_log = ft_lstnew(log_code);
	if (!new_log)
		return (free(log_code), (ctx->is_failed = true), false);
	if ((!ctx->op_log) && (!ctx->op_log_tail))
	{
		ctx->op_log = new_log;
		ctx->op_log_tail = new_log;
	}
	else
	{
		ctx->op_log_tail->next = new_log;
		ctx->op_log_tail = new_log;
	}
	return (true);
}
