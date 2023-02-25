/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:16:06 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 19:16:08 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <signal.h>
# include <termios.h>

# define OFF 0
# define ON 1
# define PARENT 2
# define CHILD 3
# define HEREDOC 4

void	on_off_catch_signals(int on_off);
void	parent_sig_handler(int signo);
void	do_signal_handle(int status);
void	signal_sigterm(char *str);
void	child_signal_handle(void);

#endif
