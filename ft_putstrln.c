/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:58:36 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/01 00:58:36 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstrln(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr(s, fd);
	write(fd, "\n", sizeof(char));
}

void	ft_putstr(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(fd, s, sizeof(*s));
		s ++;
	}
}
