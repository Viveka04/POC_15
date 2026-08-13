#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 250

typedef struct
{
    int id;
    char name[50];
    char version[20];
} Package;

Package packages[MAX_PACKAGES];
int packageCount = 0;

int graph[MAX_PACKAGES][MAX_PACKAGES] = {0};

/* Load Packages from Repository */
void loadPackages()
{
    FILE *fp;

    fp = fopen("data/Package_repo.txt", "r");

    if(fp == NULL)
    {
        printf("Package repository file not found!\n");
        return;
    }

    while(fscanf(fp,
                 "%d %49s %19s",
                 &packages[packageCount].id,
                 packages[packageCount].name,
                 packages[packageCount].version) == 3)
    {
        packageCount++;
    }

    fclose(fp);
}

/* Find Package Name using ID */
char* getPackageName(int id)
{
    for(int i = 0; i < packageCount; i++)
    {
        if(packages[i].id == id)
        {
            return packages[i].name;
        }
    }

    return "UNKNOWN";
}

/* Build Dependency Graph */
void buildDependencyGraph()
{
    FILE *fp;

    int src;
    int dest;

    fp = fopen("data/Dependency_matrix.txt", "r");

    if(fp == NULL)
    {
        printf("Dependency file not found!\n");
        return;
    }

    printf("\n========================================\n");
    printf("          DEPENDENCY GRAPH\n");
    printf("========================================\n");

   while(fscanf(fp, "%d %d", &src, &dest) == 2)
{
   

    graph[src][dest] = 1;

    printf("%s (%d) -> %s (%d)\n",
           getPackageName(src),
           src,
           getPackageName(dest),
           dest);
}

    fclose(fp);

    printf("\nDependency Graph Loaded Successfully.\n");
}

int main()
{
    loadPackages();

    if(packageCount == 0)
    {
        printf("No packages available in repository.\n");
        return 0;
    }

    buildDependencyGraph();

    return 0;
}