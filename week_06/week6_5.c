#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(int argc, char *argv[]) {
    if (argc != 4) {
        write(2, "error: provide 3 commands\n", sizeof("error: provide 3 commands\n"));
        exit(1);
    }

    int status;

    if (fork() == 0) {
        if (fork() == 0) {
            if (fork() == 0) {
                execlp(argv[1], argv[1], 0);
                exit(1);
            }
            else {
                wait(&status);
                printf("pid = %d\nstatus = %d\n", getpid(), status);
                execlp(argv[2], argv[2], 0);
                exit(1);
            }
        }
        else {
            wait(&status);
            printf("pid = %d\nstatus = %d\n", getpid(), status);
            execlp(argv[3], argv[3], 0);
            exit(1);
        }
    }
    else {
        wait(&status);
        printf("pid = %d\nstatus = %d\n", getpid(), status);
    }
}
