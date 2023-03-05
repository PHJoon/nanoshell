/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/03/04 21:16:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/test.h"

int	g_signal_flag = 0;

int	main(int argc, char **argv, char **envp)
{
	t_tree	*tree;

	(void)argc;
	(void)argv;
	tree = tree_preset(envp);
	start_minishell(tree);
	return (0);
}
