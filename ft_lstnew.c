/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki </var/mail/kitsuki>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:09:45 by kitsuki           #+#    #+#             */
/*   Updated: 2022/07/14 18:30:57 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstnew(char	*str)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (out == NULL)
		return (NULL);
	out->str = str;
	out->next = NULL;
	return (out);
}
