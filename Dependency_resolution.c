#include <stdio.h>
#include <string.h>

#define MAX 250

typedef struct
{
    int id;
    char name[50];
    char version[20];
} Package;

Package packages[MAX];
int visited[MAX];
int graph[MAX][MAX];

int packageCount = 0;

/* Load Package Repository */
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

/* Get Package Name */
char *getPackageName(int id)
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

/* Load Dependency Graph */
void loadGraph()
{
    FILE *fp;

    int src, dest;

    fp = fopen("data/Dependency_matrix.txt", "r");

    if(fp == NULL)
    {
        printf("Dependency file not found!\n");
        return;
    }

    while(fscanf(fp, "%d %d", &src, &dest) == 2)
    {
        graph[src][dest] = 1;
    }

    fclose(fp);
}

/* Display Dependencies */
void resolveDependencies(int packageId)
{
    visited[packageId] = 1;

    for(int i = 0; i < MAX; i++)
    {
        if(graph[packageId][i] && !visited[i])
        {
            printf("%s (%d)\n",
                   getPackageName(i),
                   i);

            resolveDependencies(i);
        }
    }
}

int main()
{
    int packageId;

    loadPackages();

    loadGraph();

    printf("\n====================================\n");
    printf("      DEPENDENCY RESOLUTION\n");
    printf("====================================\n");

    printf("Enter Package ID: ");
    scanf("%d", &packageId);

    printf("\nSelected Package : %s\n\n",
       getPackageName(packageId));

printf("All Required Dependencies\n\n");

for(int i = 0; i < MAX; i++)
{
    visited[i] = 0;
}

resolveDependencies(packageId);

return 0;
}