/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:26:04 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/13 14:45:57 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	count;

	count = 0;
	if (!n)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	digit;
	char	*dst;

	count = count_digits(n);
	dst = (char *)ft_calloc(count + 1, sizeof(char));
	if (!dst)
		return (NULL);
	if (n < 0)
		dst[0] = '-';
	if (n == 0)
		dst[--count] = '0';
	while (n != 0)
	{
		digit = n % 10;
		if (digit < 0)
			digit = -digit;
		dst[--count] = digit + '0';
		n /= 10;
	}
	return (dst);
}
