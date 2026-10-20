/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmansak <pmansak@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:56:02 by pmansak           #+#    #+#             */
/*   Updated: 2026/10/20 15:56:02 by pmansak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_int(const char *s, int *out)
{
	long result;
	int sign;
	int i;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		result = result * 10 + (s[i] - '0');
		if (sign * result > INT_MAX || sign * result < INT_MIN)
			return (0);
		i++;
	}
	*out = (int)(sign * result);
	return (1);
}
