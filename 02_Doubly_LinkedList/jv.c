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
