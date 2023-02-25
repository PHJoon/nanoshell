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
	t_env	*env_list;
	t_env	*export_list;
	// t_node	*head;
	// t_ast	*root;

	(void)argc;
	(void)argv;
	on_off_catch_signals(OFF);
	do_signal_handle(PARENT);
	export_list = make_export_list(envp);
	env_list = make_env_list(envp);
	while (1)
	{
		str = readline("nanoshell$ ");
		signal_sigterm(str);
		temp = ft_split_syntax(str);
		if (!syntax_check(temp))
		{
			printf("syntax error\n");
			continue ;
		}
		temp = do_here_doc(temp);
		do_signal_handle(PARENT);
		temp = remove_quote(temp);
		printf("%d\n", builtin(temp, env_list, export_list));
		// dispaly_str(temp);
		// root = NULL;
		// head = trans_to_list(temp);
		// root = list_to_ast(root, head, 7);
		// display_ast(root);
		// free_ast(root);
		// free_node(head);
		ft_free_str(temp);
		add_history(str);
		free(str);
	}
	return (0);
}
