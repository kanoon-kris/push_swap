/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 21:00:33 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/10 22:26:43 by kboonkos         ###   ########.fr       */
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

// To parse only string with correct format with duplicate check.
// If flags are faulty or duplicated, return (-1); otherwise,
// return the number of numerical values--zero number of numbers is valid.
// Assuming arguments of the program means numerical values,
// when only two flags are given, it should produce nothing,
// so that is the reason `while (i < (argc))` was written that way.
int	parse_valid_int_string_with_flags(int argc, char **argv,
t_flag *flag, int *num_buf)
{
	int	i;
	int	count;

	i = 1;
	while (i < (argc))
	{
		if ((!flag->bench) && (!ft_strcmp(argv[i], "--bench")))
			flag->bench = true;
		else if ((which_strategy_flag(argv[i]) != UNSET)
			&& (flag->strategy == UNSET))
			flag->strategy = which_strategy_flag(argv[i]);
		else
			break ;
		++i;
	}
	count = 0;
	while (i <= (argc - 1))
		if (!parse_int(argv[i++], &num_buf[count++]))
			return (-1);
	if (flag->strategy == UNSET)
		flag->strategy = ADAPTIVE;
	if (!is_duplicated(count, num_buf))
		return (count);
	return (-1);
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
int	initialize_stack(t_list **lst, int count, int *num_buf)
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
			return (ft_lstclear(lst, free), -1);
		ft_lstadd_back(lst, node);
		++i;
	}
	return (1);
}
