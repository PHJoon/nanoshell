/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:39:24 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/23 13:39:26 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

size_t	check_here_doc(char **temp)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (temp[i])
	{
		if (ft_strncmp(temp[i], "<<", 3))
			cnt++;
		i++;
	}
	return (cnt);
}

static int	make_temp_plus_check(char *temp, char *limit)
{
	size_t	len;
	char	*temp_tmp;
	char	*cmp_temp;

	len = ft_strlen(temp);
	temp_tmp = str_cp_limit(temp, len - 1);
	cmp_temp = ft_strjoin(limit, "\n");
	if (cmp_temp == NULL)
	{
		free(temp_tmp);
		return (1);
	}
	if (ft_strscmp(temp_tmp, cmp_temp))
	{
		free(temp_tmp);
		free(cmp_temp);
		return (1);
	}
	free(temp_tmp);
	free(cmp_temp);
	return (0);
}

char	*here_doc(char *limit, size_t j)
{
	int		infile;
	char	c;
	char	*tmp_file;
	char	*temp;

	c = j + '0';
	tmp_file = ft_strjoin("tmp", &c);
	infile = open(tmp_file, O_WRONLY | O_CREAT, 0644);
	if (infile < 0)
	{
		perror("infile not found");
		return (0);
	}
	while (1)
	{
		write(1, "> ", 2);
		temp = get_next_line(0);
		if (temp == 0)
		{
			write(1, "get_next_line_error\n", 20);
			return (0);
		}
		if (make_temp_plus_check(temp, limit))
			break ;
		write(infile, temp, ft_strlen(temp));
		free(temp);
	}
	close(infile);
	return (tmp_file);
}

char	**change_hrd(char **temp, char *tmp_file, size_t i)
{
	temp[i] = "<";
	temp[i + 1] = tmp_file;
	return (temp);
}


char	**do_here_doc(char **temp)
{
	size_t	cnt;
	size_t	i;
	size_t	j;
	char	*tmp_file;

	cnt = check_here_doc(temp);
	i = 0;
	j = 0;
	if (cnt == 0)
		return (0);
	while (temp[i])
	{
		if (!ft_strncmp(temp[i], "<<", 3))
		{
			tmp_file = here_doc(temp[i + 1], j);
			temp = change_hrd(temp, tmp_file, i);
			j++;
			i += 2;
		}
		else
			i++;
	}
	return (temp);
}
