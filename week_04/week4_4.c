#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


main() {
    int fd, i, j, k;
    char str[20];

    if ((fd = open("abc", O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) {
        write(2, "Cannot create file abc \n", 24);
        exit(1);
    }

    for (i = 0; i <= 5; ++i)
        write(1, "HELLO\n", 6);

    j = dup(1);
    close(1);
    k = dup(fd);

    for (i = 0; i <= 5; ++i) {
        sprintf(str, "i = %d\n", i);
        write(1, str, strlen(str));
    }

    close(1);
    dup(j);

    for (i = 0; i <= 5; ++i)
        write(1, "HELLO you!!!\n", 16);
