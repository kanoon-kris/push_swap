/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:23:40 by kboonkos          #+#    #+#             */
/*   Updated: 2026/08/31 16:59:24 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_copy;
	unsigned char	c_copy;

	c_copy = (unsigned char) c;
	s_copy = s;
	while (n)
	{
		*(s_copy + n - 1) = c_copy;
		--n;
	}
	return (s);
}
