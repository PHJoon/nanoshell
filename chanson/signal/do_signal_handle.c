/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_signal_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:42:41 by chanson           #+#    #+#             */
/*   Updated: 2023/03/06 21:22:25 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	sig_handler_ctrl_c(int signo)
{
	pid_t	pid;

	(void)signo;
	pid = 0;
	write(1, "\n\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	kill(pid, SIGCONT);
	exit(130);
}

void	do_signal_handle(int status)
{
	if (status == PARENT)
	{
		on_off_catch_signals(0);
		if (g_signal_flag == 0)
			signal(SIGINT, main_sigint);
		else
			signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (status == CHILD || status == HEREDOC)
	{
		on_off_catch_signals(1);
		if (status == CHILD)
			signal(SIGINT, sig_handler_ctrl_c);
		if (status == HEREDOC)
			signal(SIGINT, sig_heredoc_ctrl_c);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (status == WAIT_CHILD)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
