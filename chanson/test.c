/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/02/23 15:03:07 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	tree_execute_heredoc(t_token *node, t_tree *tree)
{
	if (node->type == TK_STR)
		return ;
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	char	**temp;
	t_tree	*tree;

	str = readline("> ");
	temp = ft_split(str);
	if (syntax_check(temp) == FALSE)
	{
		printf("syntax error\n");
		free(str);
		return (1);
	}
	tree = init_tree(temp);
	display_tree(tree->top, 's');
	free(str);
	tree->pipe_cnt = count_pipe(temp);
	cnt_heredoc(tree->top, tree);
	tree->here_documets = (char **)malloc(sizeof(char *) * \
		(tree->here_doc_cnt));
	tree->envp_val = envp;
	execute_heredoc(tree->top, tree, 's');
	printf("---------------------------\n\n");
	display_tree(tree->top, 's');
	return (0);
}
