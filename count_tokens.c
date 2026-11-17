/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:24:35 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/17 23:39:41 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while ((argv[i] != NULL) && ((which_strategy_flag(argv[i]) != UNSET)
			|| !(ft_strcmp("--bench", argv[i]))))
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
