/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/14 16:22:39 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <readline/readline.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct s_lst
{
	char			*data;
	struct s_lst	*next;
}	t_lst;

typedef struct s_lst_info
{
	struct s_lst	*head;
	struct s_lst	*tail;
}	t_lst_info;

typedef struct s_node
{
	int				type;
	char			*str;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

# define WORD 1
# define REDIR 2
# define PIPE 3

t_node		*insert(t_node *root, char *str);
t_node		*min_node(t_node *root);
t_node		*delete(t_node *root, char *str);
void		print(t_node *root);
void		preorderprint(t_node *root);

int			check_wnull(char *str);
int			check_redir(char *str);
int			check_pipe(char *str);
int			check_str(char *str);
void		free_split(char **tmp, int i);

void		do_echo(int argc, char **argv);

void		do_pwd(int argc, char **argv);

void		do_env(char **envp);

t_lst_info	*rl_to_list(char *str);

t_lst		*new_list(char *str);
void		add_next(t_lst_info *info, char *str);
t_lst_info	*init_lst_info(void);
t_node		*list_to_tree(char *str);
#endif
