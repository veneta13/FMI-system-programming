#include <stdio.h>
#include <fcntl.h>

char buffer[16];

int main() {
    int fd = open("aa", O_RDONLY);
    int i;

    for (i = 5; i > 0; i--) {
        if (read(fd, buffer, i) == 0) {
            printf("error: reached end of file\n");
        }

        printf("%s\n", buffer);
    }
}

/*
 *
 * Output:
 *
 * abcde
 * fghie
 * jklie
 * mnlie
 * onlie
 *
*/
