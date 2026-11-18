/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:24:35 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/18 21:37:47 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

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

bool	is_flag(const char *str)
{
	return ((which_strategy_flag(str) != UNSET)
		|| !(ft_strcmp("--bench", str)));
}

// Assumption:
//   - argc > 1
//   - flags before numbers
int	count_tokens(char **argv)
{
	int		count;
	int		cur_count;
	int		i;

	if (!argv)
		return (-1);
	count = 0;
	i = 1;
	while ((argv[i] != NULL) && (is_flag(argv[i])))
		++i;
	while (argv[i] != NULL)
	{
		cur_count = (int) count_word(argv[i], ' ');
		if (cur_count == 0)
			return (-1);
		count += cur_count;
		++i;
	}
	return (count);
}
