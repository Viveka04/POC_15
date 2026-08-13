#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;

    char package1[50];
    char version1[20];

    char package2[50];
    char version2[20];

    int conflictCount = 0;

    fp = fopen("data/Conflict_data.txt", "r");

    if(fp == NULL)
    {
        printf("Conflict data file not found!\n");
        return 0;
    }

    printf("\n====================================\n");
    printf("      CONFLICT DETECTION\n");
    printf("====================================\n");

    while(fscanf(fp,
                 "%s %s %s %s",
                 package1,
                 version1,
                 package2,
                 version2) == 4)
    {
        if(strcmp(package1, package2) == 0 &&
           strcmp(version1, version2) != 0)
        {
            printf("\nConflict Detected\n");
            printf("-----------------\n");

            printf("Package  : %s\n", package1);

            printf("Versions : %s and %s\n",
                   version1,
                   version2);

            conflictCount++;
        }
    }

    fclose(fp);

    printf("\n------------------------------------\n");
    printf("Total Conflicts Found : %d\n",
           conflictCount);

    return 0;
}
