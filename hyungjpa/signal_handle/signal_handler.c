/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:15:49 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 19:15:50 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"
// cc signal_handler.c signal_handler.h -L/Users/hyungjpa/.brew/opt/readline/lib -lreadline -I/Users/hyungjpa/.brew/opt/readline/include/

void	on_off_catch_signals(int on_off)
{
	extern int	rl_catch_signals;

	rl_catch_signals = on_off;
}

void	parent_sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	do_signal_handle(int status)
{
	if (status == PARENT)
	{
		signal(SIGINT, parent_sig_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (status == CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (status == HEREDOC)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}

void	signal_sigterm(char *str)
{
	if (str != NULL)
		return ;
	printf("exit\n");
	exit(0);
}
