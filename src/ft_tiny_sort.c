/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:46:33 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 22:59:51 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Returns 1 if the stack is sorted, 0 if not */
int	ft_is_sorted(t_list *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

/* Sorts 2 values */
void	ft_sort2(t_list **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		ft_sa(stack_a);
}

/* Sorts 3 values in 2 moves max */
void	ft_sort3(t_list **stack_a)
{
	int		index_max;
	t_list	*tmp;

	tmp = *stack_a;
	index_max = tmp->index;
	if (ft_is_sorted(*stack_a))
		return ;
	while (tmp)
	{
		if (tmp->index > index_max)
			index_max = tmp->index;
		tmp = tmp->next;
	}
	if ((*stack_a)->index == index_max)
		ft_ra(stack_a);
	else if ((*stack_a)->next->index == index_max)
		ft_rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		ft_sa(stack_a);
}
