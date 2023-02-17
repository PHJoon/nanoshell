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

void	off_catch_signals(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 0;
}

void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (signo == SIGQUIT)
		return ;
}

void	signal_handle(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}

void	signal_sigterm(char *str)
{
	if (str != NULL)
		return ;
	printf("exit\n");
	exit(0);
}
