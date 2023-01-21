#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("ERROR: provide 2 commands and 1 filename\n");
        exit(1);
    }

    int fd = open(argv[3], O_WRONLY | O_CREAT | O_APPEND, 0777);

    if (fd == -1) {
        printf("ERROR: can't open file\n");
        exit(1);
    }

    int status;

    if (fork() == 0) {
        if (fork() == 0) {
            execlp(argv[1], argv[1], 0);
            exit(1);
        }
        else {
            wait(&status);

            if (status == 0) {
                write(fd, argv[1], strlen(argv[1]));
            }
            else {
                write(2, "ERROR: execution unsuccessful\n", sizeof("ERROR: execution unsuccessful\n"));
            }
        }
    }
    else {
        wait(&status);
        execlp(argv[2], argv[2], 0);
    }
}

