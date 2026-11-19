/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 04:59:56 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/08 05:17:23 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;

	size = sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1;
	res = malloc(size);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	ft_strlcat(res, s1, size);
	ft_strlcat(res, s2, size);
	return (res);
}
