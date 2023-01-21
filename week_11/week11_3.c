#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Please provide at least 2 arguments!\n");
        exit(1);
    }

    int fd[2];
    pipe(fd);

    if (fork()) {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        close(fd[1]);
        execlp(argv[1], argv[1], 0);
    }
    else {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        close(fd[0]);
        execvp(argv[2], &argv[2]);
    }
}
