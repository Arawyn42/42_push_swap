/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:21:27 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 18:02:59 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Main sorting function, which calls each case depending on the stack size */
static void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sort2(stack_a);
	else if (size == 3)
		ft_sort3(stack_a);
	else if (size > 3)
		ft_quick_sort(stack_a, stack_b);
}

/* Main function */
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	size = 1;
	if (!ft_check_errors(ac, av))
		return (-1);
	stack_a = ft_args(ac, av, &size);
	stack_b = NULL;
	ft_set_index(stack_a, size + 1);
	ft_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
