/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:24:11 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/06 14:06:24 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/test.h"

static char	**split_and_syntax_check(char *str)
{
	char	**temp;

	temp = ft_split(str);
	if (syntax_err_check(temp) == FALSE)
		ft_error("syntax error\n");
	return (temp);
}

void	start_minishell(t_tree *tree)
{
	char	*str;
	char	**temp;

	while (1)
	{
		do_signal_handle(PARENT);
		tree = tree_set_re(tree);
		str = readline("minishell$ ");
		signal_sigterm(str);
		if (str[0] == 0)
		{
			free(str);
			continue ;
		}
		temp = split_and_syntax_check(str);
		add_history(str);
		free(str);
		tree = init_tree(temp, tree);
		_init_heredoc_and_pipe(tree, &temp);
		g_signal_flag = 0;
	}
}
