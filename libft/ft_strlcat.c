/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 18:00:42 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/11 15:48:19 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	idx_dst;
	size_t	total_len;

	if (size == 0)
		return (ft_strlen(src));
	idx_dst = 0;
	while ((idx_dst < size) && (dst[idx_dst]))
		++idx_dst;
	if (dst[idx_dst] != '\0')
		return (size + ft_strlen(src));
	total_len = ft_strlen(dst) + ft_strlen(src);
	idx = 0;
	while (((idx_dst + idx) < size - 1) && (src[idx] != '\0'))
	{
		dst[idx_dst + idx] = src[idx];
		++idx;
	}
	dst[idx_dst + idx] = '\0';
	return (total_len);
}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <bsd/string.h>
//int	main(void)
//{
//	char	cat[8] = "cat";
//	char	fish[] = "fish";
//	char	*cat_dup;
//	size_t	ret = 0;
//	size_t	ret_ft = 0;
//
//	cat_dup = strdup(cat);
//	printf("BEFORE:\n");
//	printf("og: %s\n", cat);
//	ret = strlcat(cat, fish, 8);
//	printf("ft: %s\n", cat_dup);
//	ret_ft = ft_strlcat(cat_dup, fish, 8);
//	printf("AFTER:\n");
//	printf("og: %s\n", cat);
//	printf("ft: %s\n", cat_dup);
//	printf("ret: %zu\n", ret);
//	printf("ret_ft: %zu\n", ret_ft);
//	return (0);
//}
