/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:31:18 by kboonkos          #+#    #+#             */
/*   Updated: 2026/08/29 18:27:06 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static int	hidden_isupper(int c)
{
	if (('A' <= c) && (c <= 'Z'))
		return (1);
	else
		return (0);
}

static int	hidden_islower(int c)
{
	if (('a' <= c) && (c <= 'z'))
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	int	result;

	result = 0;
	if (hidden_isupper(c) || hidden_islower(c))
		result = 1;
	return (result);
}
