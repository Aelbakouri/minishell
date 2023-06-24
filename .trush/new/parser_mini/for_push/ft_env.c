/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchaf <ibouchaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:57:21 by ibouchaf          #+#    #+#             */
/*   Updated: 2023/06/08 20:12:12 by ibouchaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"

void	ft_env(char **env)
{
	int i ;
	char **str;
	str = ft_dup_matrix(env);
	i = 0;
	if ()
	while(str[i] != NULL)
		printf("%s\n",str[++i]);
}

int main(int ac, char **av, char **env)
{
	ft_env(env);
}
