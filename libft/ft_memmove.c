/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 21:04:06 by kboonkos          #+#    #+#             */
/*   Updated: 2026/08/31 16:59:11 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_copy;
	const unsigned char	*src_copy;

	dest_copy = dest;
	src_copy = src;
	if (dest_copy < src_copy)
		ft_memcpy(dest, src, n);
	else
	{
		while (n != 0)
		{
			*(dest_copy + n - 1) = *(src_copy + n - 1);
			--n;
		}
	}
	return (dest);
}
