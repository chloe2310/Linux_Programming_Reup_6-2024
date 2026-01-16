#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Function executed by threads
void *thread_function(void *arg) 
{
    int *num = (int *)arg; // Casting argument to int pointer
    printf("Thread %d is running.\n", *num);
    pthread_exit(NULL); // Thread exit with no return value
}

int main() 
{
    pthread_t threads[3]; // Array of thread IDs
    int args[3] = {1, 2, 3}; // Arguments to pass to each thread
    // Creating 3 threads
    for (int i = 0; i < 3; i++) 
	{
        if (pthread_create(&threads[i], NULL, thread_function, (void *)&args[i]) != 0) 
		{
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }
    
    // Waiting for each thread to finish
    for (int i = 0; i < 3; i++) 
	{
        pthread_join(threads[i], NULL);
    }
    printf("All threads completed.\n");
    return 0;
} 

Output:

Thread 1 is running.
Thread 2 is running.
Thread 3 is running.
All threads completed. 

Explanation:

Thread Function (thread_function):

This function is executed by each thread. It receives an argument (arg), which is cast to an integer pointer. The function prints a message indicating which thread is running and then terminates using pthread_exit().
Main Function:

An array threads[3] is created to hold the thread IDs of the three threads.
The args array stores values (1, 2, 3) that will be passed to each thread.
The pthread_create() function is used inside a loop to create three threads, each executing the thread_function and passing the corresponding element from args[].
If thread creation fails, an error message is printed.
After creating the threads, the pthread_join() function is called in a loop to wait for each thread to finish execution.
Once all threads have finished, the program prints "All threads completed."
  
