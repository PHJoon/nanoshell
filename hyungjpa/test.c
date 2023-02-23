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
	// t_env_list	*env_list;
	t_env_list	*export_list;
	char		*pwd[2] = {"pwd", 0};
	char		*cd[3] = {"cd", "././../utils/", 0};
	char		*export[3] = {"export", "a=b", 0};

	(void)argc;
	(void)argv;
	(void)envp;
	off_catch_signals();
	signal_handle();
	do_pwd(pwd);
	do_cd(cd);
	export_list = make_export_list(envp);
	do_export(export, export_list);
	// env_list = make_env_list(envp);
	// env_list = do_unset(env_list, "PATH");
	while (1)
	{
		root = NULL;
		str = readline("nanoshell$ ");
		signal_sigterm(str);
		temp = ft_split(str);
		head = trans_to_list(temp);
		root = list_to_ast(root, head, 7);
		display_ast(root);
		free_ast(root);
		free_node(head);
		ft_free_str(temp);
		free(str);
	}
	return (0);
}
