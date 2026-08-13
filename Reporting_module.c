#include <stdio.h>

int countPackages()
{
    FILE *fp;
    int count = 0;

    int id;
    char name[50];
    char version[20];

    fp = fopen("data/Package_repo.txt", "r");

    if(fp == NULL)
    {
        return 0;
    }

    while(fscanf(fp,
                 "%d %49s %19s",
                 &id,
                 name,
                 version) == 3)
    {
        count++;
    }

    fclose(fp);

    return count;
}

int countDependencies()
{
    FILE *fp;
    int count = 0;

    int src, dest;

    fp = fopen("data/Dependency_matrix.txt", "r");

    if(fp == NULL)
    {
        return 0;
    }

    while(fscanf(fp,
                 "%d %d",
                 &src,
                 &dest) == 2)
    {
        count++;
    }

    fclose(fp);

    return count;
}

int countConflicts()
{
    FILE *fp;
    int count = 0;

    char package1[50];
    char version1[20];

    char package2[50];
    char version2[20];

    fp = fopen("data/Conflict_data.txt", "r");

    if(fp == NULL)
    {
        return 0;
    }

    while(fscanf(fp,
                 "%s %s %s %s",
                 package1,
                 version1,
                 package2,
                 version2) == 4)
    {
        count++;
    }

    fclose(fp);

    return count;
}

int countCycles()
{
    FILE *fp;
    int count = 0;

    int src, dest;

    fp = fopen("data/Cycle_test.txt", "r");

    if(fp == NULL)
    {
        return 0;
    }

    while(fscanf(fp,
                 "%d %d",
                 &src,
                 &dest) == 2)
    {
        count++;
    }

    fclose(fp);

    return count > 0 ? 1 : 0;
}

int main()
{
    int packages;
    int dependencies;
    int conflicts;
    int cycles;

    packages = countPackages();
    dependencies = countDependencies();
    conflicts = countConflicts();
    cycles = countCycles();

    printf("\n====================================\n");
    printf("         PROJECT REPORT\n");
    printf("====================================\n\n");

    printf("Packages Processed : %d\n",
           packages);

    printf("Dependencies Found : %d\n",
           dependencies);

    printf("Conflicts Found    : %d\n",
           conflicts);

    printf("Cycles Found       : %d\n",
           cycles);

    if(cycles == 0)
    {
        printf("Status             : Success\n");
    }
    else
    {
        printf("Status             : Warning (Cycle Detected)\n");
    }

    printf("\nReport Generated Successfully.\n");

    return 0;
}