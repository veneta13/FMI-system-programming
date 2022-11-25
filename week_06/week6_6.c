#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "error: provide a filename\n", sizeof("error: provide a filename\n"));
        exit(1);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);

    fork();
    write(fd, "Hello\n", 6);
}