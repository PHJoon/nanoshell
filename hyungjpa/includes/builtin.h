/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:52:06 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/17 15:52:10 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*prev;
	struct s_env_list	*next;
}	t_env_list;

// builtin_echo.
void		do_echo(char **str);

// builtin_env.c
t_env_list	*make_env_list(char **envp);
void		do_env(t_env_list	*env_list);

// builtin_unset.c
t_env_list	*do_unset(t_env_list *env_list, char *key);

// builtin_export.c
t_env_list	*make_export_list(char **envp);
void		do_export(t_env_list *export_list);

// builtin_utils.c
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
