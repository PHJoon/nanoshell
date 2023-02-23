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

// builtin_cd.c
void		do_cd(char **str);

// builtin_echo.c
void	do_echo(char **str, t_env_list *env_list);

// builtin_env_1.c
void		do_env(char **str, t_env_list *env_list);

// builtin_env_2.c
t_env_list	*add_env_list(t_env_list *env_list, char *key, char *value);
t_env_list	*make_env_list(char **envp);

// builtin_export_1.c
void		do_export(char **str, t_env_list **export_list, \
t_env_list **env_list);

// builtin_export_2.c
t_env_list	*sort_export_list(t_env_list *export_list);
t_env_list	*make_export_list(char **envp);
void		print_export(t_env_list *export_list);

// builtin_pwd.c
void		do_pwd(char **str);

// builtin_unset.c
t_env_list	*do_unset(char **str, t_env_list *env_list);

#endif
