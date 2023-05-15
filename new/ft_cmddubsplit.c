/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmddubsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:33:07 by ael-bako          #+#    #+#             */
/*   Updated: 2023/05/15 12:42:02 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int count_words(const char *str, const char *delimiters) {
    int count = 0, in_quotes = 0;
    for (int i = 0; str[i]; i++) {
        if (strchr("'\"", str[i])) {
            if (!in_quotes || str[i] == in_quotes) in_quotes = 0;
            else if (!in_quotes) in_quotes = str[i];
        } else if (!in_quotes && !strchr(delimiters, str[i])) {
            count++;
            while (str[i] && !strchr(delimiters, str[i])) {
                if (strchr("'\"", str[i])) {
                    if (!in_quotes || str[i] == in_quotes) in_quotes = 0;
                    else if (!in_quotes) in_quotes = str[i];
                }
                i++;
            }
            i--;
        }
    }
    return count;
}

static char **fill_array(char **words, const char *str, const char *delimiters) {
    int in_quotes = 0, word_start = 0, i = 0;
    for (; str[i]; i++) {
        if (strchr("'\"", str[i])) {
            if (!in_quotes || str[i] == in_quotes) in_quotes = 0;
            else if (!in_quotes) in_quotes = str[i];
        } else if (!in_quotes && !strchr(delimiters, str[i])) {
            word_start = i;
            while (str[i] && !strchr(delimiters, str[i])) {
                if (strchr("'\"", str[i])) {
                    if (!in_quotes || str[i] == in_quotes) in_quotes = 0;
                    else if (!in_quotes) in_quotes = str[i];
                }
                i++;
            }
            words[word_start] = strndup(str + word_start, i - word_start);
            if (!words[word_start]) {
                for (int j = 0; j < i; j++) free(words[j]);
                free(words);
                return NULL;
            }
            i--;
        }
    }
    return words;
}

char **cmdsubsplit(const char *str, const char *delimiters) {
    if (!str) return NULL;
    int num_words = count_words(str, delimiters);
    if (num_words < 0) return NULL;
    char **words = calloc(num_words + 1, sizeof(char *));
    if (!words) return NULL;
    words = fill_array(words, str, delimiters);
    if (!words) return NULL;
    return words;
}


size_t	ft_strlen_2(char **s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

int main(int ac, char  **av)
{
    // char *input = readline("  : ");
	char **str = cmdsubsplit(av[1], "<|>");
	int len = ft_strlen_2(str);
	int i = 0;
	while (i < len)
	{
		printf("%s\n", str[i++]);
	}

}
