/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 21:00:33 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/20 02:22:34 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// Simple duplicate check for an integer array.
bool	is_duplicated(int count, int *num_buf)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (num_buf[i] == num_buf[j])
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

// Check the enumerator in the header file.
int	which_strategy_flag(const char *str)
{
	if (!ft_strcmp(str, "--simple"))
		return (SIMPLE);
	else if (!ft_strcmp(str, "--medium"))
		return (MEDIUM);
	else if (!ft_strcmp(str, "--complex"))
		return (COMPLEX);
	else if (!ft_strcmp(str, "--adaptive"))
		return (ADAPTIVE);
	return (UNSET);
}

// To create a complete node by passing value and rank to payload helper.
t_list	*create_node(int value, int rank)
{
	t_list		*node;
	t_payload	*payload;

	payload = parse_payload(value, rank);
	if (!payload)
		return (NULL);
	node = ft_lstnew(payload);
	if (!node)
		return (free(payload), NULL);
	return (node);
}

// A rank is how many numbers smaller than another number.
bool	initialize_stack(t_list **lst, int count, int *num_buf)
{
	int			i;
	int			j;
	int			rank;
	t_list		*node;

	i = 0;
	while (i < count)
	{
		rank = 0;
		j = 0;
		while (j < count)
		{
			if (num_buf[i] > num_buf[j])
				++rank;
			++j;
		}
		node = create_node(num_buf[i], rank);
		if (!node)
			return (ft_lstclear(lst, free), false);
		ft_lstadd_back(lst, node);
		++i;
	}
	return (true);
}
