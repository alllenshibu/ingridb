#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#include "ingridb_conf.h"

#include "database.h"

int create_database(char *name)
{
    char *full_path = (char *)malloc(strlen(DATABASES_LOCATION) + strlen(name) + 2);

    strcat(full_path, DATABASES_LOCATION);
    strcat(full_path, "/");
    strcat(full_path, name);

    return mkdir(full_path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
}

Database *get_all_databases()
{
    DIR *d;
    struct dirent *dir;
    Database *databases;

    d = opendir(DATABASES_LOCATION);

    if (!d)
    {
        return NULL;
    }

    databases = malloc(sizeof(Database) * 1024);

    int i = 0;
    while ((dir = readdir(d)) != NULL)
    {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;
        databases[i++].name = dir->d_name;
    }

    closedir(d);

    return databases;
}
