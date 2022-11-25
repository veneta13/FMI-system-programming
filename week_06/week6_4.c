#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *args[10];

main(int argc, char *argv[]) {
    for (int i = 2; i < argc; i++) {
        args[i] = argv[i];
    }

    int status;

    if (fork() == 0) {
        execvp(argv[1], args);
        exit(1);
    }
    else {
        wait(&status);
        if (status == 0) {
            printf("%d\n", status);
        }
    }
}