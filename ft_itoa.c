/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki </var/mail/kitsuki>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:10:23 by kitsuki           #+#    #+#             */
/*   Updated: 2022/07/20 19:42:35 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	setstr(char *dst, int n, size_t size)
{
	size_t	count;

	count = 1;
	*(dst + size) = '\0';
	if (n == 0)
		*dst = '0';
	if (n < 0)
		*dst = '-';
	while (n != 0)
	{
		if (n < 0)
			*(dst + size - count) = '0' - (n % 10);
		else
			*(dst + size - count) = '0' + (n % 10);
		count ++;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	count;
	int		tmp;
	char	*out;

	count = 1;
	tmp = n;
	if (tmp < 0)
		count ++;
	while (tmp >= 10 || tmp <= -10)
	{
		count ++;
		tmp /= 10;
	}
	out = (char *)malloc(count + 1);
	if (out == NULL)
		return (NULL);
	setstr(out, n, count);
	return (out);
}
