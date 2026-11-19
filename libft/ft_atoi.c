/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 21:46:35 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/03 05:15:37 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	unsigned char	c_ptr;

	c_ptr = c;
	if ((c_ptr == ' ') || (c_ptr == '\f') || (c_ptr == '\n')
		|| (c_ptr == '\r') || (c_ptr == '\t') || (c_ptr == '\v'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-')
	{
		sign = -1;
		++nptr;
	}
	else if (*nptr == '+')
		++nptr;
	while (ft_isdigit(*nptr))
	{
		result = (result * 10) + (*nptr - '0');
		++nptr;
	}
	return (sign * result);
}
//#include <stdio.h>
//int	main(void)
//{
//	const char	text[] = "--67";
//
//	printf("input: \"%s\"\n", text);
//	printf("atoi(\"%s\"): %d\n", text, atoi(text));
//	printf("ft_atoi(\"%s\"): %d\n", text, ft_atoi(text));
//	return (0);
//}
