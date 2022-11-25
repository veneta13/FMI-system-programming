#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char buffer[16];

main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "error: provide a filename\n", sizeof("error: provide a filename\n"));
        exit(1);
    }

    int status;

    if (fork() == 0) {
        int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (fd == -1) {
            write(2, "error: can't open file\n", sizeof("error: can't open file\n"));
            exit(1);
        }

        write(fd, "Hello\n", 6);
    }
    else {
        wait(&status);
        if (status != 0) {
            exit(1);
        }

        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) {
            write(2, "error: can't open file\n", sizeof("error: can't open file\n"));
            exit(1);
        }

        for (int i = 0; i < 6; i += 2) {
            read(fd, buffer, 2);
            write(1, buffer, 2);
            write(1, " ", 1);
        }
    }
}
