#include <stdio.h>
#include <pthread.h>

/* Thread 1 : Dependency Graph */
void *dependencyGraph(void *arg)
{
    printf("\n[THREAD 1] Dependency Graph Generation Started\n");
    printf("[THREAD 1] Dependency Graph Generated Successfully\n");

    return NULL;
}

/* Thread 2 : Circular Dependency Detection */
void *circularDependency(void *arg)
{
    printf("\n[THREAD 2] Circular Dependency Detection Started\n");
    printf("[THREAD 2] Circular Dependency Analysis Completed\n");

    return NULL;
}

/* Thread 3 : Dependency Resolution */
void *dependencyResolution(void *arg)
{
    printf("\n[THREAD 3] Dependency Resolution Started\n");
    printf("[THREAD 3] Dependencies Resolved Successfully\n");

    return NULL;
}

/* Thread 4 : Installation Order */
void *installationOrder(void *arg)
{
    printf("\n[THREAD 4] Installation Order Generation Started\n");
    printf("[THREAD 4] Installation Order Generated Successfully\n");

    return NULL;
}

/* Thread 5 : Conflict Detection */
void *conflictDetection(void *arg)
{
    printf("\n[THREAD 5] Conflict Detection Started\n");
    printf("[THREAD 5] Version Conflicts Analyzed Successfully\n");

    return NULL;
}

/* Thread 6 : Reporting */
void *reportGeneration(void *arg)
{
    printf("\n[THREAD 6] Report Generation Started\n");
    printf("[THREAD 6] Project Report Generated Successfully\n");

    return NULL;
}

int main()
{
    pthread_t t1, t2, t3, t4, t5, t6;

    printf("====================================\n");
    printf(" SOFTWARE PACKAGE DEPENDENCY RESOLVER\n");
    printf(" MULTITHREADING DEMONSTRATION\n");
    printf("====================================\n");

    pthread_create(&t1, NULL, dependencyGraph, NULL);
    pthread_create(&t2, NULL, circularDependency, NULL);
    pthread_create(&t3, NULL, dependencyResolution, NULL);
    pthread_create(&t4, NULL, installationOrder, NULL);
    pthread_create(&t5, NULL, conflictDetection, NULL);
    pthread_create(&t6, NULL, reportGeneration, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);

    printf("\n====================================\n");
    printf(" ALL THREADS COMPLETED SUCCESSFULLY\n");
    printf("====================================\n");

    return 0;
}