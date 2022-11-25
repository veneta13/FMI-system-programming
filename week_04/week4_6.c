#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char buffer[16];

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("error: pass 2 arguments\n");
        exit(1);
    }

    int fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
    if (fd == -1) {
        printf("error: can't open file\n");
        exit(1);
    }

    for (int i = 1; i < 10; i++) {
        write(1, "EXAMPLE\n", 8);
    }

    int stdOUT = dup(1);
    close(1);

    dup(fd);

    for (int i = 1; i < 10; i++) {
        sprintf(buffer, "%d\n", i);
        write(1, buffer, 2);
    }

    close(1);
    dup(stdOUT);

    for (int i = 1; i < 10; i++) {
        write(1, "HELLO\n", 6);
    }
}
