/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki </var/mail/kitsuki>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:20:26 by kitsuki           #+#    #+#             */
/*   Updated: 2022/07/14 10:20:44 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lstdelone(t_frame *f, t_list *lst, void (*del)(t_frame *, t_object *))
{
	if (f == NULL || lst == NULL || del == NULL)
		return ;
	del(f, lst->content);
	free(lst);
}
