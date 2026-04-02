// FIFO Page Replacement Algorithm in C and it also shows the page frames and whether it is a hit or a fault for each page reference. The program takes the number of frames, number of pages, and the page reference string as input from the user. It then simulates the FIFO page replacement algorithm and counts the total page faults and hits.
#include <stdio.h>

int main() {
    int frames, pages;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page[pages], frame[frames];

    printf("Enter page reference string:\n");
    for (int i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    int index = 0, faults = 0, hits = 0;
    printf("\n%-8s %-20s %-10s\n", "Page", "Frames", "Result");

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
            frame[index] = page[i];
            index = (index + 1) % frames;
            faults++;
        }

        // Print page with fixed width
        printf("%-8d ", page[i]);

        // Print frames with fixed spacing
        for (int k = 0; k < frames; k++) {
            if (frame[k] != -1)
                printf("%-3d", frame[k]);
            else
                printf("%-3s", "-");
        }

        // Print result aligned
        if (found)
            printf("   %-10s\n", "Hit");
        else
            printf("   %-10s\n", "Fault");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits   = %d\n", hits);

    return 0;
}