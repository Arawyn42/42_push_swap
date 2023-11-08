/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:21:24 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 17:01:57 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_lst.h"
# include "ft_utils.h"
# include "ft_instructions.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/**************************** ARGS ****************************/
void			ft_free(char **array);
int				ft_stack_size(char **split);
char			**ft_split_args(int ac, char **av, int *size);
t_list			*ft_args(int ac, char **av, int *size);
void			ft_set_index(t_list *stack_a, int size);

/*************************** ERRORS ***************************/
void			ft_print_error(char *error);
int				ft_check_integers(char **strargs);
int				ft_check_duplicates(t_list *args);
int				ft_check_overflow(char **strargs);
int				ft_check_errors(int ac, char **av);

/******************** SORT 3 OR LESS VALUES *******************/
int				ft_is_sorted(t_list *stack_a);
void			ft_sort2(t_list **stack_a);
void			ft_sort3(t_list **stack_a);

/************************ SET POSITION ************************/
void			ft_set_pos(t_list **stack);
void			ft_set_target_pos(t_list **stack_a, t_list **stack_b);
int				ft_get_min_index_pos(t_list **stack);

/************************** SET COST **************************/
void			ft_set_cost(t_list **stack_a, t_list **stack_b);
void			ft_operate_best_move(t_list **a, t_list **b, \
										int cost, int target_cost);

/************************* QUICK SORT *************************/
void			ft_push_all_but_3(t_list **stack_a, t_list **stack_b);
void			ft_best_move(t_list **stack_a, t_list **stack_b);
void			ft_quick_sort(t_list **stack_a, t_list **stack_b);

#endif