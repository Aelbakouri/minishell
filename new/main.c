#include "parser.h"

int main(int ac, char **av, char **env)
{
	printf(":%d:\t%ld\n", malloc_len(av[1]), strlen(av[1]));
}
