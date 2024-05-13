#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigit(char c) {
    return c >= '0' && c <= '9';
}

int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    FILE *p1, *p2;
    char line[1000];
    int c, d;
    p1=fopen("File.txt", "r");
    if (p1==NULL)
    {
        printf("Error opening the input file.\n");
        return 1;
    }
    p2=fopen("Count.txt", "w");
    if (p2==NULL)
    {
        printf("Error creating the output file.\n");
        fclose(p1);
        return 1;
    }
    while (fgets(line, sizeof(line), p1) != NULL) 
    {
        c=d=0;
        for (int i = 0; line[i] != '\0'; i++) 
        {
            if (isLetter(line[i])) 
            {
                c++;
            } 
            else if (isDigit(line[i])) 
            {
                d++;
            }
        }
        fprintf(p2, "Characters: %d, Digits: %d\n",c,d);
    }
    fclose(p1);
    fclose(p2);
    printf("Character and digit counts written to Count.txt successfully.\n");
    return 0;
}
