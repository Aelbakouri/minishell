/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:45:23 by ael-bako          #+#    #+#             */
/*   Updated: 2023/04/12 18:49:11 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <pwd.h>

// int main() {
//   char *var = "$PATH";
//   char *home_dir;
//   char *username = "john";
//   struct passwd *pw;

//   if (var[0] == '$') {
//     // If the variable starts with a $ character, expand it using getenv
//     char *env_var = var + 1;
//     home_dir = getenv(env_var);
//   } else if (var[0] == '~') {
//     // If the variable starts with a ~ character, expand it to the user's home directory
//     if (strlen(var) > 1) {
//       // If there are characters after the ~, treat them as the username
//       username = var + 1;
//     }
//     pw = getpwnam(username);
//     home_dir = pw->pw_dir;
//   } else {
//     // If the variable doesn't start with $ or ~, just use its value
//     home_dir = var;
//   }

//   printf("Expanded variable: %s\n", home_dir);

//   return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>

char* expand_variable(char *var)
{
	char	*home_dir;
	char	*username = "john";
	struct passwd *pw;

	if (!var)
		return " ";
	if (var[0] == '$')
	{
		// If the variable starts with a $ character, expand it using getenv
		char *env_var = var + 1;
		home_dir = getenv(env_var);
	}
	else if (var[0] == '~')
	{
		// If the variable starts with a ~ character, expand it to the user's home directory
		if (strlen(var) > 1)
		{
			// If there are characters after the ~, treat them as the username
			username = var + 1;
		}
		pw = getpwnam(username);
		home_dir = pw->pw_dir;
	}
	else
	{
		// If the variable doesn't start with $ or ~, just use its value
		home_dir = var;
	}

	return home_dir;
	}

int main(int ac, char **av)
{
	(void)ac;
  char *expanded = expand_variable(av[1]);
  printf("Expanded variable: %s\n", expanded);
  return 0;
}
