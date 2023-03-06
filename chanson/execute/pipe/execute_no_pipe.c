/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_no_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:34:55 by chanson           #+#    #+#             */
/*   Updated: 2023/03/06 21:43:06 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	_execute_cmd(t_tree *tree)
{
	int	builtin_num;

	g_signal_flag = 1;
	do_signal_handle(CHILD);
	if (tree->infile != 0)
	{
		if (dup2(tree->infile, STDIN_FILENO) == -1)
			ft_error("dup2 error1\n");
	}
	if (tree->outfile != 0)
	{
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error2\n");
	}
	builtin_num = builtin(tree);
	if (builtin_num != 1)
		exit(builtin_num);
	else
	{
		if (execve(tree->cmd.cmd_head, tree->cmd.cmd_arr, tree->envp_val) == -1)
			ft_error("cmd option error child\n");
	}
}

void	change_env_val(char **pure_cmd, t_tree *tree)
{
	int	i;

	i = 0;
	while (pure_cmd[i])
	{
		if (ft_str_find_c(pure_cmd[i], '$') > -1)
			pure_cmd[i] = change_env(tree->envp_val, pure_cmd[i]);
		i++;
	}
}

void	execute_no_pipe(char **temp, t_tree *tree)
{
	int		pid;
	char	**pure_cmd;

	pure_cmd = cmd_get(temp);
	pure_cmd = ft_erase_null(pure_cmd);
	change_env_val(pure_cmd, tree);
	cmd_check(tree, pure_cmd);
	if (tree->cmd.cmd_head == NULL)
		printf("cmd not valid: %s\n", tree->cmd.cmd_arr[0]);
	tree->infile = get_ird(temp);
	tree->outfile = get_ord(temp);
	if (pure_cmd[0] == NULL)
		return ;
	pid = fork();
	if (pid == 0)
		_execute_cmd(tree);
	else
	{
		do_signal_handle(WAIT_CHILD);
		waitpid(pid, &tree->child_status, 0);
	}
}
