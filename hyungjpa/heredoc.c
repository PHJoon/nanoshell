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

int	check_here_doc(char **temp)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (temp[i])
	{
		if (ft_strscmp(temp[i], "<<"))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**change_hrd(char **temp, char *tmp_file, int i)
{
	temp[i] = "<";
	temp[i + 1] = tmp_file;
	return (temp);
}

char	**do_here_doc(char **temp)
{
	int		cnt;
	char	*str;

	cnt = check_here_doc(temp);
	if (cnt == 0)
		return (temp);
	do_signal_handle(HEREDOC);
	while (1)
	{
		str = readline("> ");
		signal_sigterm(str);
		free(str);
	}
	return (temp);
}
