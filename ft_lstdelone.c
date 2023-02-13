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

void	lstdelone(t_frame *frame, void (*del)(t_object *))
{
	if (frame == NULL || del == NULL)
		return ;
	del(frame->list->content);
	free(frame->list);
}
