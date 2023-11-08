/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:30:56 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 23:02:03 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/* Checks each line and do the move if it matches */
static int	ft_checker(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "sa\n")))
		return (ft_swap(stack_a));
	else if (!(ft_strcmp(line, "sb\n")))
		return (ft_swap(stack_b));
	else if (!(ft_strcmp(line, "ss\n")))
		return (ft_swap(stack_a) && ft_swap(stack_b));
	else if (!(ft_strcmp(line, "pa\n")))
		return (ft_push(stack_b, stack_a));
	else if (!(ft_strcmp(line, "pb\n")))
		return (ft_push(stack_a, stack_b));
	else if (!(ft_strcmp(line, "ra\n")))
		return (ft_rotate(stack_a));
	else if (!(ft_strcmp(line, "rb\n")))
		return (ft_rotate(stack_b));
	else if (!(ft_strcmp(line, "rr\n")))
		return (ft_rotate(stack_a) && ft_rotate(stack_b));
	else if (!(ft_strcmp(line, "rra\n")))
		return (ft_reverse_rotate(stack_a));
	else if (!(ft_strcmp(line, "rrb\n")))
		return (ft_reverse_rotate(stack_b));
	else if (!(ft_strcmp(line, "rrr\n")))
		return (ft_reverse_rotate(stack_a) && ft_reverse_rotate(stack_b));
	return (-1);
}

static int	ft_check(char *line, t_list **stack_a, t_list **stack_b)
{
	int	checker;

	while (line)
	{
		ft_putstr(line);
		checker = ft_checker(line, stack_a, stack_b);
		if (checker <= 0)
		{
			free(line);
			return (ft_lstclear(stack_a), ft_lstclear(stack_b), checker);
		}
		if (ft_is_sorted(*stack_a) && ft_lstsize(*stack_b) < 1)
			break ;
		free(line);
		line = get_next_line(0);
	}
	if (ft_is_sorted(*stack_a) && ft_lstsize(*stack_b) < 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	free(line);
	return (1);
}

/* Main function */
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	*line;
	int		check;

	size = 1;
	if (!ft_check_errors(ac, av))
		return (-1);
	stack_a = ft_args(ac, av, &size);
	stack_b = NULL;
	line = get_next_line(0);
	check = ft_check(line, &stack_a, &stack_b);
	if (check == -1)
		ft_print_error("Error");
	else if (!check)
		ft_putstr("KO\n");
	get_next_line(-1);
	return (0);
}
