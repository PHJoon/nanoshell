/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/02/26 17:58:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	char	*temp_hist;
	char	**temp;
	char	**history;
	t_tree	*tree;

	(void)argc;
	(void)argv;
	signal(SIGQUIT, SIG_IGN);
	history = NULL;
	// 반복문
	str = readline("> ");
	temp_hist = ft_strcpy(str);
	temp_hist = ft_strcjoin(temp_hist, '\n');
	history = ft_strsjoin(history, temp_hist);
	free(temp_hist);
	temp = ft_split(str);
	if (syntax_err_check(temp) == FALSE)
	{
		free(str);
		printf("syntax_err\n");
		return (1);
	}
	tree = init_tree(temp);
	tree->history = history;
	free(str);
	tree->pipe_cnt = count_pipe(temp);
	cnt_heredoc(tree->top, tree);
	tree->here_documets = (char **)malloc(sizeof(char *) * \
		(tree->here_doc_cnt));
	tree->envp_val = envp;
	execute_heredoc(tree->top, tree, 's');
	display_tree(tree->top, 's');
	return (0);
}
