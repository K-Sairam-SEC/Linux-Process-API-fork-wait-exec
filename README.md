# Linux-Process-API-fork-wait-exec-
Ex02-Linux Process API-fork(), wait(), exec()
# Ex02-OS-Linux-Process API - fork(), wait(), exec()
Operating systems Lab exercise


# AIM:
To write C Program that uses Linux Process API - fork(), wait(), exec()

# DESIGN STEPS:

### Step 1:

Navigate to any Linux environment installed on the system or installed inside a virtual environment like virtual box/vmware or online linux JSLinux (https://bellard.org/jslinux/vm.html?url=alpine-x86.cfg&mem=192) or docker.

### Step 2:

Write the C Program using Linux Process API - fork(), wait(), exec()

### Step 3:

Test the C Program for the desired output. 

# PROGRAM:

## C Program to create new process using Linux API system calls fork() and getpid() , getppid() and to print process ID and parent Process ID using Linux API system calls

```c
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
```

## OUTPUT
<img width="461" height="199" alt="image" src="https://github.com/user-attachments/assets/4f4f2525-282b-4c97-a70d-f74470c0da36" />




## C Program to execute Linux system commands using Linux API system calls exec() , exit() , wait() family


```c
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int status;
    
    printf("--- Running ps with execl (using full path) ---\n");
    if (fork() == 0) {
        // We use /bin/ps because execl needs the absolute path
        execl("/bin/ps", "ps", "-f", NULL); 
        perror("execl failed");
        exit(1);
    }
    wait(&status);
    
    printf("\n--- Running ps with execlp (searching PATH) ---\n");
    if (fork() == 0) {
        // execlp is smarter and finds 'ps' in /bin automatically
        execlp("ps", "ps", "-f", NULL);
        perror("execlp failed");
        exit(1);
    }
    wait(&status);
    
    printf("\nDone.\n");
    return 0;
}
```


## OUTPUT


<img width="679" height="401" alt="image" src="https://github.com/user-attachments/assets/8040653b-fc72-4828-a8a1-d84c0e949d5d" />









# RESULT:
The programs are executed successfully.
