/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:25:44 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 18:26:36 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Frees a double array of char */
void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* Calculates the size for the calloc in ft_args function */
int	ft_stack_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

/* Converts all args into a double array of args */
char	**ft_split_args(int ac, char **av, int *size)
{
	char	**res;
	char	*str;
	int		i;

	str = ft_strdup("");
	if (ac == 2)
		str = ft_strjoin(str, av[1]);
	else
	{
		i = 1;
		while (i < ac)
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, av[i]);
			i++;
		}
	}
	res = ft_split(str, ' ');
	if (!res)
		return (free(str), NULL);
	free(str);
	*size = ft_stack_size(res);
	return (res);
}

/* Converts the int array into a list and returns the list */
t_list	*ft_args(int ac, char **av, int *size)
{
	char	**strargs;
	t_list	*new;
	t_list	*args;
	int		i;

	strargs = ft_split_args(ac, av, size);
	if (!strargs)
		return (ft_free(strargs), strargs = NULL, NULL);
	args = NULL;
	i = 0;
	while (i < *size)
	{
		new = ft_lstnew(ft_atoi(strargs[i]));
		if (!new)
		{
			ft_lstclear(&args);
			ft_free(strargs);
			return (NULL);
		}
		ft_lstadd_back(&args, new);
		i++;
	}
	ft_free(strargs);
	return (args);
}

/* Sets indexes values in a stack */
void	ft_set_index(t_list *stack_a, int size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

	while (--size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest)
			highest->index = size;
	}
}
