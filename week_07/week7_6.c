#include <stdio.h>
#include <fcntl.h>

#define ERROR -1

main(int argc, char *argv[]) {
    int i, fd1, fd2, status;
    if ((fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1) {
        printf("ERROR\n");
        exit(1);
    }

    printf("%d\n", fd1);

    if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1) {
        printf("ERROR\n");
        exit(1);
    }

    printf("%d\n", fd2);

    if (fork() == 0) {
        i = dup(1);
        close(1);
        dup(fd2);
        write(1, "HELLO1", 6);
        close(1);
        dup(i);
        //write(1, "HELLO2", 6);
    }
    else {
        wait(&status);
        write(fd1, "HELLO2", 6);
    }

    write(1, "HELLO3", 6);
    write(fd2, "HELLO4", 6);
}
