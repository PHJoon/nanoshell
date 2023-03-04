/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/03/04 20:16:05 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/test.h"

static void	start_cmd(t_tree *tree, char **temp)
{
	if (tree->pipe_cnt > 0)
		execute_pipe(temp, tree);
	else
		execute_no_pipe(temp, tree);
}

static void	_init_heredoc_and_pipe(t_tree *tree, char ***temp, char **envp)
{
	tree->pipe_cnt = count_pipe(*temp);
	cnt_heredoc(tree->top, tree);
	tree->here_documets = (char **)malloc(sizeof(char *) * \
		(tree->here_doc_cnt + 1));
	tree->here_documets[tree->here_doc_cnt] = NULL;
	tree->envp_val = envp;
	execute_heredoc(tree->top, tree, 's');
	ft_free_str(*temp);
	*temp = NULL;
	heredoc_sum(tree->top, temp);
	display_tree(tree->top, 's');
	start_cmd(tree, *temp);
	ft_free_tree(tree);
	ft_free_str(*temp);
	*temp = NULL;
}

static void	main_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	on_off_catch_signals(0);
	do_signal_handle(PARENT);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	char	**temp;
	t_tree	*tree;

	(void)argc;
	(void)argv;
	main_signal();
	tree = (t_tree *)malloc(sizeof(t_tree));
	if (!tree)
		ft_error("malloc error\n");
	tree->env_list = make_env_list(envp);
	tree->export_list = make_export_list(envp);
	while (1)
	{
		str = readline("minishell$ ");
		signal_sigterm(str);
		add_history(str);
		temp = ft_split(str);
		if (syntax_err_check(temp) == FALSE)
			ft_error("syntax error\n");
		tree = init_tree(temp, tree);
		free(str);
		_init_heredoc_and_pipe(tree, &temp, envp);
	}
	return (0);
}
