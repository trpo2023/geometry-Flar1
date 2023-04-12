#include <circle.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE* file;
    file = fopen("./data.txt", "r");
    if (fopen("./data.txt", "r") == NULL) {
        printf("File not found\n");
        exit(0);
    }
    char str1[100];
    int countObj = 0;

    while (fgets(str1, 99, file)) {
        countObj++;
        strtolower(str1);
        int v = printErrors(str1, countObj);
        for (; v < 1; v++) {
            char radius[10];
            for (int i = 7; i != strlen(str1); i++) {
                if (str1[i] == ',') {
                    int j = 0;
                    i = i + 1;
                    for (int z = i; str1[z] != ')'; z++) {
                        radius[j] = str1[z];
                        j++;
                    }
                }
            }
            double rad = atof(radius);
            double per = 2 * M_PI * rad;
            double plosh = M_PI * rad * rad;
            printf(" perimetr = %.4lf\n", per);
            printf(" area = %.4lf\n", plosh);
            zeero(radius);
        }
    }
    fclose(file);
    return 0;
}