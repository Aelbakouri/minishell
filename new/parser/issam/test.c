// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     char* username = getenv("USER");

//     if (username != NULL) {
//         printf("Username: %s\n", username);
//     } else {
//         printf("Unable to retrieve username.\n");
//     }

//     return 0;
// }
#include "libft/inc/libft.h"

char	*mini_env(char *var, char **envp, int n)
{
	int	i;
	int	n2;

	i = 0;
	if (n < 0)
		n = strlen(var);
	while (!strchr(var, '=') && envp && envp[i])
	{
		n2 = n;
		if (n2 < ft_strchr_i(envp[i], '='))
			n2 = ft_strchr_i(envp[i], '=');
		if (!ft_strncmp(envp[i], var, n2))
			return (ft_substr(envp[i], n2 + 1, strlen(envp[i])));
		i++;
	}
	return (NULL);
}

int main(int ac, char **av, char **env)
{
		char **str = ft_split(mini_env("PWD", env, 3), '/');
		if (!ft_strncmp(mini_env("PWD", env, 3), mini_env("HOME", env, 4), ft_strlen(mini_env("HOME", env, 4)) + 1))

		printf("\033[32;1m➜  \033[36;1m%s\n", str[ft_strlen_2(str) - 1]);


}
