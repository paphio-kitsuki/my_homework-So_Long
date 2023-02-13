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

static void	ft_lstdelone(t_list *lst)
{
	if (lst == NULL)
		return ;
	if (lst->str != NULL)
		free(lst->str);
	free(lst);
}

void	ft_lstclear(t_list	**lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
}

static void	ft_lstiter(t_list *lst)
{
	char	*tmp;

	while (lst != NULL)
	{
		tmp = ft_strrchr(lst->str, '\n');
		if (tmp != NULL)
			*tmp = '\0';
		lst = lst->next;
	}
}

void	ft_lstfix(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	while (*lst != NULL && *((*lst)->str) == '\0')
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
	while (*lst != NULL && *(ft_lstlast(*lst)->str) == '\0')
	{
		tmp = *lst;
		if (tmp->next == NULL)
		{
			ft_lstdelone(tmp);
			*lst = NULL;
			break ;
		}
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		ft_lstdelone(tmp->next);
		tmp->next = NULL;
	}
	ft_lstiter(*lst);
}
