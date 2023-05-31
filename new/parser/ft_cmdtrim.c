/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:54:57 by ael-bako          #+#    #+#             */
/*   Updated: 2023/05/31 10:01:28 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>

#include <stdlib.h>
#include "parser.h"

char    **ft_cmdtrim(const char *str, const char *delimiters)
{
    char **tokens = NULL;
    int num_tokens = 0;
    int in_quote = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        while (strchr(delimiters, str[i]) != NULL)
            i++;
        int start = i;
        while (str[i] != '\0')
        {
            if (!in_quote && strchr(delimiters, str[i]) != NULL)
                break;

            if (str[i] == '\'' || str[i] == '\"')
                in_quote = !in_quote;

            i++;
        }
        if (i > start)
        {
            char *token = malloc((i - start + 1) * sizeof(char));
            strncpy(token, &str[start], i - start);
            token[i - start] = '\0';

            tokens = realloc(tokens, (num_tokens + 1) * sizeof(char *));
            tokens[num_tokens] = token;
            num_tokens++;
        }
    }
    tokens = realloc(tokens, (num_tokens + 1) * sizeof(char *));
    tokens[num_tokens] = NULL;

    return tokens;
}
