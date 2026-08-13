#include <stdio.h>

int main()
{
    FILE *fp;

    int id;
    char name[50];
    char version[20];

    fp = fopen("data/Package_repo.txt", "r");

    if(fp == NULL)
    {
        printf("Package repository file not found!\n");
        return 0;
    }

    printf("\n====================================\n");
    printf("          PACKAGE REPOSITORY\n");
    printf("====================================\n\n");

    printf("%-10s %-20s %-10s\n",
           "ID",
           "PACKAGE",
           "VERSION");

    printf("------------------------------------------------\n");

    while(fscanf(fp,
                 "%d %49s %19s",
                 &id,
                 name,
                 version) == 3)
    {
        printf("%-10d %-20s %-10s\n",
               id,
               name,
               version);
    }

    fclose(fp);

    return 0;
}
