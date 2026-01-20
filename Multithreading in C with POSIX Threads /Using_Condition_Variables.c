/* This example demonstrates the use of condition variables to synchronize threads, where one thread waits for a signal while another sends the signal. */



#include <stdio.h>
#include <pthread.h>
pthread_mutex_t lock;  // Declare mutex
pthread_cond_t cond;   // Declare condition variable
int ready = 0;         // Shared condition

// Function to wait for condition
void* waitForSignal(void* arg) {
    pthread_mutex_lock(&lock);
    while (!ready) {
        printf("Thread waiting for signal...\n");
        pthread_cond_wait(&cond, &lock);  // Wait for condition signal
    }
    printf("Thread received signal!\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

// Function to send signal
void* sendSignal(void* arg) {
    pthread_mutex_lock(&lock);
    ready = 1;  // Set condition to true
    pthread_cond_signal(&cond);  // Send signal to waiting thread
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    // Initialize mutex and condition variable
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    // Create threads
    pthread_create(&thread1, NULL, waitForSignal, NULL);
    pthread_create(&thread2, NULL, sendSignal, NULL);

    // Join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}


Explanation:

pthread_cond_t is used for condition variables that allow threads to wait for or send signals.
pthread_cond_wait() makes a thread wait for a signal, and pthread_cond_signal() sends the signal when the condition is met.
Summary:

Thread Creation and Joining: Use pthread_create() and pthread_join() to create and manage threads.
Synchronization: Use mutexes to prevent race conditions when multiple threads access shared data.
Passing Arguments: Pass multiple arguments to threads using structures.
Condition Variables: Use condition variables to signal between threads and control execution flow.

