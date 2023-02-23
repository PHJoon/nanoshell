/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:54:11 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/18 17:54:13 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

char	*cd_dot_dot(char	*buf_tmp, size_t *i)
{
	size_t	slash_idx;
	char	*tmp;

	if (buf_tmp[ft_strlen(buf_tmp) - 1] == '/')
	{
		tmp = ft_substr(buf_tmp, 0, ft_strlen(buf_tmp) - 1);
		free(buf_tmp);
		buf_tmp = tmp;
	}
	slash_idx = ft_strrchr(buf_tmp, '/');
	tmp = ft_substr(buf_tmp, 0, slash_idx + 1);
	free(buf_tmp);
	buf_tmp = tmp;
	*i += 3;
	return (buf_tmp);
}

char	*cd_not_dot(char *buf_tmp, char *str, size_t *i)
{
	size_t	slash_idx;
	size_t	j;

	slash_idx = ft_strchr(&str[*i], '/');
	if (slash_idx == 0)
	{
		buf_tmp = ft_strcjoin(buf_tmp, '/');
		(*i)++;
		slash_idx = ft_strchr(&str[*i], '/');
	}
	j = 0;
	while (j < slash_idx)
	{
		buf_tmp = ft_strcjoin(buf_tmp, str[*i + j]);
		j++;
	}
	*i += j;
	return (buf_tmp);
}

char	*check_cd_argv(char *str)
{
	char	*cwd_buf;
	char	*buf_tmp;
	size_t	i;

	i = 0;
	cwd_buf = getcwd(NULL, 0);
	buf_tmp = ft_strdup(cwd_buf);
	free(cwd_buf);
	while (str[i])
	{
		if (!ft_strncmp(&str[i], "./", 2))
		{
			if (buf_tmp[ft_strlen(buf_tmp) - 1] != '/')
				buf_tmp = ft_strcjoin(buf_tmp, '/');
			i += 2;
		}
		else if (!ft_strncmp(&str[i], "../", 3))
			buf_tmp = cd_dot_dot(buf_tmp, &i);
		else
			buf_tmp = cd_not_dot(buf_tmp, str, &i);
	}
	return (buf_tmp);
}

void	do_cd(char **str)
{
	size_t	i;
	char	*cwd_buf;

	i = 1;
	if (!ft_strscmp(str[0], "cd"))
		return ;
	if (str_size(str) > 2)
		return ;
	cwd_buf = check_cd_argv(str[1]);
	chdir(cwd_buf);
	printf("%s\n", cwd_buf);
	free(cwd_buf);
}
