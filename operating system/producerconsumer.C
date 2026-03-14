// this is a simple implementation of the producer-consumer problem using semaphores and mutexes in C. The producer and consumer functions are called based on user input, and the program ensures that the buffer does not overflow or underflow by using semaphores to manage the number of empty and full slots in the buffer. The mutex is used to protect access to the shared buffer when producing or consuming items.And run in linux termina its easy more than windows because of the support for pthreads and semaphores.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define MAX 10   // maximum number of items allowed

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int produced_count = 0, consumed_count = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void produce_item() {
    if (produced_count >= MAX) {
        printf("Production limit reached (%d items).\n", MAX);
        return;
    }

    int item;
    printf("Enter item: ");
    scanf("%d", &item);

    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    buffer[in] = item;
    printf("Producer inserted: %d\n", item);
    in = (in + 1) % BUFFER_SIZE;
    produced_count++;

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void consume_item() {
    if (consumed_count >= MAX) {
        printf("Consumption limit reached (%d items).\n", MAX);
        return;
    }

    int item;

    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    item = buffer[out];
    printf("Consumer removed: %d\n", item);
    out = (out + 1) % BUFFER_SIZE;
    consumed_count++;

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main() {
    int choice;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                produce_item();
                break;
            case 2:
                consume_item();
                break;
            case 3:
                printf("Exiting...\n");
                sem_destroy(&empty);
                sem_destroy(&full);
                pthread_mutex_destroy(&mutex);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}