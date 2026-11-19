/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 00:33:32 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/16 17:32:21 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_len(int n)
{
	size_t	count;
	long	n_copy;

	count = 0;
	n_copy = n;
	if (n_copy == 0)
	{
		++count;
	}
	else if (n_copy != 0)
	{
		if (n_copy < 0)
		{
			n_copy = -n_copy;
			++count;
		}
		while (n_copy > 0)
		{
			n_copy = n_copy / 10;
			++count;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	num_len;
	char	*result;
	long	n_copy;

	num_len = count_len(n);
	if (n < 0)
		n_copy = -(long)n;
	else
		n_copy = n;
	result = malloc((num_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[num_len--] = '\0';
	while (num_len > 0)
	{
		result[num_len] = ((unsigned char)(n_copy % 10)) | '0';
		n_copy = n_copy / 10;
		--num_len;
	}
	if (n < 0)
		result[0] = '-';
	else
		result[0] = (unsigned char)(n_copy) | '0';
	return (result);
}
//
//void	test_itoa_main(int input)
//{
//	printf("input: %d\n", input);
//	printf("ft_itoa: %s\n", ft_itoa(input));
//}
//
//void	test_count_len(void)
//{
//	size_t	count = 11;
//	int	input[] = {-99999, -9999, -100, -99, -1, 0, 1, 99, 100, 9999, 99999};
//	int	index = 0;
//
//	while (index < count)
//	{
//		printf("count(%d): %ld\n", input[index], count_len(input[index]));
//		++index;
//	}
//	unsigned long	zero_long = 0;
//	printf("max_ld: %ld\n", --zero_long);
//}
//
//int	main(void)
//{
//	test_itoa_main(0);
//	return (0);
//}
