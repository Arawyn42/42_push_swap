/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:38:31 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/06 17:49:16 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Pre-sorts and pushes all elements except 3 from stack a to stack b */
void	ft_push_all_but_3(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_lstsize(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && pushed < size / 2 && i < size)
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		ft_pb(stack_a, stack_b);
		pushed++;
	}
}

/* Returns the absolute value of an integer */
static unsigned int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

/* Calculates the actual cheapest move according to the costs */
void	ft_best_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	int		best;
	int		cost;
	int		target_cost;

	b = *stack_b;
	best = INT_MAX;
	while (b)
	{
		if (ft_abs(b->cost) + ft_abs(b->target_cost) < ft_abs(best))
		{
			best = ft_abs(b->cost) + ft_abs(b->target_cost);
			cost = b->cost;
			target_cost = b->target_cost;
		}
		b = b->next;
	}
	ft_operate_best_move(stack_a, stack_b, cost, target_cost);
}

/* Final stage of the Quick Sort if needed, to re-push the end on the top */
static void	ft_last_sort(t_list **stack_a)
{
	int	size;
	int	min_index_pos;

	size = ft_lstsize(*stack_a);
	min_index_pos = ft_get_min_index_pos(stack_a);
	if (min_index_pos > size / 2)
	{
		while (min_index_pos < size)
		{
			ft_rra(stack_a);
			min_index_pos++;
		}
	}
	else
	{
		while (min_index_pos > 0)
		{
			ft_ra(stack_a);
			min_index_pos--;
		}
	}
}

/* Quick sort algorithm */
void	ft_quick_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_is_sorted(*stack_a))
		return ;
	ft_push_all_but_3(stack_a, stack_b);
	ft_sort3(stack_a);
	while (*stack_b)
	{
		ft_set_target_pos(stack_a, stack_b);
		ft_set_cost(stack_a, stack_b);
		ft_best_move(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_last_sort(stack_a);
}
