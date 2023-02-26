/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:32:10 by chanson           #+#    #+#             */
/*   Updated: 2023/02/26 21:43:43 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

char	*get_one_line(int fd, t_tree *tree, int index)
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
	while (cnt > 0)
	{
		cnt = read(STDIN_FILENO, &c, sizeof(c));
		if (c == CTRL_D)
		{
			if (ft_strlen(line) == 0)
				break ;
		}
		else if (c == BACK_SPACE)
		{
			if (ft_strlen(line) > 0)
				line = fr_strdel_one(line);
		}
		else if (c == LEFT_ARROW)
			return ;
		else if (c == RIGHT_ARROW)
			return ;
		else if (c == UP_ARROW)
			history_up(tree, tree->here_documets[index]);
		else if (c == DOWN_ARROW)
			history_down(tree, tree->here_documets[index]);
		else
		{
			line = ft_strcjoin(line, (char)c);
			write(0, &c, 1);
			if (c == '\n')
				break ;
		}
		c = 0;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &reset_term);
	return (line);
}
