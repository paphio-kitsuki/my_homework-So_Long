/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki </var/mail/kitsuki>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:39:43 by kitsuki           #+#    #+#             */
/*   Updated: 2022/07/14 18:24:24 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstclear(t_frame *frame, void (*del)(t_frame *, t_object *))
{
	t_list	*tmp;

	if (frame == NULL || del == NULL)
		return ;
	while (frame->list != NULL)
	{
		tmp = frame->list->next;
		lstdelone(frame->list, del);
		frame->list = tmp;
	}
}
