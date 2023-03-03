/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/03/03 20:49:46 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/test.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	char	**temp;
	t_tree	*tree;

	(void)argc;
	(void)argv;
	signal(SIGQUIT, SIG_IGN);
	on_off_catch_signals(0);
	// 반복문
	str = readline("minishell> ");
	add_history(str);
	temp = ft_split(str);
	if (syntax_err_check(temp) == FALSE)
	{
		free(str);
		printf("syntax_err\n");
		return (1);
	}
	tree = init_tree(temp);
	free(str);
	tree->pipe_cnt = count_pipe(temp);
	cnt_heredoc(tree->top, tree);
	tree->here_documets = (char **)malloc(sizeof(char *) * \
		(tree->here_doc_cnt + 1));
	tree->here_documets[tree->here_doc_cnt] = NULL;
	tree->envp_val = envp;
	execute_heredoc(tree->top, tree, 's');
	ft_free_str(temp);
	temp = NULL;
	heredoc_sum(tree->top, &temp);
	// display_str(temp);
	tree->env_list = make_env_list(envp);
	// tree->export_list = make_export_list(envp);
	// display_list_envp(tree->export_list);
	// printf("\n\n-----------------------------\n\n");
	// display_str(temp);
	if (tree->pipe_cnt > 0)
		execute_pipe(temp, tree);
	else
		execute_no_pipe(temp, tree);
	// ft_free_tree(tree);
	return (0);
}
