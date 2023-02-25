/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_canonical_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:22:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/24 16:22:23 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

struct termios	set_normal_mode(void)
{
	struct termios	normal_term;

	tcgetattr(STDIN_FILENO, &normal_term);
	normal_term.c_lflag &= ICANON;
	normal_term.c_lflag &= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &normal_term);
	return (normal_term);
}

struct termios	set_heredoc_mode(void)
{
	struct termios	hd_term;

	tcgetattr(STDIN_FILENO, &hd_term);
	hd_term.c_lflag &= ~(ICANON);
	hd_term.c_cc[VMIN] = 1;
	hd_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &hd_term);
	return (hd_term);
}

void	reset_normal_mode(struct termios normal_term)
{
	normal_term.c_lflag &= ICANON;
	normal_term.c_lflag &= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &normal_term);
}
