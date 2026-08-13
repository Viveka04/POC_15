#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf(" SOFTWARE PACKAGE DEPENDENCY RESOLVER\n");
        printf("====================================\n");

        printf("1. View Repository\n");
        printf("2. Dependency Graph\n");
        printf("3. Circular Dependency Detection\n");
        printf("4. Dependency Resolution\n");
        printf("5. Installation Order\n");
        printf("6. Conflict Detection\n");
        printf("7. Generate Report\n");
        printf("8. View Logs\n");
        printf("0. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                system("bin\\View_repository.exe");
                break;

            case 2:
                system("bin\\Dependency_graph.exe");
                break;

            case 3:
                system("bin\\Circular_dependency.exe");
                break;

            case 4:
                system("bin\\Dependency_resolution.exe");
                break;

            case 5:
                system("bin\\Installation_order.exe");
                break;

            case 6:
                system("bin\\Conflict_detection.exe");
                break;

            case 7:
                system("bin\\Reporting_module.exe");
                break;

            case 8:
                system("bin\\Logging.exe");
                break;

            case 0:
                printf("\nExiting Application...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 0);

    return 0;
}