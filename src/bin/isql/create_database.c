#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#include "ingridb_conf.h"

int create_database(char *name)
{
    char *full_path = (char *)malloc(strlen(DATABASES_LOCATION) + strlen(name) + 2);

    strcat(full_path, DATABASES_LOCATION);
    strcat(full_path, "/");
    strcat(full_path, name);

    return mkdir(full_path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
}

int main(int argc, char *argv[])
{
    create_database(argv[1]);

    return 0;
}