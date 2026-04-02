// LRU (least recently used) and Optimal Page Replacement Algorithms in C and it also shows the page frames and whether it is a hit or a fault for each page reference for both algorithms. The program takes the number of frames, number of pages, and the page reference string as input from the user. It then simulates both LRU and Optimal page replacement algorithms and counts the total page faults and hits for each algorithm.
#include <stdio.h>
void printFrames(int frame[], int frames) {
    for (int i = 0; i < frames; i++) {
        if (frame[i] != -1)
            printf("%-3d", frame[i]);
        else
            printf("%-3s", "-");
    }
}

//    LRU
void lru(int page[], int pages, int frames) {
    int frame[frames], time[frames];

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }
    int faults = 0, hits = 0, counter = 0;
    printf("\nLRU Algorithm\n");
    printf("%-8s %-20s %-10s\n", "Page", "Frames", "Result");
    for (int i = 0; i < pages; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                hits++;
                break;
            }
        }
        if (!found) {
            int lru = 0;
            for (int j = 1; j < frames; j++) {
                if (time[j] < time[lru])
                    lru = j;
            }
            frame[lru] = page[i];
            counter++;
            time[lru] = counter;
            faults++;
        }
        printf("%-8d ", page[i]);
        printFrames(frame, frames);
        printf("   %-10s\n", found ? "Hit" : "Fault");
    }
    printf("\nFaults = %d | Hits = %d\n", faults, hits);
}

//  OPTIMAL
void optimal(int page[], int pages, int frames) {
    int frame[frames];
    for (int i = 0; i < frames; i++) frame[i] = -1;
    int faults = 0, hits = 0;

    printf("\nOptimal Algorithm\n");
    printf("%-8s %-20s %-10s\n", "Page", "Frames", "Result");
    for (int i = 0; i < pages; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                found = 1;
                hits++;
                break;
            }
        }
        if (!found) {
            int pos = -1, farthest = i + 1;
            for (int j = 0; j < frames; j++) {
                int k;
                for (k = i + 1; k < pages; k++) {
                    if (frame[j] == page[k]) {
                        if (k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }
                if (k == pages) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) pos = 0;
            frame[pos] = page[i];
            faults++;
        }
        printf("%-8d ", page[i]);
        printFrames(frame, frames);
        printf("   %-10s\n", found ? "Hit" : "Fault");
    }
    printf("\nFaults = %d | Hits = %d\n", faults, hits);
}

//  MAIN 
int main() {
    int frames, pages, choice;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    int page[pages];
    printf("Enter page reference string:\n");
    for (int i = 0; i < pages; i++)
        scanf("%d", &page[i]);
    do {
        printf("\n   PAGE REPLACEMENT MENU  \n");
        printf("1. LRU\n");
        printf("2. Optimal\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                lru(page, pages, frames);
                break;
            case 2:
                optimal(page, pages, frames);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}