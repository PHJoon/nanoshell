/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:32:10 by chanson           #+#    #+#             */
/*   Updated: 2023/02/27 20:58:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

char	*get_one_line(t_tree *tr, int idx)
{
	struct termios	reset_term;
	struct termios	term;
	char			*line;
	int				c;
	int				cnt;

	tcgetattr(STDIN_FILENO, &term);
	tcgetattr(STDIN_FILENO, &reset_term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	line = NULL;
	cnt = 1;
	c = 0;
	tr->h_cusor.cm = tgetstr("cm", NULL);
	tr->h_cusor.ce = tgetstr("ce", NULL);
	get_cusor_start(&(tr->h_cusor));
	while (read(STDIN_FILENO, &c, sizeof(c)) > 0)
	{
		if (c == CTRL_D)
		{
			if (ft_strlen(line) == 0)
				break ;
		}
		else if (c == BACK_SPACE)
		{
			if (ft_strlen(line) > 0)
				line = fr_strdel_one(line);
			delete_end(&(tr->h_cusor));
		}
		else if (c == LEFT_ARROW)
			move_cursor_left(&(tr->h_cusor));
		else if (c == RIGHT_ARROW)
			move_cursor_right(&(tr->h_cusor));
		else if (c == UP_ARROW)
		{
			free(line);
			line = NULL;
			line = history_up_down(&(tr->h_cusor), tr->here_documets[idx], tr->history, 'u');
		}
		else if (c == DOWN_ARROW)
		{
			free(line);
			line = NULL;
			line = history_up_down(&(tr->h_cusor), tr->here_documets[idx], tr->history, 'd');
		}
		else
		{
			line = ft_strcjoin(line, (char)c);
			tr->h_cusor.col++;
			tr->h_cusor.end++;
			write(0, &c, 1);
			if (c == '\n')
				break ;
		}
		c = 0;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &reset_term);
	return (line);
}
