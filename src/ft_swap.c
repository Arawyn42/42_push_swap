/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:40:08 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 17:03:11 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swaps the first 2 elements of the list */
int	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	first = *stack;
	second = first->next;
	if (!first && !second)
		ft_print_error("Error: An error occured while swapping.");
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	return (1);
}

/* Swap Stack a: sa */
int	ft_sa(t_list **stack_a)
{
	if (!ft_swap(stack_a))
		return (0);
	ft_putstr("sa\n");
	return (1);
}

/* Swap Stack b: sb */
int	ft_sb(t_list **stack_b)
{
	if (!ft_swap(stack_b))
		return (0);
	ft_putstr("sb\n");
	return (1);
}

/* sa then sb: ss */
int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
		return (0);
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss\n");
	return (1);
}
