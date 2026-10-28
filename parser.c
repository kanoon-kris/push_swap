/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmansak <pmansak@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:56:02 by pmansak           #+#    #+#             */
/*   Updated: 2026/10/26 01:34:54 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/**
 *  Parameter:
 *	*s: pointer to string.
 *	*out: pointer to integer.
 *  Return:
 * 	result: binary integer indicating if string `s` is a valid input. 
 */
int	parse_int(const char *s, int *out)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		result = result * 10 + (s[i++] - '0');
		if (sign * result > INT_MAX || sign * result < INT_MIN)
			return (0);
	}
	*out = (int)(sign * result);
	return (1);
}
