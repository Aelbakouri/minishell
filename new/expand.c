/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:54:54 by ael-bako          #+#    #+#             */
/*   Updated: 2023/05/15 11:58:18 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// Function to expand a single variable reference and replace it with its value
char* expand_variable(char* var) {
    char* expanded_var = NULL;
    char* home_dir;
    char* username = getenv("ael-bako"); // Get the current user's username
    struct passwd* pw;

    if (!var) {
        return NULL;
    }

    if (var[0] == '$') {
        if (strlen(var) == 1) {
            return strdup("$"); // Return a copy of the string "$"
        }
        char* env_var = var + 1;
        char* env_value = getenv(env_var);
        if (env_value != NULL) {
            expanded_var = strdup(env_value); // Return a copy of the environment variable's value
        }
    } else if (var[0] == '~') {
        if (strlen(var) == 1 || var[1] == '/') {
            // Expand to home directory of the current user
            home_dir = getenv("HOME");
        } else {
            // Expand to home directory of a specific user
            username = var + 1;
            pw = getpwnam(username);
            if (pw != NULL) {
                home_dir = pw->pw_dir;
            }
        }
        if (home_dir != NULL) {
            size_t len = strlen(home_dir) + strlen(var) - 1; // Calculate length of the expanded variable
            expanded_var = malloc(len + 1); // Allocate memory for the expanded variable
            snprintf(expanded_var, len + 1, "%s%s", home_dir, var + 1); // Copy the expanded variable into the allocated memory
        }
    } else {
        expanded_var = strdup(var); // Return a copy of the input string
    }

    return expanded_var;
}

int main(int ac, char **av)
{
	printf("%s\n", expand_variable("$PWD"));
}
