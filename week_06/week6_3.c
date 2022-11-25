#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "error: provide command name\n", sizeof("error: provide command name\n"));
        exit(1);
    }

    int status;

    if (fork() == 0) {
        execlp(argv[1], argv[1], 0);
        exit(1);
    } else {
        wait(&status);
        printf("exit status = %d\n", status);
    }
}