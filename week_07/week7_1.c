#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main() {
    int pid1, pid2, pid;
    pid = fork();
    pid1 = fork();
    printf("pid= %d ppid=%d\n", getpid(), getppid());
    wait(NULL);
    wait(NULL);
}  
