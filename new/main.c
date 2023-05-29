/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:16:53 by ael-bako          #+#    #+#             */
/*   Updated: 2023/05/29 10:20:41 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_prompt	init_prompt(char **argv, char **envp)
{
	t_prompt	prompt;

	prompt.cmds = NULL;
	prompt.envp = ft_dup_matrix(envp);
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	char				*out;
	t_prompt			prompt;
	t_prompt			*p;
	t_list				*cmds;

	prompt = init_prompt(argv, envp);
	while (argv && argc)
	{
		out = readline("minishell: ");
		if (!(p = check_args(out, &prompt)))
			break ;
		
		while ()
	}
	// exit(g_status);
}
