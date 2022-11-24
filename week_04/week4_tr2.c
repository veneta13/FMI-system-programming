#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main() {
    int fd, j, nb1;
    char buf[5];

    j = dup(1);
    fd = open("fileA", O_RDWR);
    nb1 = read(0, buf, 4);
    write(j, buf, nb1);
    nb1 = read(fd, buf, 5);
    write(1, buf, nb1);
    write(fd, buf, nb1);
    write(j, buf, 3);
    close(fd);
    close(j);
    write(1, "\n", 1);
    execlp("cat", "cat", "fileA", 0);
}
