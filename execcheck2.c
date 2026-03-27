#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) { 
        printf("I am child, my PID is %d\n", getpid()); 
        printf("My parent PID is: %d\n", getppid()); 
        sleep(2); 
    } else { 
        printf("I am parent, my PID is %d\n", getpid()); 
        wait(NULL); 
        printf("Child has finished. Parent exiting.\n");
    }
    return 0;
}
