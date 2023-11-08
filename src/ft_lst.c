/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:56:51 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/04 16:03:47 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Function to create a new list with one element */
t_list	*ft_lstnew(int value)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->value = value;
	res->index = 0;
	res->pos = -1;
	res->target_pos = -1;
	res->cost = -1;
	res->target_cost = -1;
	res->next = NULL;
	return (res);
}

/* Adds a new element into a list */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

/* Deletes and free one element from a list */
void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		free(lst);
		lst = NULL;
	}
}

/* Deletes and free all elements from a list */
void	ft_lstclear(t_list **lst)
{
	if (lst && *lst)
	{
		ft_lstclear(&(*lst)->next);
		ft_lstdelone(*lst);
		*lst = NULL;
	}
}
