// #include "include/parser.h"
// #include "include/lexer.h"

// char	*get_path(char *cmd, char **env)
// {
// 	char	*path;
// 	char	*dir;
// 	char	*bin;
// 	int		i;

// 	i = 0;
// 	while (env[i] && str_ncmp(env[i], "PATH=", 5))
// 		i++;
// 	if (!env[i])
// 		return (cmd);
// 	path = env[i] + 5;
// 	while (path && str_ichr(path, ':') > -1)
// 	{
// 		dir = str_ndup(path, str_ichr(path, ':'));
// 		bin = join_path(dir, cmd);
// 		free(dir);
// 		if (access(bin, F_OK) == 0)
// 			return (bin);
// 		free(bin);
// 		path += str_ichr(path, ':') + 1;
// 	}
// 	return (cmd);
// }

// t_prompt	parser()
// {
// 	lexer_T* lexer = init_lexer(readline("minishell$ "));
// 	token_T* token = (void*)0;

// 	while ((token = lexer_get_next_token(lexer)) != (void*)0)
// 	{
// 		if (token->value[0] == '$' || token->value[0] == '~')
// 			printf("TOKEN(%d, '%s')\n", token->type, expand_variable(token->value));
// 		else
// 			printf("TOKEN(%d, '%s')\n", token->type, token->value);
// 	}
// }
