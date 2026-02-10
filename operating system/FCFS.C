// First Come First Served (FCFS) Scheduling Algorithm Implementation in C with grannt Chart.
#include <stdio.h>
int main()
{
    int pid[15];
    int bt[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter process id of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }
    printf("Enter burst time of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    int wt[n];
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
    printf("\nProcess ID     Burst Time     Waiting Time     Turnaround Time\n");
    float twt = 0.0, tat = 0.0;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", bt[i] + wt[i]);
        printf("\n");
        twt += wt[i];
        tat += (wt[i] + bt[i]);
    }
    float awt = twt / n;
    float att = tat / n;
    printf("\nAvg. waiting time = %.2f\n", awt);
    printf("Avg. turnaround time = %.2f\n", att);
    printf("Avg. response time = %.2f\n", awt);

    /*GANTT CHART*/
    printf("\nGantt Chart:\n\n");
    printf(" ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bt[i]; j++)
            printf("--");
        printf(" ");
    }
    printf("\n|");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bt[i] - 1; j++)
            printf(" ");
        printf("P%d", pid[i]);
        for (int j = 0; j < bt[i] - 1; j++)
            printf(" ");
        printf("|");
    }
    printf("\n ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bt[i]; j++)
            printf("--");
        printf(" ");
    }
    printf("\n0");
    for (int i = 0; i < n; i++)
    {
        printf("%*d", bt[i] * 2 + 1, wt[i] + bt[i]);
    }
    printf("\n");
    return 0;
}



