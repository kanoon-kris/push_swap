/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmansak <pmansak@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:56:02 by pmansak           #+#    #+#             */
/*   Updated: 2026/11/07 17:36:58 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>

// To verify if the format of passed string matches with flag syntax.
static bool	is_valid_flag_syntax(const char *str)
{
	size_t	i;

	if (ft_strlen(str) <= 2)
		return (false);
	i = 0;
	while ((i <= 1) && (str[i] == '-'))
		++i;
	while ((str[i]) && (ft_isalpha(str[i])) && (i <= 9))
		++i;
	if (!str[i])
		return (true);
	return (false);
}

// To verify if the passed string is one of valid flags.
bool	is_valid_flag(const char *str)
{
	const char	*flags[] = {"--simple", "--medium", "--complex",
		"--adaptive", "--bench"};
	size_t		i;

	if (!is_valid_flag_syntax(str))
		return (false);
	i = 0;
	while (i < 5)
	{
		if (!ft_strcmp(str, flags[i]))
			return (true);
		++i;
	}
	return (false);
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
