// Priority Scheduling in C with Proper Gantt Chart
#include <stdio.h>
struct priority_scheduling {
    char process_name;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    int priority;
};
int main() {
    int number_of_process;
    int total = 0;
    int ASCII_number = 65;
    int position;
    float average_waiting_time;
    float average_turnaround_time;
    printf("Enter the total number of Processes: ");
    scanf("%d", &number_of_process);
    struct priority_scheduling process[number_of_process], temp_process;
    printf("\nEnter Burst Time and Priority\n");
    for (int i = 0; i < number_of_process; i++) {
        process[i].process_name = (char)ASCII_number;
        printf("\nProcess %c\n", process[i].process_name);
        printf("Burst Time: ");
        scanf("%d", &process[i].burst_time);
        printf("Priority: ");
        scanf("%d", &process[i].priority);
        ASCII_number++;
    }
    for (int i = 0; i < number_of_process; i++) {
        position = i;
        for (int j = i + 1; j < number_of_process; j++) {
            if (process[j].priority < process[position].priority)
                position = j;
        }
        temp_process = process[i];
        process[i] = process[position];
        process[position] = temp_process;
    }
    process[0].waiting_time = 0;
    for (int i = 1; i < number_of_process; i++) {
        process[i].waiting_time =
            process[i - 1].waiting_time + process[i - 1].burst_time;
        total += process[i].waiting_time;
    }
    average_waiting_time = (float)total / number_of_process;
    total = 0;
    printf("\n\nProcess Table:\n");
    printf("------------------------------------------------------------\n");
    printf("Process | Priority | Burst | Waiting | Turnaround\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < number_of_process; i++) {
        process[i].turn_around_time =
            process[i].burst_time + process[i].waiting_time;
        total += process[i].turn_around_time;
        printf("   %c    |    %2d    |  %3d  |   %3d   |    %3d\n",
               process[i].process_name,
               process[i].priority,
               process[i].burst_time,
               process[i].waiting_time,
               process[i].turn_around_time);
    }
    printf("------------------------------------------------------------\n");
    average_turnaround_time = (float)total / number_of_process;
    printf("\nAverage Waiting Time    = %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time = %.2f\n", average_turnaround_time);

    // Proper Gantt Chart
    printf("\nGantt Chart:\n\n ");
    for (int i = 0; i < number_of_process; i++)
        printf("--------");
    printf("-\n|");
    for (int i = 0; i < number_of_process; i++)
        printf("  %c   |", process[i].process_name);
    printf("\n ");
    for (int i = 0; i < number_of_process; i++)
        printf("--------");
    printf("-\n");
    int time = 0;
    printf("0");
    for (int i = 0; i < number_of_process; i++) {
        time += process[i].burst_time;
        printf("%8d", time);
    }
    printf("\n");
    return 0;
}
