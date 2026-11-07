/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:55:49 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/08 00:23:11 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// h means hundredths
void	print_disorder(long long h)
{
	long long	immediate;

	immediate = h / 100;
	ft_putnbr_fd(immediate, 2);
	ft_putstr_fd(".", 2);
	immediate = h % 100;
	if (immediate < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(immediate, 2);
	ft_putstr_fd("%", 2);
}

void	compute_mistake_and_total_pair(t_list *lst, long long *mistake,
long long *total_pair)
{
	t_list		*anchor;
	t_list		*runner;

	*mistake = 0;
	*total_pair = 0;
	anchor = lst;
	while (anchor->next)
	{
		runner = anchor->next;
		while (runner)
		{
			++*total_pair;
			if (get_rank(anchor) > get_rank(runner))
				++*mistake;
			runner = runner->next;
		}
		anchor = anchor->next;
	}
}

void	compute_disorder(t_list *lst)
{
	long long	m;
	long long	t;
	long long	h;

	if (!lst)
		return ;
	compute_mistake_and_total_pair(lst, &m, &t);
	if (t < 1)
		h = 0;
	else
		h = (10000 * m + t / 2) / t;
	print_disorder(h);
}
