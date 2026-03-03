// Dinning philosophers problem solution using semaphores and mutexes in C always use linux to get it prefectly working. This code simulates the dining philosophers problem, where each philosopher alternates between thinking and eating. The philosophers need to acquire two chopsticks (mutexes) to eat, and a semaphore is used to limit the number of philosophers that can attempt to eat at the same time, preventing deadlock. Each philosopher will eat a maximum of three times before finishing.and if u are using vs code its difficult to run this code because of the use of semaphores and mutexes, so it is recommended to use a linux environment to compile and run this code successfully.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
#define MAX_MEALS 3

pthread_mutex_t chopstick[N];
sem_t room;

void* philosopher(void* num) {
    int id = *(int*)num;
    for (int i = 0; i < MAX_MEALS; i++) {
        printf("Philosopher %d is Thinking\n", id);
        sleep(1);
        sem_wait(&room);
        pthread_mutex_lock(&chopstick[id]);
        pthread_mutex_lock(&chopstick[(id + 1) % N]);
        printf("Philosopher %d is Eating (%d)\n", id, i + 1);
        sleep(2);
        pthread_mutex_unlock(&chopstick[id]);
        pthread_mutex_unlock(&chopstick[(id + 1) % N]);
        sem_post(&room);
        printf("Philosopher %d Finished Eating\n", id);
    }
    printf("Philosopher %d is Done\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread[N];
    int phil[N];
    sem_init(&room, 0, N - 1);
    for (int i = 0; i < N; i++)
        pthread_mutex_init(&chopstick[i], NULL);
    for (int i = 0; i < N; i++) {
        phil[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &phil[i]);
    }
    for (int i = 0; i < N; i++)
        pthread_join(thread[i], NULL);
    printf("\nAll philosophers have finished eating.\n");
    return 0;
}
