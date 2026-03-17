// Implementation of First Fit, Best Fit, and Worst Fit memory allocation algorithms in C also called memory allocation strategies. The program takes the number of memory blocks, their sizes, the number of processes, and their sizes as input, and then applies each of the three algorithms to allocate memory to the processes. It also prints a Gantt chart to visualize the allocation.
#include <stdio.h>

void printGantt(int original[], int blocks[], int m) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < m; i++)
        printf("+-----------");
    printf("+\n");
    for (int i = 0; i < m; i++)
        printf("| %9d ", original[i]);
    printf("|\n");

    for (int i = 0; i < m; i++) {
        if (blocks[i] != original[i])
            printf("| (%7d) ", blocks[i]);
        else
            printf("|           ");
    }
    printf("|\n"); 
    for (int i = 0; i < m; i++)
        printf("+-----------");
    printf("+\n");
}

void firstFit(int blocks[], int m, int process[], int n) {
    int allocation[n], original[m];
    for (int i = 0; i < m; i++) original[i] = blocks[i];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= process[i]) {
                allocation[i] = j;
                blocks[j] -= process[i];
                break;
            }
        }
    }
    printf("\n   First Fit   \n");
    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t", i+1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    printGantt(original, blocks, m);
}
void bestFit(int blocks[], int m, int process[], int n) {
    int allocation[n], original[m];
    for (int i = 0; i < m; i++) original[i] = blocks[i];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= process[i]) {
                if (best == -1 || blocks[j] < blocks[best])
                    best = j;
            }
        }
        if (best != -1) {
            allocation[i] = best;
            blocks[best] -= process[i];
        }
    }
    printf("\n   Best Fit   \n");
    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t", i+1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    printGantt(original, blocks, m);
}
void worstFit(int blocks[], int m, int process[], int n) {
    int allocation[n], original[m];
    for (int i = 0; i < m; i++) original[i] = blocks[i];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int worst = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= process[i]) {
                if (worst == -1 || blocks[j] > blocks[worst])
                    worst = j;
            }
        }
        if (worst != -1) {
            allocation[i] = worst;
            blocks[worst] -= process[i];
        }
    }
    printf("\n   Worst Fit   \n");
    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t", i+1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    printGantt(original, blocks, m);
}

int main() {
    int m, n;
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter block sizes:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter process sizes:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);
    int b1[m], b2[m], b3[m];
    for (int i = 0; i < m; i++) {
        b1[i] = b2[i] = b3[i] = blockSize[i];
    }
    firstFit(b1, m, processSize, n);
    bestFit(b2, m, processSize, n);
    worstFit(b3, m, processSize, n);
    return 0;
}