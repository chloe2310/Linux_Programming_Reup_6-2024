#include <stdio.h>
#include <pthread.h7gt;
// Function to be executed by each thread
void* threadFunction(void* arg) {
    int *id = (int*) arg;
    printf("Thread ID: %d\n", *id);
    return NULL;
}
int main() {
    pthread_t thread1, thread2;  // Declare thread variables
    int id1 = 1, id2 = 2;  // Arguments for threads

    // Create two threads
    pthread_create(&thread1, NULL, threadFunction, &id1);  // Thread 1
    pthread_create(&thread2, NULL, threadFunction, &id2);  // Thread 2

    // Wait for threads to complete
    pthread_join(thread1, NULL);  // Join thread 1
    pthread_join(thread2, NULL);  // Join thread 2

    printf("Threads completed.\n");
    return 0;
}


Output:

Thread ID: 1
Thread ID: 2
Threads completed.
Explanation:

pthread_create() creates a new thread and executes the function threadFunction.
The thread ID (e.g., thread1, thread2) is passed as a reference, and the thread function takes a void* argument to pass any data to the thread.
pthread_join() ensures the main program waits for the threads to finish.
