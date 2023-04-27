#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circle.h"

int main()
{
    FILE *file;
    file = fopen("./data.txt", "r");
    if (file == NULL)
    {
        printf("File not found\n");
        exit(0);
    }
    char str1[100];
    int countObj = 0;

    while (fgets(str1, 99, file))
    {
        countObj++;
        str_to_lower(str1);
        int v = print_errors(str1, countObj);
        for (; v < 1; v++)
        {
            calc_per_and_area(str1);
        }
    }
    fclose(file);
    return 0;
}