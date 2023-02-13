/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki </var/mail/kitsuki>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:56:08 by kitsuki           #+#    #+#             */
/*   Updated: 2022/07/21 01:20:49 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			ct;
	unsigned char	*a1;
	unsigned char	*a2;

	ct = 0;
	if (n == 0 || s1 == NULL || s2 == NULL)
		return (0);
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	while (*(a1 + ct) == *(a2 + ct) && ct + 1 < n && *(a1 + ct) != '\0')
		ct ++;
	return (*(a1 + ct) - *(a2 + ct));
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (*(str + count) != '\0')
		count ++;
	return (count);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	size;
	char	*out;
	size_t	count;
	size_t	str_size;

	if (str == NULL)
		return (NULL);
	str_size = ft_strlen(str);
	if (len + start > str_size)
	{
		if (str_size < start)
			size = 0;
		else
			size = str_size - start;
	}
	else
		size = len;
	out = (char *)malloc(size + 1);
	if (out == NULL)
		return (NULL);
	count = 0;
	while (count ++ < size)
		*(out + count - 1) = *(str + start + count - 1);
	*(out + size) = '\0';
	return (out);
}
