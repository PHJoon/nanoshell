/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/02/25 20:07:12 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	char	*temp_here;
	char	**temp;
	t_tree	*tree;
	int		history;

	(void)argc;
	(void)argv;
	signal(SIGQUIT, SIG_IGN);
	history = open("history", O_WRONLY | O_CREAT, 0644);
	// 반복문
	str = readline("> ");
	temp_here = ft_strcpy(str);
	temp_here = ft_strcjoin(temp_here, '\n');
	write(history, temp_here, ft_strlen(temp_here));
	temp = ft_split(str);
	if (syntax_err_check(temp) == FALSE)
	{
		free(str);
		printf("syntax_err\n");
		return (1);
	}
	tree = init_tree(temp, history);
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
