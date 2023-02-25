/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:32:10 by chanson           #+#    #+#             */
/*   Updated: 2023/02/25 20:02:47 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void	free_pointer(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

static char	*remake_buffer(char *buffer, int idx)
{
	char	*temp_buffer;
	int		buffer_cnt;
	int		i;

	buffer_cnt = get_strllen(buffer + idx);
	if (buffer_cnt > 0)
	{
		temp_buffer = malloc(buffer_cnt + 1);
		i = 0;
		while (buffer[idx])
		{
			temp_buffer[i] = buffer[idx];
			idx++;
			i++;
		}
		free_pointer(buffer);
		temp_buffer[i] = '\0';
		return (temp_buffer);
	}
	if (get_strllen(buffer) > 0)
		free_pointer(buffer);
	return (0);
}

char	*make_line(char *buffer, char **line, int fd, char *temp)
{
	int		cnt;
	int		idx;

	cnt = 1;
	while (cnt)
	{
		printf("line > buffer: %s, temp: %s\n", buffer, temp);
		idx = get_strchr(buffer, '\n');
		if (idx != -1)
		{
			*line = get_strdup(buffer, idx);
			buffer = remake_buffer(buffer, idx + 1);
			return (buffer);
		}
		cnt = read(fd, temp, BUFFER_SIZE);
		if (cnt < 0)
			break ;
		temp[cnt] = '\0';
		buffer = get_strjoin(buffer, temp);
	}
	if (cnt > -1)
		*line = get_strdup(buffer, get_strchr(buffer, '\0'));
	free(buffer);
	buffer = NULL;
	return (buffer);
}

char	*get_one_line(int fd)
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
	while (cnt > 0)
	{
		cnt = read(STDIN_FILENO, &c, 1);
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
			return ;
		else if (c == DOWN_ARROW)
			return ;
		else
		{
			line = ft_strcjoin(line, (char)c);
			if (c == '\n')
				break ;
		}
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &reset_term);
	return (line);
}
