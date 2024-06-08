#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5  // Size of the buffer
#define NUM_ITEMS 10   // Number of items to produce/consume

int buffer[BUFFER_SIZE];  // Shared buffer
int in = 0;               // Index to add items
int out = 0;              // Index to remove items

sem_t empty;    // Semaphore to track empty slots in the buffer
sem_t full;     // Semaphore to track filled slots in the buffer
sem_t mutex;    // Mutex semaphore for buffer access

void* producer(void* arg) {
    int item;
    for (int i = 0; i < NUM_ITEMS; i++) {
        item = i + 1;

        sem_wait(&empty);    // Wait for an empty slot in the buffer
        sem_wait(&mutex);    // Acquire the mutex for buffer access

        buffer[in] = item;
        printf("Produced item: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);    // Release the mutex for buffer access
        sem_post(&full);     // Indicate a filled slot in the buffer
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item;
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&full);     // Wait for a filled slot in the buffer
        sem_wait(&mutex);    // Acquire the mutex for buffer access

        item = buffer[out];
        printf("Consumed item: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);    // Release the mutex for buffer access
        sem_post(&empty);    // Indicate an empty slot in the buffer
    }

    pthread_exit(NULL);
}

int main() {
    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create producer and consumer threads
    pthread_t producerThread, consumerThread;
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
