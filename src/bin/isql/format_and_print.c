int format_and_print(int number_of_columns, char *columns[], int number_of_values, char *values[][number_of_columns])
{
    int i, j;

    for (i = 0; i < number_of_columns; i++)
    {
        printf("%s\t", columns[i]);
    }
    printf("\n");

    for (i = 0; i < number_of_values; i++)
    {
        for (j = 0; j < number_of_columns; j++)
        {
            printf("%s\t", values[i][j]);
        }
        printf("\n");
    }

    return 0;
}