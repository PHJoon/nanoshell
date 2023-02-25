/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:04 by chanson           #+#    #+#             */
/*   Updated: 2023/02/24 12:54:45 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_strchr(const char *s, int c);
char	*get_strchr_s(const char *s, int c);
char	*get_next_line(int fd);
char	*get_strjoin(char *s1, char *s2);
int		get_strllen(char const *s);
char	*get_strdup(const char *s1, int end);
void	free_pointer(char *ptr);

#endif