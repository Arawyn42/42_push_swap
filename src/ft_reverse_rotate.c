/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:31:20 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/03 14:26:47 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Shift down all elements of a stack by 1 */
int	ft_reverse_rotate(t_list **stack)
{
	t_list	*bot;
	t_list	*top;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	top = *stack;
	bot = ft_lstlast(top);
	while (top)
	{
		if (top->next->next == NULL)
		{
			top->next = NULL;
			break ;
		}
		top = top->next;
	}
	bot->next = *stack;
	*stack = bot;
	return (1);
}

/* Shift up all elements of stack a by 1 */
int	ft_rra(t_list **stack_a)
{
	if (!ft_reverse_rotate(stack_a))
		return (0);
	ft_putstr("rra\n");
	return (1);
}

/* Shift down all elements of stack b by 1 */
int	ft_rrb(t_list **stack_b)
{
	if (!ft_reverse_rotate(stack_b))
		return (0);
	ft_putstr("rrb\n");
	return (1);
}

/* Reverse rotates stack a and stack b at the same time */
int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
		return (0);
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putstr("rrr\n");
	return (1);
}
