/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:13:35 by kboonkos          #+#    #+#             */
/*   Updated: 2026/08/31 17:16:52 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	c_copy;

	c_copy = c;
	if (('A' <= c_copy) && (c_copy <= 'Z'))
		return (c_copy + 32);
	else
		return (c);
}
