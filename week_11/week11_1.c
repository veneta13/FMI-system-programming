#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(int argc, char *argv[]) {
    int fd[2];
    pipe(fd);
    
    if (fork()) {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        close(fd[1]);
        execlp("who", "who", 0);
    }
    else {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        close(fd[0]);
        execlp("wc", "wc", "-l", 0);
    }
}
