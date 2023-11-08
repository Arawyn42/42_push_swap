/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:19:47 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 17:54:31 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Checks each argument contiains at least one char and not only spaces */
int	ft_check_contains(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		if (ft_strlen(av[i]) < 1)
		{
			ft_print_error("Error: Some arguments contain nothing.");
			return (0);
		}
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j] != '\0')
				break ;
			j++;
			if (av[i][j] == '\0')
				return (ft_print_error("Error"), 0);
		}
		i++;
	}
	return (1);
}

/* Checks all arguments are integers only */
int	ft_check_integers(char **strargs)
{
	int		i;
	int		j;

	i = -1;
	while (strargs[++i])
	{
		if (strargs[i][0] == '-' && ft_strlen(strargs[i]) == 1)
		{
			ft_print_error("Error: Arguments must be integers only.");
			return (0);
		}
		if (strargs[i][0] != '-')
			j = -1;
		else
			j = 0;
		while (strargs[i][++j])
		{
			if (strargs[i][j] < '0' || strargs[i][j] > '9')
			{
				ft_print_error("Error: Arguments must be integers only.");
				return (0);
			}
		}
	}
	return (1);
}

/* Checks there is no overflow */
int	ft_check_overflow(char **strargs)
{
	int		i;
	long	number;

	i = 0;
	while (strargs[i])
	{
		number = ft_atoi(strargs[i]);
		if (number > INT_MAX || number < INT_MIN || ft_strlen(strargs[i]) > 15)
		{
			ft_print_error("Error: Overflow. Put numbers between\
 -2147483648 and 2147483647.");
			return (0);
		}
		i++;
	}
	return (1);
}

/* Checks if there is no duplicates */
int	ft_check_duplicates(t_list *args)
{
	t_list	*lst;
	t_list	*cursor;

	lst = args;
	while (lst)
	{
		cursor = lst->next;
		while (cursor)
		{
			if (lst->value == cursor->value)
			{
				ft_print_error("Error: Duplicated arguments.");
				return (0);
			}
			cursor = cursor->next;
		}
		lst = lst->next;
	}
	return (1);
}

/* Checks errors : Only integers, no duplicates, no overflows, contains */
int	ft_check_errors(int ac, char **av)
{
	int		size;
	char	**strargs;
	t_list	*args;

	if (ac <= 1)
		return (0);
	if (!ft_check_contains(av))
		return (0);
	size = 1;
	strargs = ft_split_args(ac, av, &size);
	if (!strargs)
		return (write(2, "Error.\n", 7), ft_free(strargs), 0);
	if (!ft_check_integers(strargs))
		return (ft_free(strargs), 0);
	if (!ft_check_overflow(strargs))
		return (ft_free(strargs), 0);
	args = ft_args(ac, av, &size);
	ft_free(strargs);
	if (!ft_check_duplicates(args))
		return (ft_lstclear(&args), 0);
	ft_lstclear(&args);
	return (1);
}
