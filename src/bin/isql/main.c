#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "database.h"

int process_command(char *input)
{
    char *options = strtok(input, "");

    if (options[1] == 'l')
    {
        Database *databases = get_all_databases();

        for (int i = 0; i < 1024; i++)
        {
            if (databases[i].name == NULL)
                break;

            printf("%s\n", databases[i].name);
        }

        free(databases);
    }
    else
    {
        printf("Invalid command\n");
        return 1;
    }

    return 0;
}

int main()
{
    char *input = malloc(1024 * sizeof(char));

    do
    {
        printf("isql> ");
        fgets(input, 1024, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (input[0] == '\\')
        {
            process_command(input);
        }

    } while (strcmp(input, "exit") != 0);

    free(input);
    return 0;
}