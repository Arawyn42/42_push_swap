/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:29:29 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/08 17:02:55 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include "push_swap.h"

/**************************** GNL ****************************/
char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer, char *statch);
char	*ft_get_line(char *statch);

/************************* GNL UTILS *************************/
char	*gnl_strchr(char const *s, int c);
size_t	gnl_strlen(char const *s);
char	*gnl_strdup(char const *src);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_substr(const char *s, unsigned int start, size_t len);

#endif