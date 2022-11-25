#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char buffer[16];

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("error: provide file");
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        printf("error: file not found");
        exit(1);
    }

    for (int i = 5; i > 0; i--) {
        lseek(fd, 0, SEEK_CUR);
        read(fd, buffer, i);
        write(1, buffer, i);
    }
}