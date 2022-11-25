#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd, fd1, broi;
    char buff[15] = "";

    fd1 = open("x1", O_CREAT | O_TRUNC | O_RDWR, 0666);

    write(fd1, "I am a student Computer science!!!", 34);
    lseek(fd1, 0, 0);

    while ((broi = read(fd1, buff, 10)) != 0) {
        write(1, buff, broi);
        write(1, "ECHO", 4);
        printf("\n%d\n", broi);
    }

    printf("\n%d\n", broi);
}

/*
 *
 * Output:
 *
 * I am a stuECHO
 * 10
 * dent CompuECHO
 * 10
 * ter sciencECHO
 * 10
 * e!!!ECHO
 * 4
 *
 * 0
 *
 */