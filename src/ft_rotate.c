/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:58:19 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/03 14:27:37 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Shift up all elements of a stack by 1 */
int	ft_rotate(t_list **stack)
{
	t_list	*bot;
	t_list	*top;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	top = *stack;
	bot = ft_lstlast(top);
	*stack = top->next;
	top->next = NULL;
	bot->next = top;
	return (1);
}

/* Shift up all elements of stack a by 1 */
int	ft_ra(t_list **stack_a)
{
	if (!ft_rotate(stack_a))
		return (0);
	ft_putstr("ra\n");
	return (1);
}

/* Shift up all elements of stack b by 1 */
int	ft_rb(t_list **stack_b)
{
	if (!ft_rotate(stack_b))
		return (0);
	ft_putstr("rb\n");
	return (1);
}

/* Rotates stack a and stack b at the same time */
int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
		return (0);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr("rr\n");
	return (1);
}
