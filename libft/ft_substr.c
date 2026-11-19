/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 01:49:04 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/16 18:51:30 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	len = min(len, (ft_strlen(s) - (size_t) start));
	if ((start >= ft_strlen(s)))
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		*(res) = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, (s + start), len);
	*(res + len) = '\0';
	return (res);
}
//#include <stdio.h>
//int	main(void)
//{
//	size_t	first = 1;
//	size_t	second = 100;
//	size_t	result = first - second;
//
//}
