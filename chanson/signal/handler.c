/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:04:50 by chanson           #+#    #+#             */
/*   Updated: 2023/03/05 21:13:08 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	on_off_catch_signals(int on_off)
{
	extern int	rl_catch_signals;

	rl_catch_signals = on_off;
}

void	main_sigint(int signo)
{
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	hd_clear(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		exit(130);
	}
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
		signal(SIGINT, SIG_DFL);
		if (status == CHILD)
			signal(SIGQUIT, SIG_DFL);
		else
			signal(SIGQUIT, SIG_IGN);
	}
	else if (status == WAIT_CHILD)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	signal_sigterm(char *str)
{
	if (str != NULL)
		return ;
	write(1, "exit\n", 5);
	exit(0);
}
