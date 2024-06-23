#ifndef DATABASE_H
#define DATABASE_H

typedef struct
{
    char *name;
} Database;

int create_database(char *name);
Database *get_all_databases();

#endif
