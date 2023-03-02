/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:59:58 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 17:13:19 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define TRUE 1
# define FALSE 0
# define READ 0
# define WRITE 1

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>

# include "signal_handler.h"
# include "utils.h"

enum e_token
{
	TK_STR,
	TK_IRD,
	TK_ORD,
	TK_HRD,
	TK_ARD,
	TK_PIPE,
	TK_AND,
	TK_OR,
	TK_LPT,
	TK_RPT,
	TK_INVALID,
	TK_EXPANDED_STR,
	TK_QUOTED_STR
};

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*prev;
	struct s_env_list	*next;
}	t_env;

typedef struct s_info
{
	char		**temp;
	int			here_doc;
	int			mini_here_doc;
	int			here_doc_cnt;
	char		**here_documets;
	int			pipe_cnt;
	int			infile;
	int			outfile;
	char		**path;
	int			*pid;
	int			**pipe_fd;
	char		**cmd;
	int			child_status;
	char		**new_envp;
	t_env		*env_list;
	t_env		*export_list;
}	t_info;

// syntax_check
int		syntax_check(char **temp);
int		check_pattern(char **temp, int *type_list, int idx);
int		check_str_valid(char *str);
void	make_type_list(int *type_list, char **temp);

char	**remove_quote(char **temp);
int		check_remove_quote(char *str);

void	ft_error(char *str);

int		get_ird(char **temp);
int		get_ord(char **temp);
char	**cmd_get(char **temp);

void	display_str(char **str);

char	**ft_split_path(char const *s, char c);

void	get_path(t_info *info);
void	get_cmd_path(t_info *info);

int		count_pipe(char **temp);
void	setting_pipe(t_info *info);
void	wait_pid(t_info *info);

void	pipex(t_info *info);

char	*ft_strjoin(char *str1, char *str2);

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