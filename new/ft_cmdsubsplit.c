/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdsubsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:33:07 by ael-bako          #+#    #+#             */
/*   Updated: 2023/05/22 12:57:30 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "parser.h"

// static int count_words(const char *str, const char *delimiters) {
//     int count = 0, in_quotes = 0;
//     for (int i = 0; str[i]; i++) {
//         if (strchr("'\"", str[i])) {
//             if (!in_quotes || str[i] == in_quotes) in_quotes = 0;
//             else if (!in_quotes) in_quotes = str[i];
//         } else if (!in_quotes && !strchr(delimiters, str[i])) {
//             count++;
//             while (str[i] && !strchr(delimiters, str[i])) {
//                 if (strchr("'\"", str[i])) {
//                     if (!in_quotes || str[i] == in_quotes) in_quotes = 0;
//                     else if (!in_quotes) in_quotes = str[i];
//                 }
//                 i++;
//             }
//             i--;
//         }
//     }
//     return count;
// }

// static char **fill_array(char **words, const char *str, const char *delimiters) {
//     int in_quotes = 0, word_start = 0, i = 0;
//     for (; str[i]; i++) {
//         if (strchr("'\"", str[i])) {
//             if (!in_quotes || str[i] == in_quotes) in_quotes = 0;
//             else if (!in_quotes) in_quotes = str[i];
//         } else if (!in_quotes && !strchr(delimiters, str[i])) {
//             word_start = i;
//             while (str[i] && !strchr(delimiters, str[i])) {
//                 if (strchr("'\"", str[i])) {
//                     if (!in_quotes || str[i] == in_quotes) in_quotes = 0;
//                     else if (!in_quotes) in_quotes = str[i];
//                 }
//                 i++;
//             }
//             words[word_start] = strndup(str + word_start, i - word_start);
//             if (!words[word_start]) {
//                 for (int j = 0; j < i; j++) free(words[j]);
//                 free(words);
//                 return NULL;
//             }
//             i--;
//         }
//     }
//     return words;
// }

// char **ft_cmdsubsplit(const char *str, const char *delimiters) {
//     if (!str) return NULL;
//     int num_words = count_words(str, delimiters);
//     if (num_words < 0) return NULL;
//     char **words = calloc(num_words + 1, sizeof(char *));
//     if (!words) return NULL;
//     words = fill_array(words, str, delimiters);
//     if (!words)
//         return NULL;
//     return words;
// }



char	*substr(char const *s, unsigned int start, size_t len)
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


static int	ft_count_words(char *s, char *set, int count)
{
	int		q[2];
	int		i;

	i = 0;
	q[0] = 0;
	q[1] = 0;
	while (s && s[i] != '\0')
	{
		count++;
		if (!strchr(set, s[i]))
		{
			while ((!strchr(set, s[i]) || q[0] || q[1]) && s[i] != '\0')
			{
				q[0] = (q[0] + (!q[1] && s[i] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && s[i] == '\"')) % 2;
				i++;
			}
			if (q[0] || q[1])
				return (-1);
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_fill_array(char **aux, char *s, char *set, int i[3])
{
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	while (s && s[i[0]] != '\0')
	{
		i[1] = i[0];
		if (!strchr(set, s[i[0]]))
		{
			while ((!strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
			{
				q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2;
				i[0]++;
			}
		}
		else
			i[0]++;
		aux[i[2]++] = substr(s, i[1], i[0] - i[1]);
	}
	return (aux);
}

char	**ft_cmdsubsplit(char const *s, char *set)
{
	char	**aux;
	int		nwords;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!s)
		return (NULL);
	nwords = ft_count_words((char *)s, set, 0);
	if (nwords == -1)
		return (NULL);
	aux = malloc((nwords + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux = ft_fill_array(aux, (char *)s, set, i);
	aux[nwords] = NULL;
	return (aux);
}


// size_t	ft_strlen_2(char **s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len] != 0)
// 		len++;
// 	return (len);
// }

// int main(int ac, char  **av)
// {
//     // char *input = readline("  : ");
// 	char **str = ft_cmdsubsplit(">MAkefile >ll'<makefile'", "<|>");
// 	int len = ft_strlen_2(str);
// 	int i = 0;
// 	while (i < len)
// 	{
// 		printf("%s\n", str[i++]);
// 	}

// }
