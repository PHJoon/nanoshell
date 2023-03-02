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

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->temp = NULL;
	info->here_doc = 0;
	info->mini_here_doc = 0;
	info->here_doc_cnt = 0;
	info->here_documets = NULL;
	info->pipe_cnt = 0;
	info->infile = 0;
	info->outfile = 0;
	info->pid = NULL;
	info->pipe_fd = NULL;
	info->cmd = NULL;
	info->new_envp = NULL;
	info->env_list = NULL;
	info->export_list = NULL;
	return (info);
}

int	main(int argc, char **argv, char **envp)
{
	char		*str;
	t_info		*info;

	(void)argc;
	(void)argv;
	on_off_catch_signals(OFF);
	do_signal_handle(PARENT);
	info = init_info();
	info->env_list = make_env_list(envp);
	info->export_list = make_export_list(envp);
	info->new_envp = envp;
	get_path(info);
	while (1)
	{
		str = readline("nanoshell$ ");
		signal_sigterm(str);
		info->temp = ft_split_syntax(str);
		if (!syntax_check(info->temp))
		{
			printf("syntax error\n");
			continue ;
		}
		info->temp = remove_quote(info->temp);
		info->pipe_cnt = count_pipe(info->temp);
		setting_pipe(info);
		pipex(info);
		ft_free_str(info->temp);
		add_history(str);
		free(str);
	}
	return (0);
}
