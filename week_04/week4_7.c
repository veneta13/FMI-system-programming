#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char buffer[16];

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("error: pass 3 arguments\n");
        exit(1);
    }

    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_CREAT| O_TRUNC| O_WRONLY, 0777);

    close(0);
    dup(fd1);

    close(1);
    dup(fd2);

    int readBytes;
    while ((readBytes = read(0, buffer, 16))) {
        write(1, buffer, readBytes);
    }
}
