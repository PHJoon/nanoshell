/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:15:49 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/04 14:33:06 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

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
