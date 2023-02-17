/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 17:13:55 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

int	main(int argc, char **argv, char **envp)
{
	char		*str;
	char		**temp;
	t_node		*head;
	t_ast		*root;
	t_env_list	*env_list;

	(void)argc;
	(void)argv;
	off_catch_signals();
	signal_handle();
	root = NULL;
	env_list = make_env_list(envp);
	// while (env_list)
	// {
	// 	printf("%s : %s\n", env_list->key, env_list->value);
	// 	env_list = env_list->next;
	// }
	while (1)
	{
		str = readline("nanoshell$ ");
		signal_sigterm(str);
		temp = ft_split(str);
		head = trans_to_list(temp);
		root = list_to_ast(root, head, 7);
		free(str);
	}
	return (0);
}
