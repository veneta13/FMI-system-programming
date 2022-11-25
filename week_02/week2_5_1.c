#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char buffer[16];

int main() {
    int fd = open("aa", O_RDONLY);
    int i;

    for (i = 5; i > 0; i--) {
        lseek(fd, 0, 0);
        read(fd, buffer, i);
        printf("%s\n", buffer);
    }
}

/*
 *
 * Output:
 *
 * abcde
 * abcde
 * abcde
 * abcde
 * abcde
 *
*/
