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

char	*cd_dot_dot(char *buf_tmp, char *slash, size_t *i)
{
	size_t	slash_idx;
	size_t	num;
	char	*tmp;

	if (ft_strscmp(slash, ".."))
		num = 2;
	else
		num = 3;
	*i += num;
	if (ft_strlen(buf_tmp) == 1)
		return (buf_tmp);
	if (buf_tmp[ft_strlen(buf_tmp) - 1] == '/')
	{
		tmp = ft_strcpy_index(buf_tmp, 0, ft_strlen(buf_tmp) - 2);
		free(buf_tmp);
		buf_tmp = tmp;
	}
	slash_idx = ft_strrchr(buf_tmp, '/');
	tmp = ft_strcpy_index(buf_tmp, 0, slash_idx);
	free(buf_tmp);
	buf_tmp = tmp;
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
	else if (slash_idx == ft_strlen(&str[*i]))
		buf_tmp = ft_strcjoin(buf_tmp, '/');
	j = 0;
	while (j < slash_idx)
	{
		buf_tmp = ft_strcjoin(buf_tmp, str[*i + j]);
		j++;
	}
	*i += j;
	return (buf_tmp);
}

char	*add_back_slash(char *buf_tmp, char *slash, size_t *i)
{
	if (buf_tmp[ft_strlen(buf_tmp) - 1] != '/')
		buf_tmp = ft_strcjoin(buf_tmp, '/');
	if (ft_strscmp(slash, "./"))
		*i += 2;
	else
		*i += 1;
	return (buf_tmp);
}

char	*check_cd_argv(char *str, char *cwd_buf)
{
	char	*buf_tmp;
	size_t	i;

	i = 0;
	buf_tmp = ft_strdup(cwd_buf);
	free(cwd_buf);
	while (str[i])
	{
		if (ft_strscmp(&str[i], "."))
			buf_tmp = add_back_slash(buf_tmp, ".", &i);
		else if (ft_strscmp(&str[i], "./"))
			buf_tmp = add_back_slash(buf_tmp, "./", &i);
		else if (ft_strscmp(&str[i], ".."))
			buf_tmp = cd_dot_dot(buf_tmp, "..", &i);
		else if (ft_strscmp(&str[i], "../"))
			buf_tmp = cd_dot_dot(buf_tmp, "../", &i);
		else
			buf_tmp = cd_not_dot(buf_tmp, str, &i);
	}
	return (buf_tmp);
}

void	do_cd(char **str, t_env_list *env_list)
{
	char	*cwd_buf;

	if (!ft_strscmp(str[0], "cd"))
		return ;
	if (str_size(str) > 2)
		return ;
	cwd_buf = (char *)malloc(sizeof(char) * 1024);
	cwd_buf = getcwd(cwd_buf, 1024);
	if (str[1])
	{
		cwd_buf = check_cd_argv(str[1], cwd_buf);
		chdir(cwd_buf);
	}
	else
		cd_home(env_list);
	free(cwd_buf);
}
