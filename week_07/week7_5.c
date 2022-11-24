#include <stdio.h>
#include <fcntl.h>

#define ERROR -1

main() {
    int i, fd1, fd2, status;
    if ((fd1 = open("ff", O_WRONLY | O_CREAT, 0777)) == -1) {
        printf("ERROR\n");
        exit(1);
    }

    printf("%d\n", fd1);

    if (fork() == 0) {
        close(1);
        dup(fd1);
        write(1, "HELLO1\n", 7);
        write(1, "HELLO2\n", 7);
    }
    else {
        //wait(&status);
        write(1, "HELLO3\n", 7);
        write(fd1, "HELLO4\n", 7);
    }

    write(1, "HELLO5\n", 7);
    write(fd1, "HELLO6\n", 7);
}
