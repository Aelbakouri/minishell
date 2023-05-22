#include "parser.h"

size_t	ft_strlen_2(char **s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

int main(int ac, char **av, char **env)
{
	char **strtrim = split_string(readline("$minishell: "), " ");
	int len = ft_strlen_2(strtrim), i = -1, quotes[2];

	while (strtrim[++i])
	{
		strtrim[i] = expand_vars(strtrim[i], -1, quotes, env);
		strtrim[i] = expand_path(strtrim[i], -1, quotes, mini_env("HOME", env, 4));
		ft_subsplit
	}
	
	i = -1;
	while (strtrim[++i])
		printf(":%s:\n", strtrim[i]);
}
