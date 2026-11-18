/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 23:43:13 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/18 20:14:39 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "push_swap.h"

static void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

// fill_pass on its own does not treat an empty string ("") as an error.
// Note that "no parameters" and "empty argument" are different.
// No parameters causes (argc == 1) to be true while empty argument is
// (argc >= 2) but nothing inside the string.
// In case of quoted shell variable such as `ARG=""; ./push_swap $ARG`,
// the unquoted empty variable disappears, so `argc` becomes 1 in which
// the program prints nothing. This is not to be confused with quoted quoted
// empty string, e.g., `ARG=""; ./push_swap "$ARG"`.
int	fill_pass(char **argv, int *num_buf)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!argv || !num_buf)
		return (-1);
	i = 1;
	while ((argv[i] != NULL) && (is_flag(argv[i])))
		++i;
	k = 0;
	while (argv[i] != NULL)
	{
		tab = ft_split(argv[i++], ' ');
		if (!tab)
			return (-1);
		j = 0;
		while (tab[j] != NULL)
		{
			if (!parse_int(tab[j++], &num_buf[k++]))
				return (free_tab(tab), -1);
		}
		free_tab(tab);
	}
	return (k);
}
