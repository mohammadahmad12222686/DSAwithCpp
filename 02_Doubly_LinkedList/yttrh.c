#include <stdio.h>
#include <pthread.h>

int shared_variable = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_thread(void *thread_id) {
    for (int i = 0; i < 1000000; ++i) {
        pthread_mutex_lock(&mutex);
        shared_variable++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment_thread, NULL);
    pthread_create(&thread2, NULL, increment_thread, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of the shared variable: %d\n", shared_variable);

    return 0;
}
// ################################################################################
#include <stdio.h>
#include <pthread.h>

void *print_numbers(void *arg) {
    for (int i = 1; i <= 10; ++i) {
        printf("Thread 1: %d\n", i);
    }
    pthread_exit(NULL);
}

void *check_even_odd(void *arg) {
    int *user_number = (int *)arg;

    if (*user_number % 2 == 0) {
        printf("Thread 2: The entered number is even.\n");
    } else {
        printf("Thread 2: The entered number is odd.\n");
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int user_number;

    printf("Enter a number: ");
    scanf("%d", &user_number);

    pthread_create(&thread1, NULL, print_numbers, NULL);
    pthread_create(&thread2, NULL, check_even_odd, (void *)&user_number);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t p1, p2, p3;

    // Create process p1
    p1 = fork();

    if (p1 == 0) {
        // Code for process p2
        printf("Process p2 (PID: %d) created by p1 (PID: %d)\n", getpid(), getppid());
    } else if (p1 > 0) {
        // Code for process p1
        printf("Process p1 (PID: %d) created p2 (PID: %d)\n", getpid(), p1);

        // Create process p3
        p3 = fork();

        if (p3 == 0) {
            // Code for process p3
            printf("Process p3 (PID: %d) created by p1 (PID: %d)\n", getpid(), getppid());
        } else if (p3 > 0) {
            // Code for process p1
            printf("Process p1 (PID: %d) created p3 (PID: %d)\n", getpid(), p3);
        } else {
            perror("Error creating process p3");
        }
    } else {
        perror("Error creating process p1");
    }

    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
int main() {
    pid_t p1, p2, p3;

    printf("Process p1 (PID: %d) created by the parent (PPID: %d)\n", getpid(), getppid());

    // Create process p2
    p2 = fork();

    if (p2 == 0) {
        // Code for process p2
        printf("Process p2 (PID: %d) created by p1 (PPID: %d)\n", getpid(), getppid());

        // Create process p3
        p3 = fork();

        if (p3 == 0) {
            // Code for process p3
            printf("Process p3 (PID: %d) created by p2 (PPID: %d)\n", getpid(), getppid());
        }
    } else if (p2 > 0) {
        // Code for process p1
        wait(NULL); // Wait for p2 to finish

        printf("Process p1 (PID: %d) created p2 (PID: %d)\n", getpid(), p2);
    }

    return 0;
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Code for the child process
        printf("Child Process (PID: %d)\n", getpid());
    } else {
        // Code for the parent process
        printf("Parent Process (PID: %d), Child Process ID: %d\n", getpid(), pid);
    }

    return 0;
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Code for the child process
        printf("Child Process (PID: %d)\n", getpid());
    } else {
        // Code for the parent process
        usleep(100000); // Delay for 100 milliseconds (simulate parent taking time)
        printf("Parent Process (PID: %d), Child Process ID: %d\n", getpid(), pid);
    }

    return 0;
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 5

int numbers[ARRAY_SIZE] = {7, 2, 8, 1, 5};

int sum_result = 0;
int max_result = 0;
int min_result = 0;

// Mutex for synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to calculate the sum of the array
void *calculate_sum(void *arg) {
    int sum = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += numbers[i];
    }

    pthread_mutex_lock(&mutex);
    sum_result = sum;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

// Function to calculate the maximum of the array
void *calculate_max(void *arg) {
    int max = numbers[0];

    for (int i = 1; i < ARRAY_SIZE; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    pthread_mutex_lock(&mutex);
    max_result = max;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

// Function to calculate the minimum of the array
void *calculate_min(void *arg) {
    int min = numbers[0];

    for (int i = 1; i < ARRAY_SIZE; ++i) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    pthread_mutex_lock(&mutex);
    min_result = min;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread_sum, thread_max, thread_min;

    pthread_create(&thread_sum, NULL, calculate_sum, NULL);
    pthread_create(&thread_max, NULL, calculate_max, NULL);
    pthread_create(&thread_min, NULL, calculate_min, NULL);

    pthread_join(thread_sum, NULL);
    pthread_join(thread_max, NULL);
    pthread_join(thread_min, NULL);

    printf("Sum: %d\n", sum_result);
    printf("Maximum: %d\n", max_result);
    printf("Minimum: %d\n", min_result);

    return 0;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX_STR_LEN 100

// Thread function to find the length of a string
void *find_length(void *arg) {
    char *str = (char *)arg;
    int length = strlen(str);
    printf("Length of string '%s': %d\n", str, length);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Example strings
    char str1[] = "Hello,";
    char str2[] = "world!";

    // Create threads and pass the strings
    pthread_create(&thread1, NULL, find_length, (void *)str1);
    pthread_create(&thread2, NULL, find_length, (void *)str2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
//####################################################################################
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 2
#define ITERATIONS 1000000

int shared_counter = 0;
sem_t semaphore;

void *increment_counter(void *arg) {
    for (int i = 0; i < ITERATIONS; ++i) {
        sem_wait(&semaphore); // Wait for the semaphore
        shared_counter++;
        sem_post(&semaphore); // Release the semaphore
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Initialize the semaphore
    sem_init(&semaphore, 0, 1);

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    // Display the final value of the shared counter
    printf("Final value of the shared counter: %d\n", shared_counter);

    return 0;
}
//####################################################################################
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define ITERATIONS 1000000

int shared_counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_counter(void *arg) {
    for (int i = 0; i < ITERATIONS; ++i) {
        pthread_mutex_lock(&mutex); // Lock the mutex
        shared_counter++;
        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Display the final value of the shared counter
    printf("Final value of the shared counter: %d\n", shared_counter);

    return 0;
}
//####################################################################################
#include<stdio.h>
#include<dirent.h>
int main()
{
DIR *dp;
struct dirent *dptr;
int b = mkdir(“Dir1", 0777);
dp=opendir(“Dir1");
while(NULL !=(dptr = readdir(dp)))
{
printf(“\%s \n", dptr ->d_name);
printf(%d \n",dptr->d_type);
}
return 0;
}
//####################################################################################
