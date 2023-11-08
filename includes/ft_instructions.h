/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:02:50 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/03 20:41:13 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRUCTIONS_H
# define FT_INSTRUCTIONS_H

/**************************** SWAP ****************************/
int	ft_swap(t_list **stack);
int	ft_sa(t_list **stack_a);
int	ft_sb(t_list **stack_b);
int	ft_ss(t_list **stack_a, t_list **stack_b);

/**************************** PUSH ****************************/
int	ft_push(t_list **from, t_list **to);
int	ft_pa(t_list **stack_a, t_list **stack_b);
int	ft_pb(t_list **stack_a, t_list **stack_b);

/*************************** ROTATE ***************************/
int	ft_rotate(t_list **stack);
int	ft_ra(t_list **stack_a);
int	ft_rb(t_list **stack_b);
int	ft_rr(t_list **stack_a, t_list **stack_b);

/*********************** REVERSE ROTATE ***********************/
int	ft_reverse_rotate(t_list **stack);
int	ft_rra(t_list **stack_a);
int	ft_rrb(t_list **stack_b);
int	ft_rrr(t_list **stack_a, t_list **stack_b);

#endif