#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/history.h>
#include <readline/readline.h>

#include "history.h"
#include "token.h"

int main(void)
{
    // Display welcome banner
    printf("=========\n");
    printf("      Shellforge\n");
    printf(" A Unix Style Shell written in C\n");
    printf("=========\n");

    // Initialize history
    using_history();

    char *line;

    while (1)
    {
        line = readline("shellforge$ ");

        if (line == NULL)
        {
            printf("\nGoodbye!\n");
            break;
        }

        // Ignore empty input
        if (strlen(line) == 0)
        {
            free(line);
            continue;
        }

        // History command
        if (strcmp(line, "history") == 0)
        {
            print_history();
            free(line);
            continue;
        }

        // Add command to history
        add_history(line);

        // Print entered command
        printf(" YOU ENTERED : %s\n", line);

        // Exit command
        if (strcmp(line, "exit") == 0)
        {
            free(line);
            printf("Exiting...\n");
            break;
        }

        // Tokenize the input
        Token tokens[MAX_TOKENS];

        int count = tokenize(line, tokens);

        // Print tokens
        print_tokens(tokens, count);

        free(line);
    }

    return 0;
}
