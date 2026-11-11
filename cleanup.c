/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:06:57 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/09 01:25:50 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// Note that only the code allocated the struct should free it.
// main() is responsible for this.
bool	context_clear(t_context *ctx)
{
	if (!ctx)
		return (false);
	ft_lstclear(&ctx->a, free);
	ft_lstclear(&ctx->b, free);
	ft_lstclear(&ctx->op_log, free);
	ctx->op_log_tail = NULL;
	return (true);
}
