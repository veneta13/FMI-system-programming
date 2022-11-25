#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("error: pass 2 arguments\n");
        exit(1);
    }

    int fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
    close(1);
    dup(fd);

    for (int i = 0; i < 10; i++) {
        write(1, "EXAMPLE\n", 8);
    }
}
