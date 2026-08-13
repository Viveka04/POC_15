#include <stdio.h>

int main()
{
    FILE *fp;
    char line[200];

    fp = fopen("data/project_log.txt", "r");

    if(fp == NULL)
    {
        printf("Log file not found!\n");
        return 0;
    }

    printf("\n====================================\n");
    printf("           SYSTEM LOGS\n");
    printf("====================================\n\n");

    while(fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}