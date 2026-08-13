#include <stdio.h>

#define MAX 250

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];

/* DFS Function */
int dfs(int node)
{
    visited[node] = 1;
    recStack[node] = 1;

    for(int i = 0; i < MAX; i++)
    {
        if(graph[node][i])
        {
            if(!visited[i])
            {
                if(dfs(i))
                {
                    return 1;
                }
            }
            else if(recStack[i])
            {
                return 1;
            }
        }
    }

    recStack[node] = 0;

    return 0;
}

/* Detect Cycle */
int detectCycle()
{
    for(int i = 0; i < MAX; i++)
    {
        if(!visited[i])
        {
            if(dfs(i))
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    FILE *fp;

    int src, dest;

    fp = fopen("data/Cycle_test.txt", "r");

    if(fp == NULL)
    {
        printf("Cycle test file not found!\n");
        return 0;
    }

    while(fscanf(fp, "%d %d", &src, &dest) == 2)
    {
        graph[src][dest] = 1;
    }

    fclose(fp);

    printf("\n====================================\n");
    printf("   CIRCULAR DEPENDENCY CHECK\n");
    printf("====================================\n");

    if(detectCycle())
    {
        printf("\nCircular Dependency Found.\n");
    }
    else
    {
        printf("\nNo Circular Dependency Found.\n");
    }

    return 0;
}