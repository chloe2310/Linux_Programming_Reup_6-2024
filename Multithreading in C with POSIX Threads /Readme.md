Introduction

Multithreading allows a program to perform multiple tasks concurrently, improving performance on multicore systems. In C, POSIX threads (commonly referred to as pthreads) are used for multithreading. 
This tutorial will explore basic thread concepts, creation, joining, and synchronization using pthread in C.

POSIX threads (pthreads)

POSIX (Portable Operating System Interface): A standard for maintaining compatibility between operating systems, ensuring portability of code across UNIX-like systems.
Multithreading Library: The pthread library provides functions to create, manage, and synchronize threads in C programs.
Thread Creation: Use pthread_create() to create a new thread, which runs a specific function concurrently with the main program.
Thread Joining: Use pthread_join() to ensure the main program waits for a thread to finish before continuing execution.
Mutex for Synchronization: Pthreads offer mutex locks (pthread_mutex_t) to ensure that shared resources are accessed safely by multiple threads, preventing race conditions.
Condition Variables: Pthreads support condition variables (pthread_cond_t) to allow threads to wait for or signal certain conditions before proceeding.
Portability: Since pthreads adhere to the POSIX standard, programs using pthreads are portable across different UNIX-like systems, including Linux and macOS.
Efficiency: Multithreading can increase performance by taking advantage of multicore processors, allowing tasks to be performed simultaneously.


Syntax for POSIX threads (pthreads)

Here's a clear syntax for POSIX threads (pthreads) in C programming, along with descriptions of the primary functions and their parameters:

1 , Thread Creation: pthread_create()

This function creates a new thread that starts execution at the function pointed to by start_routine.

Syntax: int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); 

Parameters:
pthread_t *thread: Pointer to a variable that stores the thread ID of the newly created thread.
const pthread_attr_t *attr: Pointer to thread attributes. Use NULL for default attributes.
void *(*start_routine)(void *): Pointer to the function that the thread will execute. This function must return void* and take a void* argument.
void *arg: Argument passed to the thread’s start routine. Use NULL if no argument is needed.

2, Thread Termination: pthread_exit() 

This function terminates the calling thread and optionally returns a value to other threads.

Syntax: void pthread_exit(void *retval);

Parameter:
void *retval: The exit status of the thread, which can be retrieved by another thread using pthread_join().

3, Waiting for Thread to Complete: pthread_join()

The calling thread waits for the specified thread to terminate. If the target thread has already exited, pthread_join() returns immediately.

Syntax: int pthread_join(pthread_t thread, void **retval);

Parameters:
pthread_t thread: The thread ID of the thread to wait for.
void **retval: Pointer to store the return value of the terminated thread (optional, can be NULL).

4, Thread Synchronization with Mutex: pthread_mutex_t

Mutexes are used to protect shared resources from being accessed by multiple threads at the same time. pthread_mutex_lock() locks the mutex, and pthread_mutex_unlock() releases it.

a,Mutex Initialization:
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

b,Mutex Locking:
int pthread_mutex_lock(pthread_mutex_t *mutex);

Parameters:
pthread_mutex_t *mutex: Pointer to the mutex to be locked.

c,Mutex Unlocking:
int pthread_mutex_unlock(pthread_mutex_t *mutex);

Parameter:
pthread_mutex_t *mutex: Pointer to the mutex to be unlocked.

5, Condition Variables: pthread_cond_t

Condition variables allow threads to wait for specific conditions to be met, typically in conjunction with a mutex.

a, Condition Variable Initialization: pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
b, Wait on Condition: int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
Parameters:
pthread_cond_t *cond: Pointer to the condition variable.
pthread_mutex_t *mutex: Pointer to the associated mutex. The mutex is automatically unlocked while waiting.
c, Signal a Condition: int pthread_cond_signal(pthread_cond_t *cond);
Parameter: pthread_cond_t *cond: Pointer to the condition variable to signal.

6, Thread Attributes: pthread_attr_t

Attributes control thread behavior, such as whether the thread is joinable or detached.

Attribute Initialization:
pthread_attr_t attr;
pthread_attr_init(&attr);


Set Detach State (Optional): pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
Parameters:
pthread_attr_t *attr: Pointer to the thread attribute object.
int detachstate: Set the detach state, either PTHREAD_CREATE_JOINABLE (default) or PTHREAD_CREATE_DETACHED.







