/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:13:11 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/02 20:38:03 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_converted;
	const unsigned char	*s2_converted;
	size_t				idx;

	if (n == 0)
		return (0);
	s1_converted = s1;
	s2_converted = s2;
	idx = 0;
	while ((idx < n) && (*(s1_converted + idx) == *(s2_converted + idx)))
		++idx;
	if (idx < n)
		return (*(s1_converted + idx) - *(s2_converted + idx));
	else
		return (0);
}
