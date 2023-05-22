
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
// extern int	g_status;

// char	*expand_path(char *str, int i, int quotes[2], char *var)
// {
// 	char	*path;
// 	char	*aux;

// 	quotes[0] = 0;
// 	quotes[1] = 0;
// 	while (str && str[++i])
// 	{
// 		quotes[0] = (quotes[0] + (!quotes[1] && str[i] == '\'')) % 2;
// 		quotes[1] = (quotes[1] + (!quotes[0] && str[i] == '\"')) % 2;
// 		if (!quotes[0] && !quotes[1] && str[i] == '~' && (i == 0 || \
// 			str[i - 1] != '$'))
// 		{
// 			aux = ft_substr(str, 0, i);
// 			path = ft_strjoin(aux, var);
// 			free(aux);
// 			aux = ft_substr(str, i + 1, ft_strlen(str));
// 			free(str);
// 			str = ft_strjoin(path, aux);
// 			free(aux);
// 			free(path);
// 			return (expand_path(str, i + ft_strlen(var) - 1, quotes, var));
// 		}
// 	}
// 	free(var);
// 	return (str);
// }
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*s3;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (s3 == NULL)
		return (NULL);
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			s3[i] = s1[i];
		if (i < len_s2)
			s3[i + len_s1] = s2[i];
		i++;
	}
	s3[len_s1 + len_s2] = '\0';
	return (s3);
}
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
		if (!strncmp(envp[i], var, n2))
			return (ft_substr(envp[i], n2 + 1, strlen(envp[i])));
		i++;
	}
	return (NULL);
}

static char	*get_substr_var(char *str, int i, t_prompt *prompt)
{
	char	*aux;
	int		pos;
	char	*path;
	char	*var;

	pos = ft_strchars_i(&str[i], "|\"\'$?>< ") + (ft_strchr("$?", str[i]) != 0);
	if (pos == -1)
		pos = ft_strlen(str) - 1;
	aux = ft_substr(str, 0, i - 1);
	var = mini_env(&str[i], prompt->envp, \
		ft_strchars_i(&str[i], "\"\'$|>< "));
	if (!var && str[i] == '$')
		var = ft_itoa(prompt->pid);
	else if (!var && str[i] == '?')
		var = ft_itoa(5);
	path = ft_strjoin(aux, var);
	free(aux);
	aux = ft_strjoin(path, &str[i + pos]);
	free(var);
	free(path);
	free(str);
	return (aux);
}

char	*expand_vars(char *str, int i, int quotes[2], t_prompt *prompt)
{
	quotes[0] = 0;
	quotes[1] = 0;
	while (str && str[++i])
	{
		quotes[0] = (quotes[0] + (!quotes[1] && str[i] == '\'')) % 2;
		quotes[1] = (quotes[1] + (!quotes[0] && str[i] == '\"')) % 2;
		if (!quotes[0] && str[i] == '$' && str[i + 1] && \
			((ft_strchars_i(&str[i + 1], "/~%^{}:; ") && !quotes[1]) || \
			(ft_strchars_i(&str[i + 1], "/~%^{}:;\"") && quotes[1])))
			return (expand_vars(get_substr_var(str, ++i, prompt), -1, \
				quotes, prompt));
	}
	return (str);
}




char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = strlen(s);
	i = 0;
	if (len > s_len)
		len = s_len;
	if (start >= s_len)
	{
		substr = (char *)malloc(1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (i++ < start)
		s++;
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}


int	ft_strchr_i(const char *s, int c)
{
	unsigned char	c_unsigned;
	int				i;

	i = 0;
	if (!s)
		return (-1);
	c_unsigned = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c_unsigned)
			return (i);
		i++;
	}
	if (c_unsigned == '\0')
		return (i);
	return (-1);
}



char	*expand_path(char *str, int i, int quotes[2], char *var)
{
	char	*path;
	char	*aux;

	quotes[0] = 0;
	quotes[1] = 0;
	while (str && str[++i])
	{
		quotes[0] = (quotes[0] + (!quotes[1] && str[i] == '\'')) % 2;
		quotes[1] = (quotes[1] + (!quotes[0] && str[i] == '\"')) % 2;
		if (!quotes[0] && !quotes[1] && str[i] == '~' && (i == 0 || \
			str[i - 1] != '$'))
		{
			aux = ft_substr(str, 0, i);
			path = ft_strjoin(aux, var);
			free(aux);
			aux = ft_substr(str, i + 1, strlen(str));
			// free(str);
			str = ft_strjoin(path, aux);
			free(aux);
			free(path);
			printf("%s\t %lu \n", str, i + strlen(var) - 1);
			return (expand_path(str, i + strlen(var) - 1, quotes, var));
		}
	}
	free(var);
	return (str);
}


int main(int ac, char **av, char **env)
{
	int quotes[2];
	t_prompt *prompt;
	printf("%s\n", expand_vars("~/src", -1, quotes, prompt));
	// system("leaks a.out");
}

