/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:06:21 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/15 14:06:21 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*g_print = NULL;

void	set_count(char *str)
{
	if (g_print != NULL)
		free(g_print);
	g_print = str;
}

char	*get_count(void)
{
	return (g_print);
}
