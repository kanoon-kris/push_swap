/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:44:23 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/16 17:59:39 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	idx_inner;

	if (*little == '\0')
		return ((char *)(big));
	idx_inner = 0;
	idx = 0;
	while ((*(big + idx) != '\0') && (idx < len))
	{
		idx_inner = 0;
		while ((*(big + idx + idx_inner) == *(little + idx_inner))
			&& (*(little + idx_inner) != '\0')
			&& ((idx + idx_inner) < len))
			++idx_inner;
		if (*(little + idx_inner) == '\0')
			return ((char *)(big + idx));
		++idx;
	}
	return (NULL);
}
//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	printf("%s\n", ft_strnstr("Hellow World", "W", 1));
//	printf("%s\n", ft_strnstr(NULL, NULL, 1));
//	printf("og: %s\n", strnstr(NULL, NULL, 1));
//	return (0);
//}
