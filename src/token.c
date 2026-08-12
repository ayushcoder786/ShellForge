#include <stdio.h>
#include <string.h>
#include "token.h"

int tokenize(char *input, Token tokens[])
{
    int count = 0;

    char *token = strtok(input, " \t\n");

    while (token != NULL && count < MAX_TOKENS)
    {
        strcpy(tokens[count].value, token);

        // Assign token type based on character content
        if (strcmp(token, "|") == 0)
        {
            tokens[count].type = TOKEN_PIPE;
        }
        else if (strcmp(token, "<") == 0)
        {
            tokens[count].type = TOKEN_INPUT;
        }
        else if (strcmp(token, ">") == 0)
        {
            tokens[count].type = TOKEN_OUTPUT;
        }
        else
        {
            tokens[count].type = TOKEN_WORD;
        }

        count++;
        token = strtok(NULL, " \t\n");
    }

    return count;
}

void print_tokens(Token tokens[], int count)
{
    printf("\n========== Tokens ==========\n");

    for (int i = 0; i < count; i++)
    {
        switch (tokens[i].type)
        {
            case TOKEN_PIPE:
                printf("%d : PIPE     %s\n", i, tokens[i].value);
                break;
            case TOKEN_INPUT:
                printf("%d : INPUT    %s\n", i, tokens[i].value);
                break;
            case TOKEN_OUTPUT:
                printf("%d : OUTPUT   %s\n", i, tokens[i].value);
                break;
            case TOKEN_WORD:
            default:
                printf("%d : WORD     %s\n", i, tokens[i].value);
                break;
        }
    }

    printf("%d : END      END\n", count);
    printf("============================\n");
}
