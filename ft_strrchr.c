/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki </var/mail/kitsuki>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:44:22 by kitsuki           #+#    #+#             */
/*   Updated: 2022/07/22 18:43:21 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != (unsigned char)c && *s != '\0')
		s ++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = ft_strchr(s, c);
	if (tmp == NULL)
		return (NULL);
	if (*tmp == '\0')
		return (tmp);
	ans = tmp;
	tmp = ft_strrchr(ans + 1, c);
	if (tmp != NULL)
		ans = tmp;
	return (ans);
}
