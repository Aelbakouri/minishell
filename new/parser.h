# ifndef PARSER_H
# define PARSER_H

# define STDIN 0
# define STDOUT 1

# include "libft/inc/libft.h"
# include <string.h>
# include <stdio.h>


typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
}		t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int	infile;
	int	outfile;
}		t_mini;

char	*expand_path(char *str, int i, int quotes[2], char *var);
static char	*get_substr_var(char *str, int i, char **env);
char	*expand_vars(char *str, int i, int quotes[2], char **env);
char	*mini_env(char *var, char **envp, int n);
int	malloc_len(char const *s1);
char	*ft_strtrim_all(char const *s1, int squote, int dquote);


# endif
