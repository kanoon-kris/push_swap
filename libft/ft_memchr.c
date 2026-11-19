/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 23:04:23 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/02 20:27:36 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_converted;
	unsigned char		c_converted;
	size_t				idx;

	idx = 0;
	c_converted = c;
	s_converted = s;
	while (idx < n)
	{
		if (*(s_converted + idx) == c_converted)
			return ((void *)(s + idx));
		++idx;
	}
	return (NULL);
}
