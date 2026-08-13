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

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];

int top = -1;
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

/* Topological DFS */
void topoSort(int node)
{
    visited[node] = 1;

    for(int i = 0; i < MAX; i++)
    {
        if(graph[node][i] && !visited[i])
        {
            topoSort(i);
        }
    }

    stack[++top] = node;
}

int main()
{
    int packageId;

    loadPackages();
    loadGraph();

    printf("\n====================================\n");
    printf("       INSTALLATION ORDER\n");
    printf("====================================\n");

    printf("Enter Package ID: ");
    scanf("%d", &packageId);

    for(int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
    }

    topoSort(packageId);

    printf("\nSelected Package : %s\n",
           getPackageName(packageId));

    printf("\nInstallation Sequence\n\n");

    /* Print dependencies first */
    for(int i = 0; i <= top; i++)
    {
        printf("%s (%d)\n",
               getPackageName(stack[i]),
               stack[i]);
    }

    return 0;
}