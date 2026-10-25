/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:23:10 by kboonkos          #+#    #+#             */
/*   Updated: 2026/10/23 17:44:29 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * Turn parsed integer value into a custom payload for (void *) content.
 * 
 * Parameter:
 * 	value: Parse-by-value integer.
 * Return:
 * 	payload: Address of custom struct of contents for linked list.
 */
t_payload	*parse_payload(int value)
{
	t_payload	*payload;

	payload = malloc(sizeof(t_payload));
	if (!payload)
		return (free(payload), NULL);
	payload->value = value;
	payload->is_processed = false;
	return (payload);
}

void	print_payload(void *content)
{
	t_payload	*payload;

	payload = (t_payload *) content;
	ft_putnbr_fd(payload->value, 1);
	ft_putendl_fd("", 1);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	const int	number[4] = {1, 2, 3, 4};
	size_t		idx;

	a = NULL;
	b = NULL;
	idx = 0;
	while (idx < (sizeof(number)/sizeof(number[0])))
		ft_lstadd_front(&a,
			ft_lstnew((void *)parse_payload(number[idx++])));
	ft_lstiter(a, print_payload);
	ft_lstiter(b, print_payload);
	return (0);
}
