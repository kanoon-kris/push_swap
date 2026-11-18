/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmansak <pmansak@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:56:02 by pmansak           #+#    #+#             */
/*   Updated: 2026/11/18 21:05:23 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>

// The `flag` struct must be zeroed before the call. `ft_bzero` to ctx does
// the job.
// When the function returns false, the flag struct may be partly filled but
// that does not matter, as long as the caller treat false as an error and
// does not use the struct afterward.
// The function assumes that flags must be placed before any valid numbers.
bool	parse_flags(char **argv, t_flag *flag)
{
	int	i;

	if (!argv || !flag)
		return (false);
	i = 1;
	while ((argv[i] != NULL) && (is_flag(argv[i])))
	{
		if ((!flag->bench) && (!ft_strcmp(argv[i], "--bench")))
			flag->bench = true;
		else if ((flag->bench) && (!ft_strcmp(argv[i], "--bench")))
			return (false);
		else if (flag->strategy == UNSET)
			flag->strategy = which_strategy_flag(argv[i]);
		else
			return (false);
		++i;
	}
	if (flag->strategy == UNSET)
		flag->strategy = ADAPTIVE;
	return (true);
}

/**
 *  Parameter:
 *	*s: pointer to string.
 *	*out: pointer to integer.
 *  Return:
 * 	bool: bool indicating if string `s` is a valid input.
 *
 *  Note that (long long) guaruntees 64 bits most systems.
 */
bool	parse_int(const char *s, int *out)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	if (!s[i])
		return (false);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
		result = result * 10 + (s[i++] - '0');
		if (sign * result > INT_MAX || sign * result < INT_MIN)
			return (false);
	}
	*out = (int)(sign * result);
	return (true);
}
