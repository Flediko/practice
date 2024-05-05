#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *p1, *p2;
    char c[100];

    p1 = fopen("Data.txt", "r");
    if (p1 == NULL)
    {
        printf("Error opening the input file.\n");
        return 1;
    }
    p2 = fopen("Del.txt", "w");
    if (p2 == NULL) 
    {
        printf("Error creating the output file.\n");
        fclose(p1);
        return 1;
    }
    while (fscanf(p1,"%s",c) != EOF) {
        if (strcmp(c, "a") == 0 || strcmp(c, "the") == 0 || strcmp(c, "an") == 0) 
        {
            fprintf(p2," ");
        } else {
            fprintf(p2,"%s ",c);
        }
    }
    fclose(p1);
    fclose(p2);

    printf("Words filtered and written to Del.txt successfully.\n");

    return 0;
}
