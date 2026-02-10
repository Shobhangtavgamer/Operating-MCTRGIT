// Shortest Job First (SJF) Scheduling Algorithm - Non-Preemptive with Gantt Chart in C
#include <stdio.h>
int main()
{
    int time, burst_time[10], at[10], temp_bt[10];
    int n, i, smallest;
    int sum_burst_time = 0;
    int wt[10], tat[10], ct[10];
    int sumt = 0, sumw = 0;
    int gantt_pid[10], gantt_time[10];
    int gc = 0;
    printf("Enter the no of processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("The arrival time for process P%d : ", i + 1);
        scanf("%d", &at[i]);
        printf("The burst time for process P%d : ", i + 1);
        scanf("%d", &burst_time[i]);
        temp_bt[i] = burst_time[i];
        sum_burst_time += burst_time[i];
    }
    burst_time[9] = 9999; 
    for (time = 0; time < sum_burst_time;)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && burst_time[i] > 0 &&
                burst_time[i] < burst_time[smallest])
            {
                smallest = i;
            }
        }
        gantt_pid[gc] = smallest + 1;
        time += burst_time[smallest];
        gantt_time[gc] = time;
        gc++;
        ct[smallest] = time;
        burst_time[smallest] = 0;
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - temp_bt[i];
        sumw += wt[i];
        sumt += tat[i];
    }
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], temp_bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time = %.2f", sumw * 1.0 / n);
    printf("\nAverage turnaround time = %.2f", sumt * 1.0 / n);
    printf("\nAverage response time = %.2f\n", sumw * 1.0 / n);

    /* GANTT CHART*/
    printf("\nGantt Chart:\n\n ");
for (i = 0; i < gc; i++)
    printf("--------");
printf("-\n|");
for (i = 0; i < gc; i++)
    printf("  P%d   |", gantt_pid[i]);
printf("\n ");
for (i = 0; i < gc; i++)
    printf("--------");
printf("-\n");
printf("0");
for (i = 0; i < gc; i++)
    printf("%8d", gantt_time[i]);
printf("\n");
}