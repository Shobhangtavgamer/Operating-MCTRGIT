// Round Robin Scheduling Algorithm with Grant Chart in C
#include <stdio.h>
int main() {
    int n, i, quantum;
    int burst[20], remaining[20];
    int waiting[20]={0}, tat[20]={0};
    int time = 0, done;
    int gantt_process[200], gantt_time[200];
    int k = 0;
    float avg_wt=0, avg_tat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Burst Time for P%d: ",i+1);
        scanf("%d",&burst[i]);
        remaining[i]=burst[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d",&quantum);
    gantt_time[k] = 0;
    // Round Robin
    do{
        done = 1;
        for(i=0;i<n;i++){
            if(remaining[i] > 0){
                done = 0;
                gantt_process[k] = i+1;
                k++;
                if(remaining[i] > quantum){
                    time += quantum;
                    remaining[i] -= quantum;
                }
                else{
                    time += remaining[i];
                    waiting[i] = time - burst[i];
                    remaining[i] = 0;
                }
                gantt_time[k] = time;
            }
        }
    }while(!done);

    // PERFECT GANTT CHART
    printf("\nGantt Chart:\n");
    for(i=0;i<k;i++)
        printf("+-----");
    printf("+\n");
    for(i=0;i<k;i++)
        printf("| P%-2d ",gantt_process[i]);
    printf("|\n");
    for(i=0;i<k;i++)
        printf("+-----");
    printf("+\n");
    for(i=0;i<=k;i++)
        printf("%-6d",gantt_time[i]);
    for(i=0;i<n;i++){
        tat[i]=burst[i]+waiting[i];
        avg_wt+=waiting[i];
        avg_tat+=tat[i];
    }
    printf("\n\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n",i+1,burst[i],waiting[i],tat[i]);
    printf("\nAverage Waiting Time = %.2f",avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f",avg_tat/n);
    printf("\nResponse Time = %.2f",avg_wt/n);
    return 0;
}
