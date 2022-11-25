#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char buffer[16];

int main() {
    int fd = open("aa", O_RDONLY);
    if (fd == -1) {
        printf("error: can't open file\n");
        exit(1);
    }

    int readBytes;

    while ((readBytes = read(fd, buffer, 10)) > 0) {
        printf("%d\n", readBytes);
    }
    printf("%d\n", readBytes);
}

/*
 *
 * Output:
 *
 * 10
 * 10
 * 6
 * 0
 *
 */