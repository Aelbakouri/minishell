#include "parser.h"

int main(int ac, char **av, char **env)
{
	int quotes[2];
	t_prompt *prompt;
	char *str;
	str = ft_strdup("~");
	printf("%s\n", expand_vars(av[1], -1, quotes, env));
}
