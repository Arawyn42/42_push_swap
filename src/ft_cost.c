/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:02:06 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 17:06:33 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_set_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;

	a = *stack_a;
	b = *stack_b;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (b)
	{
		b->cost = b->pos;
		if (b->pos > size_b / 2)
			b->cost = b->pos - size_b;
		b->target_cost = b->target_pos;
		if (b->target_pos > size_a / 2)
			b->target_cost = b->target_pos - size_a;
		b = b->next;
	}
}

static void	ft_rotate_cost_a(t_list **stack_a, int *target_cost)
{
	while (*target_cost)
	{
		if (*target_cost < 0)
		{
			ft_rra(stack_a);
			(*target_cost)++;
		}
		else if (*target_cost > 0)
		{
			ft_ra(stack_a);
			(*target_cost)--;
		}
	}
}

static void	ft_rotate_cost_b(t_list **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			ft_rrb(stack_b);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			ft_rb(stack_b);
			(*cost)--;
		}
	}
}

void	ft_operate_best_move(t_list **a, t_list **b, int cost, int target_cost)
{
	if (cost < 0 && target_cost < 0)
	{
		while (cost < 0 && target_cost < 0)
		{
			cost++;
			target_cost++;
			ft_rrr(a, b);
		}
	}
	else if (cost > 0 && target_cost > 0)
	{
		while (cost > 0 && target_cost > 0)
		{
			cost--;
			target_cost--;
			ft_rr(a, b);
		}
	}
	ft_rotate_cost_a(a, &target_cost);
	ft_rotate_cost_b(b, &cost);
	ft_pa(a, b);
}
