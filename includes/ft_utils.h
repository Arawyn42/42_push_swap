/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:52:45 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 17:02:44 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
long	ft_atoi(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
void	ft_bzero(void *dest, size_t n);
void	*ft_calloc(size_t n, size_t size);
int		ft_strcmp(const char *s1, const char *s2);

#endif