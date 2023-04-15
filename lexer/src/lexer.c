#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


lexer_T* init_lexer(char* contents)
{
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->i = 0;
    lexer->c = contents[lexer->i];

    return lexer;
}

void lexer_advance(lexer_T* lexer)
{
    if (lexer->c != '\0' && lexer->i < strlen(lexer->contents))
    {
        lexer->i += 1;
        lexer->c = lexer->contents[lexer->i];
    }
}

token_T* lexer_get_next_token(lexer_T* lexer)
{
    while (lexer->c && lexer->i < strlen(lexer->contents))
    {
        while (lexer->c == ' ' || lexer->c == 10)
            lexer_advance(lexer);
        if (lexer->c == '"' || lexer->c == '\'')
            return lexer_collect_string(lexer);
        if (lexer->c == '|' || lexer->c == '<' || lexer->c == '>')
            return lexer_collect_id(lexer, lexer->c);
        if (lexer->c)
            return lexer_collect_id(lexer, 0);
    }
    return 0;
}

token_T* lexer_collect_string(lexer_T* lexer)
{
    char c = lexer->c;
    lexer_advance(lexer);

    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (lexer->c != c)
    {
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);
        lexer_advance(lexer);
    }
    lexer_advance(lexer);

    return init_token(TOKEN_STRING, value);
}

token_T* lexer_collect_id(lexer_T* lexer, char c)
{
    char* value = calloc(2, sizeof(char));
    int token = get_token_id(lexer->c);
    value[0] = c;
    value[1] = 0;
    while (lexer->c != ' ' && lexer->c != 10 && lexer->c && !c)
    {
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);
        lexer_advance(lexer);
    }
        lexer_advance(lexer);

    return init_token(token, value);
}

int get_token_id(char c)
{
    int token;

    if (isalnum(c))
        token = TOKEN_ID;
    else if (c == '|')
        token = TOKEN_PIPE;
    else if (c == '$')
        token = TOKEN_VAR;
    else if (c == '-')
        token = TOKEN_FLAG;
    else if (c == '<')
        token = TOKEN_INPUT;
    else if (c == '~')
        token = TOKEN_TILDE;
    else if (c == '>')
        token = TOKEN_OUTPUT;
    else
        token = TOKEN_ERR;
    return token;
}

token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token)
{
    lexer_advance(lexer);

    return token;
}

char* lexer_get_current_char_as_string(lexer_T* lexer)
{
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';

    return str;
}
