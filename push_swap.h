/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmansak <pmansak@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:43:38 by pmansak           #+#    #+#             */
/*   Updated: 2026/10/20 10:43:38 by pmansak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	parse_int(const char *s, int *out);

typedef struct s_data
{
	int				argc;
	char			*argv;
	struct s_data	*next;
}	t_data;

#endif