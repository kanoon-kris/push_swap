/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 05:21:51 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/10 22:44:32 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 1. Loop until a char is not in set at the beginning
// 2. Yes: memmove the string to the left
// 3. No: Skipped
// 4. Check if the last char of set is (len - 1), the last before /0
// 4. Loop from the last until a char is not in the set
// 5. Yes: ft_memmove 1 char towards the beginning
// 6. No: Skipped
char	*ft_strtrim(char const *s1, char const *set)
{
	char		is_searching;
	const char	*s1_begin;
	const char	*s1_end;
	size_t		len;

	is_searching = 1;
	s1_begin = s1;
	s1_end = s1 + ft_strlen(s1) - 1;
	while (is_searching)
	{
		if (ft_strchr(set, *(s1_begin)) != NULL)
			++s1_begin;
		else if (ft_strrchr(set, *(s1_end)) != NULL)
			--s1_end;
		else
			is_searching = 0;
	}
	len = (s1_end - s1_begin + 1);
	return (ft_substr(s1, (s1_begin - s1), len));
}

//char	*ft_strtrim(char const *s1, char const *set)
//{
//	char	is_searching;
//	char	*s1_copy;
//	size_t	len_s1_copy;
//
//	is_searching = 1;
//	s1_copy = ft_strdup(s1);
//	while (is_searching)
//	{
//		if (*s1_copy == '\0')
//			break;
//		if (ft_strchr(set, *(s1_copy)) != NULL)
//			ft_memmove((s1_copy), (s1_copy + 1), ft_strlen(s1_copy));
//		else
//			is_searching = 0;
//	}
//	len_s1_copy = ft_strlen(s1_copy);
//	is_searching = 1;
//	while (is_searching)
//	{
//		if (len_s1_copy == 0)
//			break;
//		if (ft_strrchr(set, *(s1_copy + len_s1_copy - 1)) != NULL)
//		{
//			ft_memmove((s1_copy + len_s1_copy - 1),
//				(s1_copy + len_s1_copy), 1);
//			len_s1_copy = ft_strlen(s1_copy);
//		}
//		else
//			is_searching = 0;
//	}
//	return (s1_copy);
//}
//#include <stdio.h>
//int	main(void)
//{
//	char	text[] = "xyxyxyxyhello worldxyxyxyxy";
//	char	set[] = "xy";
//
//	printf("input: '%s'\n", text);
//	printf("output: '%s'\n", ft_strtrim(text, set));
//	return (0);
//}
