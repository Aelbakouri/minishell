# ifndef PARSER_H
# define PARSER_H

# define STDIN 0
# define STDOUT 1

typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
}		t_prompt;

typedef struct s_list
{
	char	**full_cmd;
	char	*full_path;
	int	infile;
	int	outfile;
}		t_list;

# endif
