#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN_STRUCT
{
    enum
    {
        TOKEN_ID,
        TOKEN_STRING,
        // TOKEN_SEMI,
        TOKEN_PIPE,
        // TOKEN_BACKGROUND,
        TOKEN_VAR,
        TOKEN_FLAG,
        TOKEN_INPUT,
        TOKEN_OUTPUT,
        TOKEN_ERR
    } type;

    char* value;
} token_T;

token_T* init_token(int type, char* value);
#endif
