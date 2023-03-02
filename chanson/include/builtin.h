/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:52:06 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 19:46:09 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <dirent.h>
# define PATH_MAX 1024

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*prev;
	struct s_env_list	*next;
}	t_env;

// builtin_cd_1.c
int		do_cd(t_info *info);

// builtin_cd_2.c
void	cd_home(t_env *env_list);
int		check_dir(char *cwd_buf);

// builtin_echo.c
int		do_echo(t_info *info);

// builtin_env_1.c
int		do_env(t_info *info);
char	**env_to_envp(t_env *env_list);

// builtin_env_2.c
t_env	*add_env_list(t_env *env_list, char *key, char *value);
t_env	*make_env_list(char **envp);
char	*find_path(t_info *info);

// builtin_exit.c
int		do_exit(t_info *info);

// builtin_export_1.c
int		do_export(t_info *info);

// builtin_export_2.c
t_env	*sort_export_list(t_env *export_list);
t_env	*make_export_list(char **envp);
void	print_export(t_env *export_list);
int		valid_check(char *str);

// builtin_pwd.c
int		do_pwd(t_info *info);

// builtin_unset.c
int		do_unset(t_info *info);

// builtin_main.c
int		builtin(t_info *info);

// builtin_error.c
int		print_error_1(char *str);
int		print_error_2(char *str1, char *str2);
int		print_error_3(char *str1, char *str2, char *str3);

#endif
