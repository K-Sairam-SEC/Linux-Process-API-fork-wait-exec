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
}//C Program to create new process using Linux API system calls fork() and exit()
