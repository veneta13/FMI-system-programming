#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char buffer[16];

int main() {
    int fd = open("aa", O_RDONLY);
    int i;

    if (fd == -1) {
        printf("error: can't open file\n");
    }
    else {
        for (i = 5; i > 0; i--) {
            int readBytes;
            readBytes = read(fd, buffer, i);
            write(1, buffer, readBytes);
        }
    }
}

/*
 *
 * Output:
 *
 * abcdefghijklmno
 *
 */