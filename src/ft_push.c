/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:07:27 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 18:35:18 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Pushes the first element of the stack 'from' at the top of the stack 'to' */
int	ft_push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!ft_lstsize(*from))
		return (0);
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	return (1);
}

/* Pushes the first element of the stack b at the top of the stack a */
int	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (!ft_push(stack_b, stack_a))
		return (0);
	ft_putstr("pa\n");
	return (1);
}

/* Pushes the first element of the stack a at the top of the stack b */
int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (!ft_push(stack_a, stack_b))
		return (0);
	ft_putstr("pb\n");
	return (1);
}
