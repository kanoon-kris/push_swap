/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:28:26 by kboonkos          #+#    #+#             */
/*   Updated: 2026/08/31 16:59:55 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;

	if (size == 0)
		return (ft_strlen(src));
	idx = 0;
	while ((idx < size - 1) && (src[idx] != '\0'))
	{
		dst[idx] = src[idx];
		++idx;
	}
	dst[idx] = '\0';
	return (ft_strlen(src));
}
//
//#include <bsd/string.h>
//#include <stdlib.h>
//#include <stdio.h>
//int	main(void)
//{
//	const char	text[] = "0123456789";
//	char	text_emp[] = "";
//	char	*pt;
//	char	*pt_n;
//	size_t	ret;
//
//	pt = malloc(sizeof(char) * 11 + 1);
//	pt_n = NULL;
//	ret = strlcpy(pt_n, text, 12);
//	printf("text: %s\n", text);
//	printf("pt: %s\n", pt);
//	printf("ret: %zu\n", ret);
//	return (0);
//}
