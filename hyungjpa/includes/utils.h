/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:19:18 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/22 20:19:19 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

// ./utils/ft_free_str
void	ft_free_str(char **str);

// ./utils/ft_str_size
size_t	str_size(char **str);

// ./utils/ft_strchr
size_t	ft_strchr(const char *s, int c);

// ./utils/ft_strcjoin 
char	*ft_strcjoin(char *s, char c);

// ./utils/ft_strdup
char	*ft_strdup(const char *s1);

// ./utils/ft_strlen
size_t	ft_strlen(const char *s);

// ./utils/ft_strncmp
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// ./utils/ft_strrchr
size_t	ft_strrchr(const char *s, int c);

// ./utils/ft_strscmp
int		ft_strscmp(char *str1, char *str2);

// ./utils/ft_strsjoin
char	**ft_strsjoin(char **str1, char *str);

// ./utils/ft_substr
char	*ft_substr(char const *s, unsigned int start, size_t len);

// ./utils/syntax_ft_split_1
char	**ft_split_syntax(char *s);

// ./utils/syntax_ft_split_2
int		ft_split_pipe(char ***temp, char *str, int idx);
int		ft_split_redirection(char ***temp, char *str, int idx);
int		_ft_split_quote(char *str, int idx, char **buff);
int		ft_split_quote(char ***temp, char *str, int idx);

// ./utils/syntax_ft_split_3
int		ft_split_and(char ***temp, char *str, int idx);
int		ft_split_par(char ***temp, char *str, int idx);
void	dispaly_str(char **str);

// ./utils/ft_strtrim
char	*_ft_strtrim(char *str, int i, int j, int cnt);
char	*ft_strtrim_couple(char *str, char c1, char c2);
char	*ft_strtrim(char *str, char c);
char	*ft_strtrim_couple_check(char *str, char c1, char c2);

// ./utils/ft_strcpy_index.c
char	*ft_strcpy_index(char *str, int start, int end);

#endif
