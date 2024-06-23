#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "ingridb_conf.h"

int show_databases()
{

    DIR *databases;
    struct dirent *database;

    databases = opendir(DATABASES_LOCATION);

    if (!databases)
    {
        return -1;
    }

    while ((database = readdir(databases)) != NULL)
    {
        if (strcmp(database->d_name, ".") == 0 || strcmp(database->d_name, "..") == 0)
            continue;
        printf("%s\n", database->d_name);
    }
}

int main()
{
    show_databases();

    return 0;
}