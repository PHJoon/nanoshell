/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 17:13:55 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	main(void)
{
	char	*str;
	char	**temp;
	int		i;
	t_node	*head;
	t_ast	*root;

	str = readline("> ");
	temp = ft_split(str);
	i = 0;
	head = trans_to_list(temp);
	root = list_to_ast(root, head, 8);
	inorderprint(root);
	// printf("---res---\n");
	// print_list(res);
	// printf("---res---\n");
	// printf("---left---\n");
	// print_list(left);
	// printf("---left---\n");
	// printf("---right---\n");
	// print_list(right);
	// printf("---right---\n");
	// if (syntax_check(temp) == FALSE)
	// {
	// 	printf("syntax error\n");
	// 	return (1);
	// }
	return (0);
}
