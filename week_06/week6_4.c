#include <stdio.h>
#include <fcntl.h>

#define ERROR -1

main() {
    int i, fd1, fd2;

    if ((fd1 = open("ff", O_WRONLY | O_CREAT, 0777)) == -1) {
        printf("ERROR\n");
        exit(1);
    }

    printf("%d\n", fd1);

    if ((fd2 = open("ff", O_WRONLY)) == -1) {
        printf("GRESHKA\n");
        exit(1);
    }

    printf("%d\n", fd2);

    if (fork() == 0) {
        write(fd1, "HELLO", 5);
    }
    else {
        write(fd2, "HELLO", 5);
    }
}
