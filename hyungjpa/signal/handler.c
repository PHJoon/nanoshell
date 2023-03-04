/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:04:50 by chanson           #+#    #+#             */
/*   Updated: 2023/03/04 14:34:05 by chanson          ###   ########.fr       */
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
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
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
		if (status == CHILD)
			on_off_catch_signals(1);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
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
	printf("exit\n");
	exit(0);
}
