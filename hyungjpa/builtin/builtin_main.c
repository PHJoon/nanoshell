/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:17:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/24 11:17:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	builtin(char **temp, t_env_list *env_list, t_env_list *export_list)
{
	do_cd(temp, env_list);
	do_echo(temp, env_list);
	do_env(temp, env_list);
	do_export(temp, &export_list, &env_list);
	do_pwd(temp);
	do_unset(temp, &env_list, &export_list);
	do_exit(temp);
}
