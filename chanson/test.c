/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/03/02 20:00:51 by chanson          ###   ########.fr       */
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
	str = readline("> ");
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
	tree->env_list = make_env_list(envp);
	tree->export_list = make_export_list(envp);
	execute_heredoc(tree->top, tree, 's');
	execute_pipe(temp, tree);
	return (0);
}
