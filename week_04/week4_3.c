#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

main() {
    int fd = open("f1", O_CREAT | O_TRUNC | O_WRONLY, 0777);
    close(1);
    dup(fd);

    for (int i = 0; i < 10; i++) {
        write(1, "EXAMPLE\n", 8);
    }
}
