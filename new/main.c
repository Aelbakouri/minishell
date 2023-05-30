/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:16:53 by ael-bako          #+#    #+#             */
/*   Updated: 2023/05/30 14:14:39 by ael-bako         ###   ########.fr       */
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
// int ft_len(char **t)
// {
// 	int i = -1, len = 0, j;

// 	while (t[++i])
// 	{
// 		j = -1;
// 		while (t[i][++j])
// 			len++
// 	}
// 	return len;
// }

// char *join_t(char **t)
// {
// 	char	*str;

// 	while ()
// }

int	main(int argc, char **argv, char **envp)
{
	char				*out;
	t_prompt			prompt;
	t_prompt			*p;
	t_list				*cmds;
	t_mini				*mini;
	int					i;

	prompt = init_prompt(argv, envp);
	while (argv && argc)
	{
		out = readline("minishell: ");
		if (!(p = check_args(out, &prompt)))
			break ;
		cmds = p->cmds;
		while (cmds)
		{
			mini = cmds->content;
			i = -1;
			printf("full_cmd: ");
			while (mini->full_cmd[++i])
				printf("%s; ",mini->full_cmd[i]);
			printf("\tinfile: %d\t outfile: %d\t full_path: %s\n", mini->infile, mini->outfile, mini->full_path);
			cmds = cmds->next;
		}
	}
	// exit(g_status);
}
