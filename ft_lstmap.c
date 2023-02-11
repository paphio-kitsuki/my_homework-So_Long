/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki </var/mail/kitsuki>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:23:06 by kitsuki           #+#    #+#             */
/*   Updated: 2022/07/21 00:51:18 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(t_object *), void (*del)(t_object *))
{
	t_list	*out;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	out = (t_list *)malloc(sizeof(t_list));
	if (out == NULL)
		return (NULL);
	tmp = out;
	while (lst != NULL)
	{
		tmp->content = f(lst->content);
		if (lst->next != NULL)
			tmp->next = (t_list *)malloc(sizeof(t_list));
		else
			tmp->next = NULL;
		if (lst->next != NULL && tmp->next == NULL)
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (out);
}
