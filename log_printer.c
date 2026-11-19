/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 21:58:39 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/10 17:07:29 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// Lookup table is an array of strings.
// Its positions nicely match enum valuess.
// This eliminates if/else branches, entirely.
void	print_log(t_list *op_log)
{
	const char	*op_names[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	if (!op_log)
		return ;
	while (op_log)
	{
		ft_putendl_fd((char *)op_names[*(int *)op_log->content], 1);
		op_log = op_log->next;
	}
}
