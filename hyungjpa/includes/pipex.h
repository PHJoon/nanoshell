/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:11:09 by chanson           #+#    #+#             */
/*   Updated: 2023/01/19 20:41:41 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "get_next_line.h"

# define FAIL		0
# define SUCCESS	1
# define READ		0
# define WRITE		1

typedef struct s_pipex
{
	int		pipe_a[2];
	int		pipe_b[2];
	int		indirection;
	int		outdirection;
	int		infile;
	int		outfile;
	char	**cmd1;
	char	**cmd2;
	char	**path;
}	t_pipex;


char	*ft_strjoin(char *str1, char *str2);
char	*str_cp_limit(char *str, size_t idx);


char	**do_here_doc(char **temp);

#endif
