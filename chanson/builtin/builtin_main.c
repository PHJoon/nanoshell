/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:17:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

int	cd_echo_env_check(char **temp, t_env *env_list)
{
	int	cd_check;
	int	echo_check;
	int	env_check;

	cd_check = do_cd(temp, env_list);
	echo_check = do_echo(temp, env_list);
	env_check = do_env(temp, env_list);
	if (cd_check != 1)
		return (cd_check);
	if (echo_check != 1)
		return (echo_check);
	if (env_check != 1)
		return (env_check);
	return (1);
}

int	export_pwd_unset_check(char **temp, t_env *env_list, t_env *export_list)
{
	int	export_check;
	int	pwd_check;
	int	unset_check;

	export_check = do_export(temp, &export_list, &env_list);
	pwd_check = do_pwd(temp);
	unset_check = do_unset(temp, &env_list, &export_list);
	if (export_check != 1)
		return (export_check);
	if (pwd_check != 1)
		return (pwd_check);
	if (unset_check != 1)
		return (unset_check);
	return (1);
}

int	builtin(char **temp, t_env *env_list, t_env *export_list)
{
	int	exit_check;
	int	check_1;
	int	check_2;

	check_1 = cd_echo_env_check(temp, env_list);
	if (check_1 != 1)
		return (check_1);
	check_2 = export_pwd_unset_check(temp, env_list, export_list);
	if (check_2 != 1)
		return (check_1);
	exit_check = do_exit(temp);
	if (exit_check != 0)
		return (exit_check);
	exit(0);
	return (exit_check);
}
