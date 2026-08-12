#ifndef TOKEN_H
#define TOKEN_H

#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 100

// 1. Define the different token types
typedef enum {
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_INPUT,
    TOKEN_OUTPUT,
    TOKEN_END
} TokenType;

// 2. Add the TokenType to your struct
typedef struct
{
    TokenType type;
    char value[MAX_TOKEN_SIZE];
} Token;

int tokenize(char *input, Token tokens[]);
void print_tokens(Token tokens[], int count);

#endif
