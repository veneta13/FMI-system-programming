#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(2, "error: provide 2 filenames\n", sizeof("error: provide 2 filenames\n"));
        exit(1);
    }

    int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if (fork() == 0) {
        write(fd1, "hello2", 6);

        close(1);
        dup(fd2);
    }
    else {
        write(fd1, "hello1", 6);
    }

    write(1, "hello3\n", 7);
    write(fd2, "hello4", 6);
}
