/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:54:57 by ael-bako          #+#    #+#             */
/*   Updated: 2023/05/22 01:05:22 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>

#include <stdlib.h>
#include "parser.h"

// int main() {
//     char* input;

//     // Use readline to read input from the user
//     input = readline("  : ");

//     // Add the input to the history
//     // add_history(input);

//     // Print the input
//     printf("You entered: %s\n", input);

//     // Free the memory used by the input
//      free(input);

//     return 0;
// }

char **split_string(const char *str, const char *delimiters)
{
    char **tokens = NULL;
    int num_tokens = 0;
    int in_quote = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        // Skip leading delimiters
        while (strchr(delimiters, str[i]) != NULL)
            i++;

        // Start of a new token
        int start = i;

        // Find end of token
        while (str[i] != '\0')
        {
            if (!in_quote && strchr(delimiters, str[i]) != NULL)
                break;

            if (str[i] == '\'' || str[i] == '\"')
                in_quote = !in_quote;

            i++;
        }

        // If the token is non-empty, add it to the array
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

    // Add a NULL terminator to the end of the array
    tokens = realloc(tokens, (num_tokens + 1) * sizeof(char *));
    tokens[num_tokens] = NULL;

    return tokens;
}

// int main(int ac, char  **av)
// {
//     char *input = readline("  : ");
// 	char **str = split_string(input, " ");
// 	int len = ft_strlen_2(str);
// 	int i = 0;
// 	while (i < len)
// 	{
// 		printf("%s\n", str[i++]);
// 	}

// }
