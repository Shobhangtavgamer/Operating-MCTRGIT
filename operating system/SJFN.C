// Shortest Job First (SJF) Scheduling Algorithm - Preemptive with Gantt Chart in C
#include <stdio.h>
int main()
{
    int n, i, time = 0, completed = 0, smallest;
    int at[10], bt[10], rt[10];
    int ct[10], wt[10], tat[10], response[10];
    int sumw = 0, sumt = 0, sumr = 0;
    int gantt_pid[100], gantt_time[100];
    int gc = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Arrival time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        response[i] = -1;
    }
    rt[9] = 9999; // sentinel
    while (completed < n)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0 && rt[i] < rt[smallest])
                smallest = i;
        }
        // CPU idle
        if (smallest == 9)
        {
            time++;
            continue;
        }
        if (response[smallest] == -1)
            response[smallest] = time - at[smallest];
        gantt_pid[gc] = smallest + 1;
        rt[smallest]--;
        time++;
        gantt_time[gc] = time;
        gc++;
        if (rt[smallest] == 0)
        {
            completed++;
            ct[smallest] = time;
        }
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        sumw += wt[i];
        sumt += tat[i];
        sumr += response[i];
    }
    printf("\nProcess\tAT\tBT\tWT\tTAT\tRT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], wt[i], tat[i], response[i]);
    }
    printf("\nAverage Waiting Time = %.2f", sumw * 1.0 / n);
    printf("\nAverage Turnaround Time = %.2f", sumt * 1.0 / n);
    printf("\nAverage Response Time = %.2f\n", sumr * 1.0 / n);

    /* GANTT CHART */
    printf("\nGantt Chart:\n\n ");
    for (i = 0; i < gc; i++)
        printf("----");
    printf("-\n|");
    for (i = 0; i < gc; i++)
        printf(" P%d |", gantt_pid[i]);
    printf("\n ");
    for (i = 0; i < gc; i++)
        printf("----");
    printf("-\n0");
    for (i = 0; i < gc; i++)
        printf("%4d", gantt_time[i]);
    printf("\n");
    return 0;
}
