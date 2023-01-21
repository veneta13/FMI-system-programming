#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

main() {
    int fdi, fdio, nb1, nb2;
    char buff[15];
    fdi = open("abc", O_RDONLY);
    fdio = open("abc", O_RDWR);

    nb1 = read(fdi, buf, 6);
    write(1, buf, nb1);

    lseek(fdi, 3, SEEK_CUR);
    nb1 = read(fdi, buf, 6);
    write(1, buf, nb1);

    lseek(fdio, -18, SEEK_END);
    write(fdio, "tra", 3);

    write(fdio, "vel", 3);
    nb2 = read(fdio, buf, 5);
    write(1, buf, nb2);
    write(1, "time", 4);

    lseek(fdi, -2, SEEK_END);
    nb2 = read(fdi, buf, 2);
    write(1, buf, nb2);
}

/*
 *
 * Let's go change the world!
 *
 * Output:
 * Let's change the time!
 *
 *
 * abc:
 * Let's go travel the world!
 *
 */
