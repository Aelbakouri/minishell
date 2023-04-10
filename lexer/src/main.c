#include <stdio.h>
#include "include/lexer.h"

int	main(int ac, char **av)
{
	lexer_T* lexer = init_lexer("echo \"hello      there\" how are 'you 'doing? $USER |wc -l >outfile");
	token_T* token = (void*)0;

	while ((token = lexer_get_next_token(lexer)) != (void*)0)
		printf("TOKEN(%d, '%s')\n", token->type, token->value);
}
