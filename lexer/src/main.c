#include <stdio.h>
#include "include/lexer.h"
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
		if (strlen(var) == 1)
			return "$";
		char *env_var = var + 1;
		home_dir = getenv(env_var);
	}
	else if (var[0] == '~')
	{
		if (strlen(var) > 1)
			username = var + 1;
		// pw = getpwnam(username);
		// if (!pw)
		// 	return var;
		// home_dir = pw->pw_dir;
	}
	else
		home_dir = var;
	return home_dir;
}


int	main(int ac, char **av)
{
	lexer_T* lexer = init_lexer("echo \"hello  it's  ~  there\" ~ <how are $RC 'you 'doing? $USER |wc -l >outfile");
	token_T* token = (void*)0;

	printf("hello %s\n", expand_variable("~0"));
	while ((token = lexer_get_next_token(lexer)) != (void*)0)
	{
		// if (token->value[0] == '$' || token->value[0] == '~')
		// printf("hello %s\n", expand_variable(token->value));
			// printf("TOKEN(%d, '%s')\n", token->type, expand_variable(token->value));
			printf("TOKEN(%d, '%s')\n", token->type, token->value);
	}
}
