/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   payload_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:33:56 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/07 22:45:40 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

int	get_rank(t_list *lst)
{
	return (((t_payload *)lst->content)->rank);
}

int	get_value(t_list *lst)
{
	return (((t_payload *)lst->content)->value);
}

/**
 * Turn parsed integer value into a custom payload for (void *) content.
 * 
 * Parameter:
 * 	value: Parse-by-value integer.
 *  rank: Parse-by-value integer.
 * Return:
 * 	payload: Address of custom struct of contents for linked list.
 */
t_payload	*parse_payload(int value, int rank)
{
	t_payload	*payload;

	payload = malloc(sizeof(t_payload));
	if (!payload)
		return (free(payload), NULL);
	payload->value = value;
	payload->rank = rank;
	return (payload);
}

void	print_payload(void *content)
{
	t_payload	*payload;

	payload = (t_payload *) content;
	ft_putstr_fd("value:\t", 1);
	ft_putnbr_fd(payload->value, 1);
	ft_putstr_fd("\trank:\t", 1);
	ft_putnbr_fd(payload->rank, 1);
	ft_putendl_fd("", 1);
}
