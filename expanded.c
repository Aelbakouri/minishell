/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:45:23 by ael-bako          #+#    #+#             */
/*   Updated: 2023/04/15 02:20:37 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>

int main() {
  char *var = "~dfhdsg";
  char *home_dir;
  char *username = "ael-bako";
  struct passwd *pw;

  if (var[0] == '$') {
    // If the variable starts with a $ character, expand it using getenv
    char *env_var = var + 1;
    home_dir = getenv(env_var);
  } else if (var[0] == '~') {
    // If the variable starts with a ~ character, expand it to the user's home directory
    if (strlen(var) > 1) {
      // If there are characters after the ~, treat them as the username
    //   username = var + 1;
    }
    pw = getpwnam(username);
    home_dir = pw->pw_dir;
    printf("there an err\n");
  } else {
    // If the variable doesn't start with $ or ~, just use its value
    home_dir = var;
  }

  printf("Expanded variable: %s\n", home_dir);

  return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <pwd.h>

// char* expand_variable(char *var)
// {
// 	char	*home_dir;
// 	char	*username = "ael-bako";
// 	struct passwd *pw;

// 	if (!var)
// 		return " ";
// 	if (var[0] == '$')
// 	{
// 		// If the variable starts with a $ character, expand it using getenv
// 		if (strlen(var) == 1)
// 			return "$";
// 		char *env_var = var + 1;
// 		home_dir = getenv(env_var);
// 	}
// 	else if (var[0] == '~')
// 	{
// 		printf("hello\n");
// 		// If the variable starts with a ~ character, expand it to the user's home directory
// 		if (strlen(var) > 1)
// 		{
// 			// If there are characters after the ~, treat them as the username
// 			username = var + 1;
// 		}
// 		pw = getpwnam(username);
// 		if (!pw)
// 			return "var";
// 		home_dir = pw->pw_dir;
// 	}
// 	else
// 	{
// 		// If the variable doesn't start with $ or ~, just use its value
// 		home_dir = var;
// 	}
// 	return home_dir;
// }

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	char *expanded = expand_variable(av[1]);
// 	// if (av[1][0] == '/')
// 	// 	printf("%s\n", av[1]);
// 	printf("Expanded variablee :%s:\n", expanded);
// 	return 0;
// }




// char* expand_tilde(const char* path) {
//     if (path == NULL) {
//         return NULL;
//     }

//     if (path[0] == '~') {
//         const char* username = NULL;
//         const char* home_dir = NULL;
//         struct passwd* pw = NULL;

//         if (strlen(path) > 1) {
//             username = path + 1;
//         } else {
//             username = getenv("Users");
//             if (username == NULL) {
//                 username = getpwuid(getuid())->pw_name;
//             }
//         }

//         pw = getpwnam(username);
//         if (pw == NULL) {
//             return NULL;
//         }
//         home_dir = pw->pw_dir;

//         size_t home_len = strlen(home_dir);
//         size_t path_len = strlen(path);
//         char* result = malloc(home_len + path_len);

//         if (result == NULL) {
//             return NULL;
//         }

//         memcpy(result, home_dir, home_len);
//         memcpy(result + home_len, path + 1, path_len - 1);
//         result[home_len + path_len - 1] = '\0';
//         return result;
//     } else {
//         // No tilde expansion necessary, just return the input path
//         return strdup(path);
//     }
// }

// #include <stdio.h>
// #include <wordexp.h>

// int main(int argc, char* argv[]) {
//     // wordexp_t exp_result;
//     // wordexp(argv[1], &exp_result, 0);
//     printf("%s\n", expand_tilde("~"));
// }

// #include <stdio.h>
// #include <pwd.h>

// int main() {
//     struct passwd *pw = getpwnam("ael-bako");
//     if (pw == NULL) {
//         printf("Could not get user information\n");
//     } else {
//         printf("Username: %s\n", pw->pw_name);
//         printf("UID: %d\n", pw->pw_uid);
//         printf("GID: %d\n", pw->pw_gid);
//         printf("Home directory: %s\n", pw->pw_dir);
//         printf("Login shell: %s\n", pw->pw_shell);
//     }
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <readline/readline.h>

// int main() {
//     char *input;

//     // Read a line of input from the user using readline
//     input = readline("Enter a string: ");

//     // Print the input string
//     printf("You entered: %s\n", input);

//     // Free the memory allocated by readline
//     free(input);

//     return 0;
// }
