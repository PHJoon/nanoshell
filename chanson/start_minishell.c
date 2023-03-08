/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:24:11 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/08 19:27:08 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/test.h"

static char	**split_and_syntax_check(char *str)
{
	char	**temp;

	temp = ft_split(str);
	if (syntax_err_check(temp) == FALSE)
	{
		printf("syntax error\n");
		ft_free_str(temp);
		temp = NULL;
	}
	return (temp);
}

static int	_start_minishell(t_tree *tree, char ***temp, char *str)
{
	if (*temp == NULL)
	{
		free(str);
		return (FALSE);
	}
	free(str);
	tree = init_tree(*temp, tree);
	_init_heredoc_and_pipe(tree, temp);
	return (TRUE);
}

void	start_minishell(t_tree *tree)
{
	char			*str;
	char			**temp;

	set_mode(tree);
	while (1)
	{
		do_signal_handle(PARENT);
		tree = tree_set_re(tree);
		str = readline("minishell$ ");
		signal_sigterm(str);
		add_history(str);
		if (str[0] == 0)
		{
			free(str);
			continue ;
		}
		tree->history = ft_strsjoin(tree->history, ft_strcpy(str));
		temp = split_and_syntax_check(str);
		if (_start_minishell(tree, &temp, str) == FALSE)
			continue ;
		g_signal_flag = 0;
	}
}
