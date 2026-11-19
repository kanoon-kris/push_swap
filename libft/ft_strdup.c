/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 05:15:45 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/10 04:34:03 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str_pt;

	len = ft_strlen(s);
	str_pt = malloc(sizeof(char) * len + 1);
	if (str_pt == NULL)
		return (NULL);
	return (ft_memcpy(str_pt, s, len + 1));
}
//char	*ft_strdup(const char *s)
//{
//	char	*str_pt;
//	size_t	len;
//	size_t	idx;
//
//	idx = 0;
//	len = ft_strlen(s);
//	str_pt = malloc(sizeof(char) * len + 1);
//	if (str_pt == NULL)
//		return (NULL);
//	while (idx < len)
//	{
//		*(str_pt + idx) = *(s + idx);
//		++idx;
//	}
//	return (str_pt);
//}
