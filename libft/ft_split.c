/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 19:31:08 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/18 20:48:19 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	unsigned char	word_entered;
	size_t			idx;
	size_t			count;

	count = 0;
	idx = 0;
	word_entered = 0;
	while (*(s + idx) != '\0')
	{
		if ((!word_entered) && (*(s + idx) != c))
		{
			word_entered = 1;
			++count;
		}
		else if ((!word_entered) && (*(s + idx) == c))
			;
		else if ((word_entered) && (*(s + idx) != c))
			;
		else if ((word_entered) && (*(s + idx) == c))
			word_entered = 0;
		++idx;
	}
	return (count);
}

static void	free_result(char **result, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		++i;
	}
	free(result);
}

static char	*manifest_word(char const *s, size_t start_word, size_t len)
{
	char	*new_word;

	new_word = malloc(len + 1);
	if (!new_word)
		return (NULL);
	ft_memcpy(new_word, s + start_word, len);
	new_word[len] = '\0';
	return (new_word);
}

//char	**ft_split(const char *s, char c)
//{
//	size_t	word_count;
//	char	**result;
//	size_t	inner_index;
//	size_t	start_word;
//	size_t	index;
//
//	word_count = count_word(s, c);
//	result = calloc((word_count + 1), sizeof(char *));
//	if (!result)
//		return (NULL);
//	inner_index = 0;
//	index = 0;
//	while (s[inner_index] != '\0')
//	{
//		while (s[inner_index] == c)
//			++inner_index;
//		if (s[inner_index] == '\0')
//			break ;
//		start_word = inner_index;
//		while ((s[inner_index] != '\0') && (s[inner_index] != c))
//			++inner_index;
//		result[index] = manifest_word(s, start_word, inner_index
//				- start_word);
//		if (!result[index])
//		{
//			free_result(result, index);
//			return (NULL);
//		}
//		++index;
//	}
//	result[index] = NULL;
//	return (result);
//}

static int	fill_words(char **result, char const *s, char c)
{
	size_t	index;
	size_t	inner_index;
	size_t	start_word;

	index = 0;
	inner_index = 0;
	while (s[inner_index] != '\0')
	{
		while (s[inner_index] == c)
			++inner_index;
		if (s[inner_index] == '\0')
			break ;
		start_word = inner_index;
		while ((s[inner_index] != '\0') && (s[inner_index] != c))
			++inner_index;
		result[index] = manifest_word(s, start_word,
				inner_index - start_word);
		if (!result[index])
			return (0);
		++index;
	}
	result[index] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	word_count;

	word_count = count_word(s, c);
	result = ft_calloc((word_count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	if (!fill_words(result, s, c))
	{
		free_result(result, word_count);
		return (NULL);
	}
	return (result);
}
