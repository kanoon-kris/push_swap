/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:45:14 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/08 02:26:34 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
//void	ft_bzero(void *s, size_t n)
//{
//	unsigned char	*s_copy;
//
//	s_copy = s;
//	while (n--)
//		*s_copy++ = 0;
//}
