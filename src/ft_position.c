/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:23:09 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/06 18:17:11 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Sets the current position of each element in a stack */
void	ft_set_pos(t_list **stack)
{
	t_list	*ptr;
	int		pos;

	ptr = *stack;
	pos = 0;
	while (ptr)
	{
		ptr->pos = pos;
		ptr = ptr->next;
		pos++;
	}
}

/* Sets the target position next to the minimum index in stack a */
static int	ft_set_min_target(t_list **stack_a)
{
	t_list	*a;
	int		target_index;
	int		target_pos;

	a = *stack_a;
	target_index = INT_MAX;
	target_pos = 0;
	while (a)
	{
		if (a->index < target_index)
		{
			target_index = a->index;
			target_pos = a->pos;
		}
		a = a->next;
	}
	return (target_pos);
}

/* Gets the target position needed in stack a */
static int	ft_get_target_pos(t_list **stack_a, t_list **stack_b, int b_index)
{
	t_list	*a;
	t_list	*b;
	int		target_index;
	int		target_pos;

	a = *stack_a;
	b = *stack_b;
	target_index = INT_MAX;
	target_pos = 0;
	while (a)
	{
		if (a->index > b_index && a->index < target_index)
		{
			target_index = a->index;
			target_pos = a->pos;
		}
		a = a->next;
	}
	if (target_index == INT_MAX)
		return (ft_set_min_target(stack_a));
	return (target_pos);
}

/* Sets the target position in stack a for each element of stack b */
void	ft_set_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	int		target_pos;

	b = *stack_b;
	ft_set_pos(stack_a);
	ft_set_pos(stack_b);
	target_pos = 0;
	while (b)
	{
		target_pos = ft_get_target_pos(stack_a, stack_b, b->index);
		b->target_pos = target_pos;
		b = b->next;
	}
}

/* Returns the position of the minimum index of a stack */
int	ft_get_min_index_pos(t_list **stack)
{
	t_list	*ptr;
	int		min_index;
	int		pos;

	ptr = *stack;
	min_index = INT_MAX;
	ft_set_pos(stack);
	pos = ptr->pos;
	while (ptr)
	{
		if (ptr->index < min_index)
		{
			min_index = ptr->index;
			pos = ptr->pos;
		}
		ptr = ptr->next;
	}
	return (pos);
}
