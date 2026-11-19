/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 00:45:20 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/01 22:03:21 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (n == 0)
		return (0);
	idx = 0;
	while ((idx < n) && ((unsigned char) s1[idx] == (unsigned char) s2[idx]))
		++idx;
	if (idx >= n)
		return ((unsigned char) s1[idx - 1] - (unsigned char) s2[idx - 1]);
	return ((unsigned char) s1[idx] - (unsigned char) s2[idx]);
}
//#include <stdio.h>
//#include <bsd/string.h>
//int	main(void)
//{
//	printf("Double Quote:\n");
//	printf("octal: %ld\n", ("\200"[0] - "\0"[0]));
//	printf("octal: %ld\n", ("\200"));
//	printf("octal: %d\n", ("\200"));
//	printf("octal: %o\n", ("\200"));
//	printf("Single Quote:\n");
//	printf("octal: %ld\n", ('\200' - '\0'));
//	printf("ft: %d\n", ft_strncmp("test\200", "test\0", 6));
//	printf("ft: %d\n", ft_strncmp("test\0", "test\200", 6));
//	return (0);
//}
